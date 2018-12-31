
#include <stdio.h>

void foo(int* a, int *c)
{

}

int main()
{
	// int a[10];
	// int b[20];
	// int c[10];
	int* a = malloc(sizeof(int) * 10);
	int* c = malloc(sizeof(int) * 10);

	// a = b;      // X, a=> int[10] b=> int[20]
	free(a);
	a = c;      // X, 
	// a => 배열의 첫번째 원소의 시작 주소 => &a[0] => int * const 
	// c =>                                => &c[0]

	// int * const pa;
	// const int *pa;
	// const int * const pa;
	// int const * const pa;

	foo(a, c);
}
