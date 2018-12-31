#include <stdio.h>

int is_prime(int value);
int prime_sum(int arr[], int n);

int main()
{
	int arr[10];

	int count = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0 ; i < 10 ; ++i)
		scanf("%d", &arr[i]);

	int sum = prime_sum(arr, count);
	printf("sum: %d\n", sum);
}

int is_prime(int value)
{
	if (value <= 1)
		return 0;
	
	for (int i = 2; i < value ; ++i)
		if (value % i == 0)
			return 0;

	return 1;
}

// 참/ 거짓
//  C 언어의  참: non zero
//          거짓: 0
int prime_sum(int arr[], int n)
{
	int sum = 0;
	for (int i = 0 ; i < n ; ++i)
		sum += is_prime(arr[i]) ? arr[i] : 0;

		if (is_prime(arr[i]))
			sum += arr[i];
		else
			sum += 0;
	
	return sum;
}

