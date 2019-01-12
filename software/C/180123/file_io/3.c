
// $ cat
// 모든 것이 파일이다.
#include <stdio.h>
#include <unistd.h> // sleep / usleep

// stdin/stdout: line buffering
// regular file: full buffering

// 한글자씩 읽어서 출력하는 프로그램
// 파일의 끝: EOF
// 키보드를 통해서 EOF를 전달하는 방법: Ctrl + D
int main()
{
	char ch;
	FILE* fp = fopen("3.c", "r");

	// while ((ch = fgetc(fp)) != EOF)
	while ((ch = getchar()) != EOF)
	{
		fputc(ch, stdout);
		// usleep(1000 * 1000 * 0.2);
		fflush(stdout);
	}
}
#if 0
int main()
{
	char ch;
	FILE* fp = fopen("3.c", "r");

	while (1)
	{
		// fgetc: file에한 글자를 입력 받는 함수.
		// ch = getchar();
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		//   stdin으로 부터 한 글자를 입력받는 함수.

		// putchar(ch);
		fputc(ch, stdout);
		//   인자로 전달받은 ch를 stdout에 출력하는 함수
		// fflush(stdout);
		// 강제적으로 출력 버퍼를 비울 수 있다.
		usleep(1000 * 1000 * 0.2);
	}
}
#endif




