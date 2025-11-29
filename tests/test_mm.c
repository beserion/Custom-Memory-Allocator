/* tests/test_mm.c */
#include "../include/mini_malloc.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *a = mm_malloc(16);
	if (!a) { printf("alloc a failed\n"); return 1; }
	strcpy(a, "hello-allocator");
	printf("a: %s\n", a);

	char *b = mm_malloc(100000); /* large -> mmap */
	if (!b) { printf("alloc b failed\n"); return 1; }
	memset(b, 'X', 100000);
	printf("b[0]=%c b[99999]=%c\n", b[0], b[99999]);

	mm_free(a);

	char *c = mm_malloc(20);
	strcpy(c, "after-free");
	printf("c: %s\n", c);

	char *d = mm_realloc(c, 200000); /* realloc to large (mmap) */
	if (!d) { printf("realloc failed\n"); return 1; }
	printf("d[0]=%c\n", d[0]);

	char *z = mm_calloc(10, 10);
	if (!z) { printf("calloc failed\n"); return 1; }
	printf("z[0]=%d\n", (int)z[0]);

	mm_free(b);
	mm_free(d);
	mm_free(z);

	printf("done\n");
	return 0;
}
