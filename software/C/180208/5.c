
#include <stdio.h>
#include <stdlib.h>

// qsort
void qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *));

int cmp1(int a, int b)
{
	return a - b;
}

int compare(const void* a, const void* b)
{
	int na = *(int*)a;
	int nb = *(int*)b;

	return nb - na;
}

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	qsort(x, 10, sizeof(x[0]), &compare);

	for (int i = 0 ; i < 10; ++i)
		printf("%3d", x[i]);
	putchar('\n');
}
