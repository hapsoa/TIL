#include <stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr + 1;

	// arr[1]
	//  *(arr + 1)


	printf("%d\n", p[-1]);
	//             *(p - 1)
}
