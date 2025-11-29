Custom Memory Allocator

A lightweight and educational clone of malloc, free, realloc, and calloc. This project demonstrates how dynamic memory management works under the hood by implementing a simple heap manager in C.

🚀 Features

Custom implementations of:

malloc

free

realloc

calloc

Metadata-based block management

Heap expansion using sbrk() or mmap()

Block splitting and merging (coalescing)

Basic fragmentation handling

Fully written in C

Clean and modular structure

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

Each allocated region is represented with this metadata header:

typedef struct s_block {
    size_t size;
    int    free;
    struct s_block *next;
} t_block;


Memory flow:

malloc(x) searches for a suitable free block

If none exists, the heap is expanded

Metadata + user memory are allocated

free() marks the block as available

Adjacent free blocks merge (coalescing)

🔧 Build & Run
Compile
make

Example
#include "allocator.h"

int main(void)
{
    char *p = malloc(20);
    p = realloc(p, 100);
    free(p);
}

Run tests
make test

📈 Roadmap

 Thread-safe version

 mmap-based page manager

 Benchmark tools

 Valgrind integration

📝 License

MIT License.
