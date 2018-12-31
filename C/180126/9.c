#include <stdio.h>
// 배열과 포인터

// 1. 배열은 배열의 첫번째 원소의 시작 주소가 전달된다.
//    arr -> int arr[] -> &arr[0] -> int*

// 2. 다른 함수에서 전달된 배열의 크기를 알 수 없다.
void foo(int* arr)
{
	printf("%ld\n", sizeof(arr));  // ?
	for (int i = 0; i < 10; ++i)
		arr[i] = i + 1;
}

int main()
{
	int arr[10];
	// foo(arr);
	foo(&arr[0]);

	for (int i = 0; i < 10; ++i)
		printf("%3d ", arr[i]);
}
