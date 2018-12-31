
#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 정렬 알고리즘
//  1. 선택 정렬   n^2
//  2. 삽입 정렬   n^2
//  3. 버블 정렬   n^2
//  4. 퀵 정렬     nlogn  - *
//  5. 머지 정렬   nlogn
//  6. 힙 정렬     nlogn  - *

// 1 2 3 4 5 6 7 8 9 10  - 오름 차순
// 10 9 8 7 6 5 4 3 2 1  - 내림 차순

// 공통성과 가변성의 분리
//  => 변하는 것과 변하지 않은 것은 분리되어야 한다.
//   변하지 않는 전체 알고리즘에서 변해야 하는 정책은 분리되어야 한다.
//   함수에서 분리하는 방법 => 인자로 분리한다.
void sort(int* x, int n, int (*cmp)(int, int))
{
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if ((*cmp)(x[j], x[j+1]) > 0) 
			// if (x[j] < x[j+1])
				swap(&x[j], &x[j+1]);
		}
	}
}

// cmp라는 함수를 만드는 규칙
// 1. 왼쪽이 클때    >0
// 2. 오른쪽이 클때  <0
// 3. 같을 때        =0

int cmp1(int a, int b)
{
	return a - b;
}

int cmp2(int a, int b)
{
	return b - a;
}

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	sort(x, 10, cmp2);

	for (int i = 0 ; i < 10; ++i)
		printf("%3d", x[i]);
	putchar('\n');
}
