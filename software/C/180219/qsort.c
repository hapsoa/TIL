#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

// 퀵 정렬은 피봇의 값이 전체값의
// 최대값이나 최소값이 선택이 될 경우
// 알고리즘의 효율이 N^2으로 떨어진다.
//   i
// j
//   1 9 5 4 3 2 10

// 1. pivot이 quick_sort의 성능을 결정한다.
// 2. 퀵 소트는 데이터의 개수가 많을 때 빠르게 동작하지만,
//    데이터가 적을 경우 큰 효과가 없다.
//   => 데이터의 개수가 적어질 경우, 삽입 정렬로 최적화한다.
// 3. 비재귀로 작성한다.


void insertion_sort(int *data, int n)
{
	int i, j, remember;
	for ( i = 1; i < n; i++ )
	{
		remember = data[i];
		j = i;
		// remember = data[(j=i)];
		while ( --j >= 0 && remember < data[j] ) 
			data[j+1] = data[j];

		data[j+1] = remember;
	}
}

void quick_sort(int *a, int n)
{
	int pivot;
	int i;
	int j;

	// 재귀 호출의 종료 조건
	if (n <= 7) 
	{
		insertion_sort(a, n);
		return;
	}

#if 1
	// 1. 임의 분할법
	//  : 피봇의 값을 랜덤으로 선정한다.
	// 2. 세 값의 중위 - median of three
	// a[0] / a[n-1] / a[n / 2]
	int m = n / 2;
	int r = 0;
	if ((a[0] - a[n-1]) * (a[0] - a[m]) < 0)
		r = 0;
	if ((a[n-1] - a[0]) * (a[n-1] - a[m]) < 0)
		r = n-1;
	if ((a[m] - a[0]) * (a[m] - a[n-1]) < 0)
		r = m;
	swap(&a[r], &a[n-1]);
#endif

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)
			;
		while (a[--j] > pivot)
			;

		if (i >= j)
			break;

		swap(&a[i], &a[j]);

	}

	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}


void init_arr(int* arr, int n)
{
	srand(time(0));
	for (int i = 0 ; i < n ; ++i)
		arr[i] = n - i;
}

int a_10000[10000]; 
int a_100000[100000]; 
int a_1000000[1000000]; 


int cmp1(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	init_arr(a_100000, 100000);
	init_arr(a_1000000, 1000000);

	clock_t start, end;

	start = clock();
	quick_sort(a_100000, 100000);
	// qsort(a_10000, 10000, sizeof(int), cmp1);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);

	start = clock();
	quick_sort(a_1000000, 1000000);
	// qsort(a_1000000, 1000000, sizeof(int), cmp1);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);
}











