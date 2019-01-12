#include <stdio.h>
#include <math.h>

int main()
{
	double a = 0.7;
	double b = 0.8 - 0.1;

	// if (a == b)
	if (fabs(a - b) < 0.000001)
	{
		printf("same..\n");
	}
	else
	{
		printf("diffrent..\n");
	}
}
