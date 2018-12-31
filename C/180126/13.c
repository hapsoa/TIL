
#include <stdio.h>

// arr의 타입은 무엇인가요?
//  int[3]

// arr은 배열의 첫번째 원소의 시작 주소로 해석된다.
//  int*
#if 0
int n = 42;
int* p = &n;
*p <-- n;
#endif

// 예외 1.
//    sizeof 연산에서는 int[3]로 해석된다.
// 예외 2.
//    & 연산자
void foo(int(*p)[3])
{
	int* arr = *p;  // int[3]
}

int main()
{
	int arr[3];
	foo(&arr);
	printf("%ld\n", sizeof(arr));  // ?
}









