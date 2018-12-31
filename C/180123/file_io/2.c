#include <stdio.h>

// FILE* stdin = fopen("...", "r");
int main()
{
	int age;
	FILE* fp = fopen("input.txt", "r");

	// stdin: keyboard
	// scanf("%d", &age);
	fscanf(fp, "%d", &age); 

	printf("age: %d\n", age);
}
