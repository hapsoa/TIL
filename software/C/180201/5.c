
// 동적할당
//  : 프로그래머가 원하는 시점에 메모리를 할당/해제할 수 있다.
//   malloc / free

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	p1[0] = 10;
	p1[2] = 20;

	int arr[3][10];

	int (*p)[10] = (int (*)[10])malloc(sizeof(int[10]) * 3);
	p[2][3] = 20;

	free(p1);
	free(p);



}










