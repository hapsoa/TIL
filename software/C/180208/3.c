#include <stdio.h>

// 함수 포인터
//  : 함수도 주소가 있습니다.
// 실행시간에 어떤 함수를 호출할지 제어할 수 있다.

// C 언어 - 함수 포인터
// C#     - 델리게이트
// Java   - 인터페이스
// C++    - 함수 객체
// Swift  - Closure


void foo()
{
	printf("foo\n");
}

void goo()
{
	printf("goo\n");
}



int main()
{
	foo(); // 직접 호출

	// 함수 포인터 변수
	void (*p1)() = &goo;
	void (*p2)() = foo;
	// 함수의 이름은 함수의 주소로 해석된다. - decay

	(*p1)();
	p2();

	printf("%ld\n", sizeof p1);
}





