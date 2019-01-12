#include <stdio.h>
#include <stdlib.h>

int max_value(int* arr, int n);
int min_value(int* arr, int n);
double average_value(int* arr, int n);

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		printf("malloc failed...\n");
		return -1;
	}

	for (int i = 0 ; i < n ; ++i)
		scanf("%d", &arr[i]);

	printf("최대: %d\n", max_value(arr, n));
	printf("최소: %d\n", min_value(arr, n));
	printf("평균: %.2lf\n", average_value(arr, n));
}

int max_value(int* arr, int n)
{
	int ret = arr[0];
	for (int i = 1 ; i < n ; ++i)
		if (ret < arr[i])
			ret = arr[i];

	return ret;
}

int min_value(int* arr, int n)
{
	int ret = arr[0];
	for (int i = 1 ; i < n ; ++i)
		if (ret > arr[i])
			ret = arr[i];

	return ret;

}

double average_value(int* arr, int n)
{
	int sum = 0;
	for (int i = 0 ; i < n ; ++i)
		sum += arr[i];
	return (double)sum / n;
}
