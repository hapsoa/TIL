
#include <stdio.h>

// 1. 배열의 [] 기호는 반드시 심볼의 뒤에 와야 한다.
// int[3] *p
// => int *p[3]
// 2. [] vs * 우선순위
// => []가 우선순위가 더 높다. 그래서 포인터가 먼저 해석되도록,
//    ()로 묶어주어야 한다.
// => int (*p)[3]
void foo(int (*p)[3])
{
	printf("%ld\n", sizeof(p));  // ?
}

int main()
{
	int arr[5][3];
	// 몇개?    5개
	// arr[0]?  int[3]

	foo(arr);
	// 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
	foo(&arr[0]);
	// &arr[0]
	// &int[3]
	// int[3]*

}
