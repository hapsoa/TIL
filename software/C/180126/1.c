
// 배열의 길이에 상관없이 배열의 평균을 구하는 함수를 만드시오
#include <stdio.h>

// 프로그래밍 언어 - naming convention
// 1. 모든 변수의 이름은 소문자로 시작한다.
// 2. 모든 함수의 이름은 소문자로 시작한다.
// 3. 모든 변수와 함수의 이름이 두 개의 단어 이상일 경우
//    _로 연결한다.
// 4. 중괄호({}) 는 다음 라인에 둔다.
// 5. 스페이스도 동일하게 작성한다.
//   1) #include <stdio.h>
//   2) if (condition)
//   3) for (int i = 0; i < 10; ++i)
//   4) int a = 0;
//   5) int arr[10] = { 1, 2, 3, 4, 5 };
// 6. 변수는 명사이고, 함수는 동사로 시작한다.

// 함수를 만드는 방법
// return_type func_name(arg_type arg_name, ...);
double get_average(int arr[], int n);

int main() 
{
	int arr[10];
	// 0...9
	// 배열을 사용하는 이유?
	//  : '같은 타입'의 변수가 여러개가 필요한 경우

	// 배열의 길이를 구하는 방법.
	int count = sizeof(arr) / sizeof(arr[0]);
	// int count = sizeof(arr) / sizeof(int);

	for (int i = 0 ; i < 10 ; ++i)
		scanf("%d", &arr[i]);

	// 배열을 함수의 인자로 보낼 때, 반드시 배열의 개수를 보내야 한다.
	//  : 다른 함수에서 배열의 크기를 절대 알 수 없다.
	double average = get_average(arr, count);
	printf("%lf\n", average);
}

// 7. 함수의 구현은 다른 파일이나, 같은 파일일 경우, main 함수의 아래에
//    작성한다.
double get_average(int arr[], int n)
{
	double sum = 0;
	for (int i = 0 ; i < n ; ++i)
		sum += arr[i];

	return sum / n;
}
