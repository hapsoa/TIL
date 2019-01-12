
#include <stdio.h>

int main()
{
	int arr[3][4];
	
	printf("sizeof arr[0]: %ld\n", sizeof(arr[0]));         // 16
	printf("sizeof &arr[0]: %ld\n", sizeof(&arr[0]));       // 8
	printf("sizeof arr[0][0]: %ld\n", sizeof(arr[0][0]));   // 4
	printf("sizeof &arr[0][0]: %ld\n", sizeof(&arr[0][0])); // 8

	printf("sizeof *arr: %ld\n", sizeof(*arr));   // *(arr + 0)  // arr[0] // 16
	printf("sizeof **arr: %ld\n", sizeof(**arr)); // **arr // arr[0][0]    // 4
}
