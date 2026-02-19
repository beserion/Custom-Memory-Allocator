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
- minor update @ 2026-01-20 07:28:50.352435
- minor update @ 2026-01-20 07:29:07.989109
- minor update @ 2026-01-20 07:29:14.298486
- minor update @ 2026-01-20 07:29:22.611364
- minor update @ 2026-01-21 07:29:32.967233
- minor update @ 2026-01-21 07:29:40.265375
- minor update @ 2026-01-21 07:29:52.814066
- minor update @ 2026-01-21 07:29:56.103022
- minor update @ 2026-01-21 07:30:41.790237
- minor update @ 2026-01-21 14:32:35.668395
- minor update @ 2026-01-21 14:32:43.679398
- minor update @ 2026-01-21 14:32:58.681430
- minor update @ 2026-01-21 14:33:11.230388
- minor update @ 2026-01-21 20:33:21.701447
- minor update @ 2026-01-21 20:33:26.973177
- minor update @ 2026-01-21 20:33:31.254993
- minor update @ 2026-01-22 20:29:45.235194
- minor update @ 2026-01-22 20:29:52.512929
- minor update @ 2026-01-22 20:29:56.786954
- minor update @ 2026-01-22 20:30:03.052690
- minor update @ 2026-01-22 20:30:07.608875
- minor update @ 2026-01-23 03:43:52.992832
- minor update @ 2026-01-23 10:26:57.537404
- minor update @ 2026-01-23 10:27:20.614040
- minor update @ 2026-01-23 10:27:24.080769
- minor update @ 2026-01-23 10:27:38.625321
- minor update @ 2026-01-23 16:32:27.283924
- minor update @ 2026-01-23 16:32:36.594740
- minor update @ 2026-01-23 16:33:01.569177
- minor update @ 2026-01-23 16:33:15.192721
- minor update @ 2026-01-23 16:33:24.782141
- minor update @ 2026-01-23 23:23:03.816110
- minor update @ 2026-01-23 23:23:16.224337
- minor update @ 2026-01-23 23:23:42.409538
- minor update @ 2026-01-23 23:23:50.709078
- minor update @ 2026-01-25 04:13:43.746284
- minor update @ 2026-01-25 04:13:51.162742
- minor update @ 2026-01-25 04:14:11.323544
- minor update @ 2026-01-25 04:14:24.903757
- minor update @ 2026-01-25 04:14:31.746847
- minor update @ 2026-01-25 05:29:04.268158
- minor update @ 2026-01-25 05:29:09.820331
- minor update @ 2026-01-25 05:29:19.096633
- minor update @ 2026-01-25 05:29:27.377683
- minor update @ 2026-01-25 05:29:33.655642
- minor update @ 2026-01-25 05:29:41.925946
- minor update @ 2026-01-25 05:30:07.748328
- minor update @ 2026-01-25 09:23:11.714378
- minor update @ 2026-01-25 09:23:34.597941
- minor update @ 2026-01-25 09:23:40.263441
- minor update @ 2026-01-25 09:23:44.904371
- minor update @ 2026-01-25 21:20:35.382907
- minor update @ 2026-01-26 02:00:21.624309
- minor update @ 2026-01-26 02:00:24.257013
- minor update @ 2026-01-26 02:00:30.847222
- minor update @ 2026-01-26 18:38:20.901940
- minor update @ 2026-01-26 18:38:42.660669
- minor update @ 2026-01-27 06:37:51.558234
- minor update @ 2026-01-27 06:38:01.829890
- minor update @ 2026-01-27 06:38:14.379964
- minor update @ 2026-01-27 07:28:40.816373
- minor update @ 2026-01-27 07:29:07.108972
- minor update @ 2026-01-27 07:29:09.416580
- minor update @ 2026-01-27 07:29:12.727434
- minor update @ 2026-01-27 07:29:18.037215
- minor update @ 2026-01-27 07:29:23.346314
- minor update @ 2026-01-27 07:29:42.406678
- minor update @ 2026-01-27 07:29:46.722054
- minor update @ 2026-01-27 08:35:37.106014
- minor update @ 2026-01-27 08:35:46.780644
- minor update @ 2026-01-27 08:35:50.436094
- minor update @ 2026-01-27 08:36:03.632417
- minor update @ 2026-01-27 08:36:12.287182
- minor update @ 2026-01-27 08:36:22.570987
- minor update @ 2026-01-29 20:32:28.759332
- minor update @ 2026-01-30 02:07:22.140939
- minor update @ 2026-01-30 02:07:27.423768
- minor update @ 2026-01-30 07:40:52.587444
- minor update @ 2026-01-30 07:41:12.230706
- minor update @ 2026-01-30 07:41:14.526163
- minor update @ 2026-01-30 08:40:52.893233
- minor update @ 2026-01-30 08:41:02.005799
- minor update @ 2026-01-30 10:36:07.000703
- minor update @ 2026-01-30 12:58:43.437248
- minor update @ 2026-01-30 12:58:49.095874
- minor update @ 2026-02-01 02:32:00.082943
- minor update @ 2026-02-01 16:31:48.376794
- minor update @ 2026-02-01 20:28:48.001039
- minor update @ 2026-02-01 20:28:57.279477
- minor update @ 2026-02-01 22:26:29.784540
- minor update @ 2026-02-01 22:26:38.351952
- minor update @ 2026-02-02 09:52:10.889065
- minor update @ 2026-02-03 05:51:56.098580
- minor update @ 2026-02-03 05:52:05.386902
- minor update @ 2026-02-03 05:52:07.661738
- minor update @ 2026-02-03 08:39:02.475792
- minor update @ 2026-02-03 08:39:07.005621
- minor update @ 2026-02-03 17:53:40.766692
- minor update @ 2026-02-04 02:08:50.109935
- minor update @ 2026-02-04 15:43:56.282198
- minor update @ 2026-02-06 02:10:22.528242
- minor update @ 2026-02-06 21:32:17.079953
- minor update @ 2026-02-06 21:32:22.588419
- minor update @ 2026-02-07 08:33:54.261457
- minor update @ 2026-02-07 08:34:10.307824
- minor update @ 2026-02-07 13:44:15.775926
- minor update @ 2026-02-07 13:44:22.765315
- minor update @ 2026-02-07 13:44:26.376780
- minor update @ 2026-02-07 18:37:06.541684
- minor update @ 2026-02-07 18:37:15.096438
- minor update @ 2026-02-07 18:37:25.358404
- minor update @ 2026-02-07 20:28:58.723273
- minor update @ 2026-02-07 20:29:05.020491
- minor update @ 2026-02-08 10:28:43.458601
- minor update @ 2026-02-08 10:29:03.760705
- minor update @ 2026-02-09 17:08:34.654266
- minor update @ 2026-02-09 17:08:39.133810
- minor update @ 2026-02-09 17:08:42.593410
- minor update @ 2026-02-10 19:59:57.346147
- minor update @ 2026-02-10 22:40:54.374285
- minor update @ 2026-02-10 22:41:07.726711
- minor update @ 2026-02-11 19:11:03.140446
- minor update @ 2026-02-11 19:11:14.912718
- minor update @ 2026-02-12 21:35:13.680693
- minor update @ 2026-02-13 09:45:54.032992
- minor update @ 2026-02-13 09:46:04.414217
- minor update @ 2026-02-13 11:31:43.220367
- minor update @ 2026-02-13 11:31:53.810315
- minor update @ 2026-02-13 11:32:10.033370
- minor update @ 2026-02-13 15:42:51.242367
- minor update @ 2026-02-13 15:43:06.460066
- minor update @ 2026-02-13 18:52:56.273972
- minor update @ 2026-02-13 21:36:57.644754
- minor update @ 2026-02-14 16:31:26.678726
- minor update @ 2026-02-14 16:31:42.549422
- minor update @ 2026-02-14 20:28:16.768860
- minor update @ 2026-02-14 20:28:30.615845
- minor update @ 2026-02-15 04:55:03.834318
- minor update @ 2026-02-15 04:55:12.043612
- minor update @ 2026-02-15 05:57:10.502851
- minor update @ 2026-02-15 05:57:23.865041
- minor update @ 2026-02-15 05:57:27.095424
- minor update @ 2026-02-15 13:47:29.669781
- minor update @ 2026-02-16 02:22:33.657530
- minor update @ 2026-02-16 10:53:00.332319
- minor update @ 2026-02-16 15:41:38.427139
- minor update @ 2026-02-16 15:41:54.615149
- minor update @ 2026-02-16 16:46:03.504798
- minor update @ 2026-02-16 16:46:31.020240
- minor update @ 2026-02-16 21:29:49.077112
- minor update @ 2026-02-16 21:29:53.428914
- minor update @ 2026-02-16 22:30:40.767675
- minor update @ 2026-02-17 13:06:30.191138
- minor update @ 2026-02-17 13:06:41.086140
- minor update @ 2026-02-17 13:07:00.910257
- minor update @ 2026-02-17 19:10:19.493890
- minor update @ 2026-02-17 19:10:25.700047
- minor update @ 2026-02-19 08:47:19.064081