
#include <stdio.h>
#include <string.h>
// 1. xstrlen를 구현하시오
// 2. xstrcpy를 구현하시오
// 3. xstrcat를 구현하시오
// => 포인터의 연산으로 만드시오.
int main()
{
	char a[100];

	// a = "hello"; 초기화에서만 허용한다.
	xstrcpy(a, "hello");
	printf("%s\n", a);

	// "hello" + " world" -> strcat
	xstrcat(a, " world");
	printf("%s\n", a);

	// 배열의 길이
	int n = sizeof(a) / sizeof(a[0]);  // 100

	// 문자열의 길이
	n = xstrlen(a);
	printf("%d\n", n);
}
