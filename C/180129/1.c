// 문자열 
#include <stdio.h>

void foo(char *s) // char[]
{

}

void goo(char *s) // char
{

}

int main()
{
	char c;
	goo(&c);


	char arr1[] = "hello";
	char arr2[] = "chansik";
	char arr3[] = "babo";

	char* str[3];
	str[0] = arr1;





	for (int i = 0 ; i < 3 ; ++i)
		printf("%s\n", str[i]);
}
