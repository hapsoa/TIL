#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"


// 삽입 정렬은 이미 정렬되어 있는 데이터에 대해서는
// 알고리즘의 시간 복잡도는 N 이다.
// r=5
//            i  
//          j
//      1 2 3 5 10
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

void init_arr(int* arr, int n)
{
	srand(time(0));
	for (int i = 0 ; i < n ; ++i)
		arr[i] = i;
}

int a_10000[10000]; 
int a_100000[100000]; 
int a_1000000[1000000]; 
int main()
{
	init_arr(a_10000, 10000);
	init_arr(a_100000, 100000);
	init_arr(a_1000000, 1000000);

	clock_t start, end;

	start = clock();
	insertion_sort(a_10000, 10000);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);

	start = clock();
	insertion_sort(a_1000000, 1000000);
	end = clock();
	printf("%lf\n", ((double)end - start) / CLOCKS_PER_SEC);
}











