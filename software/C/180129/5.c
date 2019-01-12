
#include <stdio.h>

int main()
{
	int arr[3][4];
	
	// *arr  -> int (*)[4] -> int[4] -> 16
	// **arr -> int (*)[4] -> int[4] -> int* -> int -> 4
	printf("sizeof *arr: %ld\n", sizeof(*arr));    // 16
	printf("sizeof **arr: %ld\n", sizeof(**arr));  // 4
}
