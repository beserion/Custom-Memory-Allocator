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
- minor update @ 2026-01-12 11:22:59.417674
- minor update @ 2026-01-12 11:23:03.664428
- minor update @ 2026-01-12 12:51:07.373897
- minor update @ 2026-01-12 12:51:16.589196
- minor update @ 2026-01-12 12:51:33.018820
- minor update @ 2026-01-12 12:51:36.226274
- minor update @ 2026-01-12 12:51:54.694962
- minor update @ 2026-01-12 14:27:21.398115
- minor update @ 2026-01-12 14:27:27.698871
- minor update @ 2026-01-12 14:27:33.952683
- minor update @ 2026-01-12 14:27:40.201035
- minor update @ 2026-01-12 14:27:50.686177
- minor update @ 2026-01-12 21:35:36.136904
- minor update @ 2026-01-12 21:35:42.674313
- minor update @ 2026-01-13 18:33:31.100264
- minor update @ 2026-01-13 18:33:47.993809
- minor update @ 2026-01-13 18:34:01.159154
- minor update @ 2026-01-13 18:34:07.454524
- minor update @ 2026-01-13 18:34:28.049364
- minor update @ 2026-01-14 18:36:01.476021
- minor update @ 2026-01-14 18:36:10.080100
- minor update @ 2026-01-14 18:36:28.300533
- minor update @ 2026-01-15 10:27:21.134991
- minor update @ 2026-01-15 10:27:31.678439
- minor update @ 2026-01-15 10:27:38.234699
- minor update @ 2026-01-15 10:27:45.875103
- minor update @ 2026-01-15 10:27:53.169337
- minor update @ 2026-01-15 10:27:59.474531
- minor update @ 2026-01-15 10:28:20.075012
- minor update @ 2026-01-15 10:28:23.378140
- minor update @ 2026-01-15 23:22:16.532251
- minor update @ 2026-01-15 23:22:18.806756
- minor update @ 2026-01-15 23:22:42.115997
- minor update @ 2026-01-16 07:25:35.885284
- minor update @ 2026-01-16 07:25:41.614334
- minor update @ 2026-01-16 07:25:57.607510
- minor update @ 2026-01-16 07:26:18.416211
- minor update @ 2026-01-16 08:32:10.024505
- minor update @ 2026-01-16 08:32:15.698243
- minor update @ 2026-01-16 08:32:24.060017
- minor update @ 2026-01-16 08:32:34.309059
- minor update @ 2026-01-16 08:32:51.860252
- minor update @ 2026-01-16 08:32:58.144084
- minor update @ 2026-01-16 08:33:16.760275
- minor update @ 2026-01-16 23:21:11.628055
- minor update @ 2026-01-16 23:21:19.183532
- minor update @ 2026-01-16 23:21:23.444596
- minor update @ 2026-01-16 23:21:58.483946
- minor update @ 2026-01-16 23:22:05.741956
- minor update @ 2026-01-17 08:27:59.631652
- minor update @ 2026-01-17 08:28:07.305063
- minor update @ 2026-01-17 08:28:19.467675
- minor update @ 2026-01-17 12:41:50.118995
- minor update @ 2026-01-17 12:41:54.702583
- minor update @ 2026-01-17 12:42:03.322190
- minor update @ 2026-01-17 12:42:11.643927
- minor update @ 2026-01-17 15:20:45.587556
- minor update @ 2026-01-17 15:20:52.903843
- minor update @ 2026-01-17 15:21:04.441639
- minor update @ 2026-01-17 17:18:29.647600
- minor update @ 2026-01-18 13:29:21.932370
- minor update @ 2026-01-18 13:29:38.329517
- minor update @ 2026-01-18 14:19:50.600916
- minor update @ 2026-01-18 14:19:55.302438
- minor update @ 2026-01-18 14:20:11.312964
- minor update @ 2026-01-19 12:53:07.825793
- minor update @ 2026-01-19 12:53:15.473540
- minor update @ 2026-01-19 12:53:48.835770