
#include <stdint.h>
#include <stdio.h>

int main()
{
	// printf("%ld\n", sizeof(int));   // 4, 4
	// printf("%ld\n", sizeof(long));  // 8, 4

	printf("%ld\n", sizeof(int8_t));
	printf("%ld\n", sizeof(int16_t));
	printf("%ld\n", sizeof(int32_t));
	printf("%ld\n", sizeof(int64_t));
}
