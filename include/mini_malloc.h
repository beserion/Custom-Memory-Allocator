/* include/mini_malloc.h
 * Advanced mini memory allocator (mmap + sbrk hybrid, segregated bins, thread-safe)
 */
#ifndef MINI_MALLOC_H
# define MINI_MALLOC_H

# include <stddef.h>

void	*mm_malloc(size_t size);
void	mm_free(void *ptr);
void	*mm_realloc(void *ptr, size_t size);
void	*mm_calloc(size_t nmemb, size_t size);

#endif
