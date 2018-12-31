
#include <stdio.h>

// getchar()
// fgetc()
// 위의 함수의 반환타입은 char가 아닌 int 입니다.
//  => 반드시 int를 통해서 처리해야, 바이너리에서 문제가 발생하지 않습니다.

#if 0
char ch  = 0xFF;
int  EOF = 0xFFFFFFFF
ch == EOf => Same

int ch =  0x000000FF;
int EOF = 0xFFFFFFFF;
ch == EOF => Diff
#endif

int main()
{
	FILE* fp = fopen("a.out", "r");

	int ch;
	int size = 0;
	while ((ch = fgetc(fp)) != EOF)
		++size;

	printf("size: %d\n", size);
}
