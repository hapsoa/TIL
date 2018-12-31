
#include <stdio.h>

// arr's type: int[3]
// arr(배열의 이름)은 일반적으로 배열의 첫번째 원소의
// 시작 주소로 해석된다.
//  &arr[0] -> int*
//  : decay

// decay가 발생하지 않는 경우 2가지
// 1) sizeof 연산
//   sizeof(arr): 12
// 2) &(address) 연산
//   &arr -> int[3]* -> int(*)[3]




void foo(int* p)
{

}

int main()
{
	int arr[3] = { 1, 2, 3 };
	foo(arr);
}
