// 문자열 5개 입력 받아서, 소문자를 대문자로 바꾸는 프로그램을 작성하시오
#include <stdio.h>
#include <ctype.h>

// Undo: u
// Redo: Ctrl + R

// gg / G
// ^  / $
void to_upper_str(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

// [ char[32] ][ char[32] ][ char[32] ]

int main()
{
	char str[5][32] = { 0, };

	int n = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < n; ++i)
		scanf("%s", str[i]);

	for (int i = 0; i < n; ++i)
		to_upper_str(str[i]);
	// to_upper_str(str[i], 32);   : 2
	// 문자열은 null 문자로 종료를 알 수 있기 
	// 때문에, 길이를 별도로 전달할 필요가 없다. 

	// manpage
	// 1: shell command
	// 2: system call    - System Programming
	// 3: library
	for (int i = 0; i < n; ++i)
		printf("%s", str[i]);
}
