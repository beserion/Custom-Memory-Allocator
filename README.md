Custom Memory Allocator

A lightweight and educational clone of malloc, free, realloc, and calloc.
This project demonstrates how dynamic memory management works under the hood by implementing a simple heap manager in C.

🚀 Features

Custom implementation of:

malloc

free

realloc

calloc

Metadata-based block management

Heap expansion using sbrk() or mmap()

Block splitting and merging (coalescing)

Simple fragmentation handling

Fully written in C

Clean, modular code structure

📂 Project Structure
custom-allocator/
│
├── src/
│   ├── malloc.c
│   ├── free.c
│   ├── realloc.c
│   ├── calloc.c
│   ├── block.c        # metadata, split/merge, utilities
│   └── allocator.h
│
├── tests/
│   └── test_basic.c
│
├── README.md
└── Makefile

🧠 Architecture Overview

Every allocated block is described using a simple metadata header:

typedef struct s_block {
    size_t size;
    int    free;
    struct s_block *next;
} t_block;


Memory flow:

User requests malloc(x)

Allocator searches for a free block of suitable size

If none exists, the heap is expanded

Metadata + user space are allocated

free() marks blocks as available

Adjacent free blocks merge (coalescing)

🔧 Build & Run
Compile
make

Example Usage
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

 Thread-safe version (mutex)

 mmap-based page manager

 Performance benchmarking tools

 Valgrind integration

📝 License

Distributed under the MIT License.
