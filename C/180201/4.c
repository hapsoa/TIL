
#include <stdio.h>

#if 0
------
  a     -> 4

------
  b     -> 1
------
padding -> 3
------

#endif

// 1. 구조체의 멤버 중 가장 큰 크기를 가지는 필드의 크기로 정렬하는
//    형태로 구현되어 있다.
// 2. 필드의 메모리 위치는 4의 배수 / 8의 배수로 위치한다.
struct A
{
	char a;     
	double b;  
	int c;    
} __attribute__((packed));

struct B
{
	double a; 
	char b;  
	int c;  
} __attribute__((packed));

int main()
{
	printf("%ld\n", sizeof(struct A));
	printf("%ld\n", sizeof(struct B));
}
