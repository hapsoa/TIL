#include <stdio.h>
int max_arr(int arr[], int n);
int min_arr(int arr[], int n);

int main()
{
	int arr[10];

	int count = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0 ; i < 10 ; ++i)
		scanf("%d", &arr[i]);

	printf("%d\n", max_arr(arr, count));
	printf("%d\n", min_arr(arr, count));
}

int max_arr(int arr[], int n)
{
	int ret = arr[0];
	for (int i = 1; i < n; ++i)
		if (ret < arr[i])
			ret = arr[i];
	
	return ret;
}

int min_arr(int arr[], int n)
{
	int ret = arr[0];
	for (int i = 1; i < n; ++i)
		if (ret > arr[i])
			ret = arr[i];
	
	return ret;
}

