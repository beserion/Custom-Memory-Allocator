# Custom Memory Allocator

A lightweight and educational clone of `malloc`, `free`, `realloc`, and `calloc`.
This project demonstrates how dynamic memory management works internally by implementing a simple heap manager in C.

---

## 🚀 Features

* Custom implementation of:

  * `malloc`
  * `free`
  * `realloc`
  * `calloc`
* Metadata-based block management
* Heap expansion via `sbrk()` or `mmap()`
* Block splitting & coalescing
* Basic fragmentation handling
* Fully written in C
* Clean, modular structure

---

## 📂 Project Structure

```
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
```

---

## 🧠 Architecture Overview

Each allocated memory block starts with a metadata header:

```c
typedef struct s_block {
    size_t size;
    int    free;
    struct s_block *next;
} t_block;
```

**Allocation flow:**

1. `malloc(size)` searches for a suitable free block
2. If none exists, heap is expanded
3. Metadata + usable memory are returned
4. `free()` marks the block as free
5. Neighboring free blocks merge (coalescing)

---

## 🔧 Build & Usage

### Compile

```bash
make
```

### Example Program

```c
#include "allocator.h"

int main(void)
{
    char *p = malloc(20);
    p = realloc(p, 100);
    free(p);
    return 0;
}
```

### Run Tests

```bash
make test
```

---

## 📈 Roadmap

* [ ] Thread-safe allocator (mutex)
* [ ] mmap-based page allocator
* [ ] Benchmark utilities
* [ ] Valgrind integration

---

## 📝 License

MIT License.


da ekleyebilirim.

- minor update @ 2026-01-10 18:13:45.590063
- minor update @ 2026-01-10 18:13:45.867383
- minor update @ 2026-01-10 18:13:46.594313
- minor update @ 2026-01-10 18:13:47.070133
- minor update @ 2026-01-10 18:13:47.551581
- minor update @ 2026-01-10 18:13:48.262303
- minor update @ 2026-01-10 18:13:48.498838
- minor update @ 2026-01-10 18:13:48.979120
- minor update @ 2026-01-10 18:13:49.212275
- minor update @ 2026-01-10 18:13:49.453557
- minor update @ 2026-01-10 18:13:50.152607
- minor update @ 2026-01-10 18:13:51.109827
- minor update @ 2026-01-10 18:13:51.349282
- minor update @ 2026-01-10 18:13:51.820373
- minor update @ 2026-01-10 18:13:52.308927
- minor update @ 2026-01-10 19:52:37.479351
- minor update @ 2026-01-10 19:52:37.942276
- minor update @ 2026-01-10 19:52:38.601030
- minor update @ 2026-01-10 19:52:39.032780
- minor update @ 2026-01-10 19:52:39.681488
- minor update @ 2026-01-10 19:52:40.326260
- minor update @ 2026-01-10 19:52:40.552666
- minor update @ 2026-01-10 19:52:40.771348