
#include <stdio.h>
#include <ctype.h>

char xtoupper(char c)
{
	// 소문자 -> 대문자.
	// if ('a' <= c && c <= 'z')
	if (islower(c))
		return c - ('a' - 'A');
	
	return c;
}

int main()
{
	// hello@gmail.com
	// Hello
	const char* s1 = "hEllo";
	const char* s2 = "HeLlo";
	if (s1 == s2)
	{

	}

	char ch;
	// ascii code
	//  A: 65
	//  a: 97
	//  0: 48

	// a-z
	ch = getchar();

	// ch = ch + ('a' - 'A');
	ch = toupper(ch);
	


	printf("%c\n", ch);
}
