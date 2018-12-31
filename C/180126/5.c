#include <stdio.h>
// 포인터 변수
//  : 포인터는 왜 사용하는가?
//  => 포인터의 주요한 목적: 다른 함수에서 변수의 값을 변경하기 위해서
//  => Call by Reference
//             Pointer

// C 언어에서는 다른 함수에서 다른 함수의 변수값을 변경하는 것이
// 불가능하다.

#if 0
// 아래의 함수는 a와 b의 값이 변경되지 않는다.
// => 함수의 컨텍스트가 다르기 떄문이다.
void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	printf("%d %d\n", a, b);
}
#endif


int main()
{
	int a = 10;
	int b = 20;

	printf("%d %d\n", a, b);
	swap(a, b);
}




