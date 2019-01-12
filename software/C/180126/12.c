
#include <stdio.h>

// void foo(int[3]* p)
void foo(int (*p)[3], int n)
{
	printf("%ld\n", sizeof(p));
}

int main()
{
	int arr[2][3];
	foo(arr, 2);
	// &arr[0];
	// &int[3]
	// int[3]*
}
