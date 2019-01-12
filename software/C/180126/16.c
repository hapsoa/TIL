#include <stdio.h>

// 포인터와 배열의 연산이 호환되는 이유
// => 배열의 연산은 포인터의 연산으로 변환됩니다. 

// 포인터 + 상수   : 주소값 + 포인터 대상체 타입 크기 * 상수
// 포인터 - 상수   : 주소값 - 포인터 대상체 타입 크기 * 상수
// 포인터 - 포인터 : 주소값 차 / 대상체 타입 크기

int main()
{
	int arr[5];          // 100
	int* p1 = &arr[0];   // 100
	int* p2 = &arr[4];   // 116

	printf("%ld\n", p2 - p1);
}
	

#if 0
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("%d", arr[3]);
	printf("%d", *(arr + 3));
	printf("%d", *(3 + arr));
	printf("%d", 3[arr]);



}
#endif
