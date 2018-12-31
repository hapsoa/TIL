#include <stdio.h>

// 아 -> 0xfefe    => encoding
// &  -> 0xfefe
// ascii - 영어 1byte / 한글 2byte 이상
//  => encoding

// 인코딩 표준 => 유니코드 / 멀티바이트
//  Windows => euc-kr(멀티 바이트) == CP949
//             Unicode(UTF-16_KR)
//  Linux   => Unicode(UTF-8_KR)
//  macOS   => Unicode(UTF-8_KR)
size_t xstrlen(const char *s)
{
	const char* p = s;
	while (*p)
	{
		p++;
	}

	return p - s;
}

char *xstrcpy(char *dest, const char *src)
{
	char *s = dest;
	while ((*dest++ = *src++) != '\0')
		/* Nothing */;
		
	return s;
}

char *xstrcat(char *dest, const char *src)
{
	char *s = dest;
	while (*dest)
		dest++;

	while ((*dest++ = *src++) != '\0')
		/* Nothing */;
	
	return s;
}

int main()
{
	// strlen
	char* s = "hello";
	printf("%ld\n", xstrlen(s));

	// strcpy
	char dest[100];
	xstrcpy(dest, s);
	printf("%s\n", dest);
	// strcat
}






