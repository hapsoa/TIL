#include <stdio.h>
// 알고리즘
//   반복문
//   재귀함수

// 재귀 함수
//  - 장점
//   : 직관적인 형태의 코드를 작성할 수 있다.
//  - 단점
//   : 함수 호출의 오버헤드로 인해, 반복문으로 동일한 알고리즘을
//     처리하는 것보다 느려진다.

// 반복문
//  - 장점
//   : 함수 호출의 오버헤드가 없다.

//  - 단점
//   : 코드를 이해하기 어렵다.

// 100 + 99 + 98 .... + 1
int sum_recursive(int n)
{
	if (n <= 1)
		return 1;

	return n + sum_recursive(n - 1);
}


// 1-n 까지의 합을 구하는 함수를 작성하시오
int sum_iteration(int n)
{
	int sum = 0;
	for (int i = 0 ; i <= n; ++i)
		sum += i;
	return sum;
}


int main()
{
	printf("%d\n", sum_iteration(100));
	printf("%d\n", sum_recursive(100));
}

