#include <stdio.h>

void foo(int (*p)[3])
{
	// *p -> int[3]
	(*p)[0] = 10;
	(*p)[1] = 20;
	(*p)[2] = 30;
}

void goo(int* p)
{
	// p[0] -> *(p+0) -> *p = 10
	p[0] = 10;
	// p[1] -> *(p+1) 
	p[1] = 20;
	p[2] = 30;

}

void hoo(int* p)
{
	// *p -> int	
}


int main()
{
	int n;
	hoo(&n);

	int arr[3];

	goo(arr);   // arr의 타입은 int* 으로 평가된다.
	foo(&arr);  // (int[3])* -> int (*p)[3] 
}
