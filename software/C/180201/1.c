
// 비트를 출력하는 print_bits 함수를 만드세요.
 
#include <stdio.h>

// Macro Function
//  => 이름이 반드시 대문자로 되어야 한다. 
#define NBITS(n) (sizeof(n) * 8)

#define ADD(a, b) a + b

#if 0
int add(int a, int b)
{
	return a + b;
}

double dadd(double a, double b)
{
	return a + b;
}	
#endif

// 함수 vs 매크로 함수
//  : 모듈화

// 함수의 단점
//  => 코드를 그냥 실행하는 것이 아니라, 점프를 수행해야 하므로
//     오버헤드가 있다.

//  => 함수의 호출이 오버헤드로 작용할 경우, 최적화 방법
//     매크로 함수. 
//    : 매크로 함수는 호출하는 것이 아니라 텍스트를 치환하는 것이므로
//      호출에 따른 오버헤드가 존재하지 않는다. 

//   => 함수의 타입이 다르고 알고리즘이 동일한 경우, 
//      적은 코드로 처리할 수 있다. 
//     => 매크로 함수 장점.

// 매크로 함수 단점
//  => 문제를 찾기 어렵다.


// unsigned short: 0  ~ 65535
// signed   short: -32768 ~ 32767
void print_bits(short n)
{
	unsigned short s = 1 << (NBITS(n) - 1);
	while (s)
	{
		putchar(n & s ? '1' : '0');
		s >>= 1;
	}

	putchar('\n');
}

int main()
{
	short n = 42;
	// 32 + 8 + 2 => 2^5 + 2^3 + 2^1
	//            => 0000 0000 0010 1010
	print_bits(n);

	n = -42;
	//            => 1111 1111 1101 0110
	print_bits(n);
}
