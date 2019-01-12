
#include <stdio.h>

// 포인터 배열 / 배열 포인터
int *p[3];




// 배열 포인터
void foo(int (*arr)[5])
{
	for (int i = 0 ; i < 4; ++i)
	{
		for (int j = 0 ; j < 5; ++j)
		{
			arr[i][j] = i * j;
		}
	}
}

int main()
{
	int arr[4][5];
	foo(arr);
	
	for (int i = 0 ; i < 4; ++i)
	{
		for (int j = 0 ; j < 5; ++j)
		{
			printf("%3d", arr[i][j]);
		}
		putchar('\n');
	}



}
