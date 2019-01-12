
#include <stdio.h>

// C 언어에는 문자열 타입이 존재하지 않습니다.
//  => char 배열 + 널 문자
//     null terminated char array

// NULL은 3가지
// 1. NULL Pointer
//    #define NULL (void*)0
// 2. NULL Character
//    #define '\0' (char)0
// 3. 0

int main()
{
	char* str1   = "hello";
	char  str2[] = "hello";
}

#if 0
int main()
{
	char arr1[] = { 'h', 'e', 'l', 'l', 'o' };
	// char arr2[] = "hello";
	char arr2[] = { 'h', 'e', 'l', 'l', 'o', '\0' };

	// arr2 => char* 
	char* str = "hello";




}
#endif
