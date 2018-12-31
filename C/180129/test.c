#include <stdio.h>


int x;

int main()
{
	char* s1 = "hello";
	char s4[] = "hello";
	int a;

	printf("%p\n", &x);
	printf("%p\n", &a);
	printf("%p\n", s1);
	printf("%p\n", s4);

	s4[0] = 'x';
	printf("%s\n", s4);
}


