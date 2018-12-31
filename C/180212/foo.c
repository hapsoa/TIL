#include <stdio.h>

void foo()
{
	printf("foo\n");
}

typedef void (*foo_t)();
typedef foo_t (*goo_t)[3];

goo_t bar()
{
	foo_t p[3];
	return &p;
}


int main()
{

}
