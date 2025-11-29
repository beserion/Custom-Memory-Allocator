Custom Memory Allocator

A lightweight and educational clone of malloc, free, realloc, and calloc.
This project demonstrates how dynamic memory management works internally by implementing a simple heap manager in C.

🚀 Features

Custom implementation of:

malloc

free

realloc

calloc

Metadata-based block management

Heap expansion via sbrk() or mmap()

Block splitting & coalescing

Basic fragmentation handling

Fully written in C

Clean, modular structure

📂 Project Structure
custom-allocator/
│
├── src/
│   ├── malloc.c
│   ├── free.c
│   ├── realloc.c
│   ├── calloc.c
│   ├── block.c
│   └── allocator.h
│
├── tests/
│   └── test_basic.c
│
├── README.md
└── Makefile

🧠 Architecture Overview

Each allocated memory block starts with a metadata header:

typedef struct s_block {
    size_t size;
    int    free;
    struct s_block *next;
} t_block;


Allocation flow:

malloc(size) searches for a suitable free block

If none exists, heap is expanded

Metadata + usable memory are returned

free() marks the block as free

Neighboring free blocks merge (coalescing)

🔧 Build & Usage
Compile
make

Example Program
#include "allocator.h"

int main(void)
{
    char *p = malloc(20);
    p = realloc(p, 100);
    free(p);
    return 0;
}

Run Tests
make test

📈 Roadmap

 Thread-safe allocator (mutex)

 mmap-based page allocator

 Benchmark utilities

 Valgrind integration

📝 License

MIT License.
