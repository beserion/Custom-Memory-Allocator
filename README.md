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
- minor update @ 2026-01-10 19:52:41.208618
- minor update @ 2026-01-10 19:52:41.412007
- minor update @ 2026-01-10 19:52:42.061155
- minor update @ 2026-01-10 19:52:42.280872
- minor update @ 2026-01-10 19:52:42.487904
- minor update @ 2026-01-10 19:52:43.580659
- minor update @ 2026-01-10 19:52:43.791597
- minor update @ 2026-01-11 01:59:11.931668
- minor update @ 2026-01-11 01:59:22.145069
- minor update @ 2026-01-11 01:59:42.028599
- minor update @ 2026-01-11 03:55:44.270236
- minor update @ 2026-01-11 03:56:04.784882
- minor update @ 2026-01-11 04:50:27.186663
- minor update @ 2026-01-11 04:50:37.420254
- minor update @ 2026-01-11 04:50:53.870275
- minor update @ 2026-01-11 04:50:58.096519
- minor update @ 2026-01-11 04:51:01.331492
- minor update @ 2026-01-11 05:26:30.293003
- minor update @ 2026-01-11 05:26:40.584868
- minor update @ 2026-01-11 05:26:45.847058
- minor update @ 2026-01-11 05:26:49.099792
- minor update @ 2026-01-11 05:26:59.354989
- minor update @ 2026-01-11 05:27:05.615695
- minor update @ 2026-01-11 05:27:13.873173
- minor update @ 2026-01-11 05:27:30.643976
- minor update @ 2026-01-11 07:21:45.729678
- minor update @ 2026-01-11 07:21:48.014830
- minor update @ 2026-01-11 07:22:04.530335
- minor update @ 2026-01-11 08:28:48.861166
- minor update @ 2026-01-11 08:28:55.378242
- minor update @ 2026-01-11 10:22:33.585997
- minor update @ 2026-01-11 10:22:40.115782
- minor update @ 2026-01-11 10:22:57.402243
- minor update @ 2026-01-11 12:43:07.329362
- minor update @ 2026-01-11 12:43:11.556925
- minor update @ 2026-01-11 14:20:32.575043
- minor update @ 2026-01-11 14:20:38.799956
- minor update @ 2026-01-11 14:20:46.026244
- minor update @ 2026-01-11 14:20:51.245547
- minor update @ 2026-01-11 14:21:07.903731
- minor update @ 2026-01-11 14:21:15.123220
- minor update @ 2026-01-11 15:20:51.749674
- minor update @ 2026-01-11 15:21:10.207418
- minor update @ 2026-01-11 18:31:11.132700
- minor update @ 2026-01-11 18:31:16.351130
- minor update @ 2026-01-11 20:24:41.189245
- minor update @ 2026-01-11 20:24:50.415377
- minor update @ 2026-01-11 20:25:13.109607
- minor update @ 2026-01-11 21:19:39.802139
- minor update @ 2026-01-11 21:19:43.039506
- minor update @ 2026-01-12 03:51:24.564560
- minor update @ 2026-01-12 03:52:09.382424
- minor update @ 2026-01-12 03:52:27.134872
- minor update @ 2026-01-12 04:51:54.781310
- minor update @ 2026-01-12 04:52:04.024316
- minor update @ 2026-01-12 04:52:09.270426
- minor update @ 2026-01-12 04:52:12.496252
- minor update @ 2026-01-12 04:52:17.728963
- minor update @ 2026-01-12 04:52:23.966589
- minor update @ 2026-01-12 04:52:26.197731
- minor update @ 2026-01-12 11:22:13.343917
- minor update @ 2026-01-12 11:22:41.916602
- minor update @ 2026-01-12 11:22:49.169606