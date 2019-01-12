#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

// N^2
//  10000    - 0.2초
//  100000   - 20초
//  1000000  - 2000초

// 선택 정렬
void selection_sort(int* data, int n)
{
	int i, j, select;
	for (i = 0; i < n - 1; i++)
	{
		select = i;
		for (j = i+1; j < n; j++)
		{
			if (data[j] < data[select])
			{
				select = j;
			}
		}

		swap(&data[select], &data[i]);
	}
}

void init_arr(int* arr, int n)
{
	srand(time(0));
	for (int i = 0 ; i < n ; ++i)
		arr[i] = i;
}

int a_10000[10000]; 
int a_100000[100000]; 
int main()
{
	init_arr(a_10000, 10000);
	init_arr(a_100000, 100000);

	clock_t start, end;

	start = clock();
	selection_sort(a_10000, 10000);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);

	start = clock();
	selection_sort(a_100000, 100000);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);
}











