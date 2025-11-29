/* src/allocator.c
 * Single-file allocator implementation
 */

#define _GNU_SOURCE
#include "../include/mini_malloc.h"
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

/*
 * Design choices:
 * - For allocations >= MMAP_THRESHOLD use mmap and mark header->mmapped = 1
 * - For smaller allocations use sbrk-managed heap
 * - Segregated free lists by power-of-two size classes
 * - Thread safe using a single global mutex
 * - Block header placed before returned pointer
 */

#define ALIGNMENT 16
#define ALIGN_UP(x, a) ((((x) + (a) - 1) / (a)) * (a))
#define META_MAGIC 0xDEADBEEFCAFEBABEULL
#define MMAP_THRESHOLD (128 * 1024) /* 128 KB */
#define MIN_BLOCK_SIZE 32
#define NBINS 16 /* covers sizes up to 2^(NBINS+4) approx */

typedef struct block
{
	size_t			size;      /* user-size (not including header) */
	int				free;      /* 1 if free, 0 if used */
	int				mmapped;   /* 1 if allocated via mmap */
	struct block	*prev;     /* previous physical block in heap (only sbrk region) */
	struct block	*next;     /* next physical block in heap */
	struct block	*fl_prev;  /* previous in free-list */
	struct block	*fl_next;  /* next in free-list */
	uint64_t		magic;
}				block_t;

static pthread_mutex_t global_mutex = PTHREAD_MUTEX_INITIALIZER;
static block_t *bins[NBINS];
static block_t *heap_head = NULL; /* first block in sbrk-managed heap */
static block_t *heap_tail = NULL; /* last block in sbrk-managed heap */

static inline size_t
user_size_to_block_size(size_t s)
{
	size_t bs = ALIGN_UP(s, ALIGNMENT);
	if (bs < MIN_BLOCK_SIZE)
		bs = MIN_BLOCK_SIZE;
	return (bs);
}

static inline int
size_to_bin_index(size_t s)
{
	/* bin for sizes: 16,32,64,128,... */
	int idx = 0;
	size_t v = ALIGN_UP(s, ALIGNMENT);
	size_t threshold = 16;
	while (idx < NBINS - 1)
	{
		if (v <= threshold)
			return idx;
		threshold <<= 1;
		idx++;
	}
	return NBINS - 1;
}

/* free-list manipulation */
static void
fl_remove(block_t *b)
{
	if (!b)
		return;
	if (b->fl_prev)
		b->fl_prev->fl_next = b->fl_next;
	if (b->fl_next)
		b->fl_next->fl_prev = b->fl_prev;
	int idx = size_to_bin_index(b->size);
	if (bins[idx] == b)
		bins[idx] = b->fl_next;
	b->fl_prev = b->fl_next = NULL;
}

static void
fl_insert(block_t *b)
{
	if (!b)
		return;
	int idx = size_to_bin_index(b->size);
	b->fl_prev = NULL;
	b->fl_next = bins[idx];
	if (bins[idx])
		bins[idx]->fl_prev = b;
	bins[idx] = b;
}

/* split block: keep 'size' bytes for user in b, create new free block for remainder */
static void
split_block(block_t *b, size_t size)
{
	/* b->size is user-size */
	if (!b || b->mmapped)
		return;
	size_t aligned = user_size_to_block_size(size);
	if (b->size < aligned + sizeof(block_t) + MIN_BLOCK_SIZE)
		return;
	/* create new block header after the allocated area */
	uint8_t *ptr = (uint8_t *)(b + 1);
	block_t *newb = (block_t *)(ptr + aligned);
	newb->size = b->size - aligned - sizeof(block_t);
	newb->free = 1;
	newb->mmapped = 0;
	newb->magic = META_MAGIC;
	newb->prev = b;
	newb->next = b->next;
	if (b->next)
		b->next->prev = newb;
	b->next = newb;
	b->size = aligned;
	/* insert newb into free list */
	fl_insert(newb);
	if (heap_tail == b)
		heap_tail = newb;
}

/* coalesce b with next if next is free and not mmapped */
static void
coalesce_forward(block_t *b)
{
	if (!b || b->mmapped)
		return;
	block_t *n = b->next;
	if (n && n->free && !n->mmapped)
	{
		fl_remove(n);
		b->size += sizeof(block_t) + n->size;
		b->next = n->next;
		if (n->next)
			n->next->prev = b;
		if (heap_tail == n)
			heap_tail = b;
	}
}

/* coalesce backward: returns merged block pointer (the earlier block) */
static block_t *
coalesce_backward(block_t *b)
{
	if (!b || b->mmapped)
		return b;
	block_t *p = b->prev;
	if (p && p->free && !p->mmapped)
	{
		fl_remove(p);
		/* merge p and b */
		p->size += sizeof(block_t) + b->size;
		p->next = b->next;
		if (b->next)
			b->next->prev = p;
		if (heap_tail == b)
			heap_tail = p;
		return p;
	}
	return b;
}

/* search suitable free block in bins (first-fit within bin) */
static block_t *
find_fit(size_t size)
{
	int idx = size_to_bin_index(size);
	for (int i = idx; i < NBINS; i++)
	{
		block_t *cur = bins[i];
		while (cur)
		{
			if (cur->size >= size)
				return cur;
			cur = cur->fl_next;
		}
	}
	return NULL;
}

/* extend heap via sbrk: create new block at tail */
static block_t *
extend_heap(size_t size)
{
	void *p = sbrk(0);
	size_t total = sizeof(block_t) + size;
	void *res = sbrk(total);
	if (res == (void *)-1)
		return NULL;
	block_t *blk = (block_t *)p;
	blk->size = size;
	blk->free = 0;
	blk->mmapped = 0;
	blk->magic = META_MAGIC;
	blk->prev = heap_tail;
	blk->next = NULL;
	blk->fl_prev = blk->fl_next = NULL;
	if (heap_tail)
		heap_tail->next = blk;
	heap_tail = blk;
	if (!heap_head)
		heap_head = blk;
	return blk;
}

/* mmap-based allocation for large requests */
static block_t *
mmap_alloc(size_t size)
{
	size_t total = sizeof(block_t) + size;
	/* round up to page size multiple */
	long pagesz = sysconf(_SC_PAGESIZE);
	size_t mapsz = ((total + pagesz - 1) / pagesz) * pagesz;
	void *p = mmap(NULL, mapsz, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == MAP_FAILED)
		return NULL;
	block_t *blk = (block_t *)p;
	blk->size = mapsz - sizeof(block_t);
	blk->free = 0;
	blk->mmapped = 1;
	blk->magic = META_MAGIC;
	blk->prev = blk->next = NULL;
	blk->fl_prev = blk->fl_next = NULL;
	return blk;
}

void *
mm_malloc(size_t size)
{
	if (size == 0)
		return NULL;
	size_t aligned = user_size_to_block_size(size);
	pthread_mutex_lock(&global_mutex);
	block_t *b = NULL;
	if (aligned >= MMAP_THRESHOLD)
	{
		b = mmap_alloc(aligned);
		if (!b)
		{
			pthread_mutex_unlock(&global_mutex);
			return NULL;
		}
		pthread_mutex_unlock(&global_mutex);
		return (void *)(b + 1);
	}
	/* try free lists */
	b = find_fit(aligned);
	if (b)
	{
		fl_remove(b);
		b->free = 0;
		/* maybe split */
		split_block(b, aligned);
		pthread_mutex_unlock(&global_mutex);
		return (void *)(b + 1);
	}
	/* no free block: extend heap */
	b = extend_heap(aligned);
	if (!b)
	{
		pthread_mutex_unlock(&global_mutex);
		return NULL;
	}
	pthread_mutex_unlock(&global_mutex);
	return (void *)(b + 1);
}

/* convert user ptr to block header pointer */
static inline block_t *
ptr_to_block(void *ptr)
{
	if (!ptr)
		return NULL;
	return ((block_t *)ptr) - 1;
}

void
mm_free(void *ptr)
{
	if (!ptr)
		return;
	pthread_mutex_lock(&global_mutex);
	block_t *b = ptr_to_block(ptr);
	if (b->magic != META_MAGIC)
	{
		/* invalid pointer or corrupted header */
		pthread_mutex_unlock(&global_mutex);
		return;
	}
	if (b->mmapped)
	{
		/* unmap whole mapping */
		size_t total = b->size + sizeof(block_t);
		long pagesz = sysconf(_SC_PAGESIZE);
		size_t mapsz = ((total + pagesz - 1) / pagesz) * pagesz;
		munmap((void *)b, mapsz);
		pthread_mutex_unlock(&global_mutex);
		return;
	}
	/* mark free and coalesce */
	b->free = 1;
	/* try forward coalesce */
	coalesce_forward(b);
	/* try backward coalesce */
	b = coalesce_backward(b);
	/* insert into free list */
	fl_insert(b);
	pthread_mutex_unlock(&global_mutex);
}

void *
mm_realloc(void *ptr, size_t size)
{
	if (!ptr)
		return mm_malloc(size);
	if (size == 0)
	{
		mm_free(ptr);
		return NULL;
	}
	pthread_mutex_lock(&global_mutex);
	block_t *b = ptr_to_block(ptr);
	if (b->magic != META_MAGIC)
	{
		pthread_mutex_unlock(&global_mutex);
		return NULL;
	}
	size_t aligned = user_size_to_block_size(size);
	if (b->mmapped)
	{
		/* mmapped block: if fits, keep; else allocate new and copy */
		if (aligned <= b->size)
		{
			pthread_mutex_unlock(&global_mutex);
			return ptr;
		}
		pthread_mutex_unlock(&global_mutex);
		void *newp = mm_malloc(size);
		if (!newp)
			return NULL;
		memcpy(newp, ptr, b->size < size ? b->size : size);
		mm_free(ptr);
		return newp;
	}
	/* if current block is big enough */
	if (b->size >= aligned)
	{
		/* maybe split */
		split_block(b, aligned);
		pthread_mutex_unlock(&global_mutex);
		return ptr;
	}
	/* try to see if next is free and can be merged */
	block_t *n = b->next;
	if (n && n->free && !n->mmapped && (b->size + sizeof(block_t) + n->size) >= aligned)
	{
		/* remove n from free list and merge */
		fl_remove(n);
		b->size += sizeof(block_t) + n->size;
		b->next = n->next;
		if (n->next)
			n->next->prev = b;
		if (heap_tail == n)
			heap_tail = b;
		/* maybe split after growth */
		split_block(b, aligned);
		pthread_mutex_unlock(&global_mutex);
		return ptr;
	}
	pthread_mutex_unlock(&global_mutex);
	/* allocate new, copy, free old */
	void *newp = mm_malloc(size);
	if (!newp)
		return NULL;
	memcpy(newp, ptr, b->size < size ? b->size : size);
	mm_free(ptr);
	return newp;
}

void *
mm_calloc(size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	void *p = mm_malloc(total);
	if (!p)
		return NULL;
	memset(p, 0, total);
	return p;
}

/* optional debug helper: print free lists (not used in production) */
#ifdef MM_DEBUG
#include <stdio.h>
static void print_bins(void)
{
	fprintf(stderr, "Bins:\n");
	for (int i = 0; i < NBINS; i++)
	{
		fprintf(stderr, "bin %d: ", i);
		block_t *cur = bins[i];
		while (cur)
		{
			fprintf(stderr, "[%zu]%s -> ", cur->size, cur->free ? "F" : "U");
			cur = cur->fl_next;
		}
		fprintf(stderr, "NULL\n");
	}
}
#endif
