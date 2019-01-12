// a.txt
//  => hello, world

// Unix / Linux: 모든 것은 파일이다.
// 모니터(표준 출력 장치): stdout - line
// 키보드(표준 입력 장치): stdin
// 모니터(표준 에러 장치): stderr - no buffering

// a.txt: 명시적으로 열어주면 된다.

#include <stdio.h>

int main()
{
	// 인자 1: 파일명
	// 인자 2: 모드  
	//   읽기: "r"  
	//   쓰기: "w" 
	// 아래의 옵션은 C 표준이 아닙니다.
	//  : Windows에서만 사용합니다.
	//   "t": "Text"
	//   "b": "Binary"

	// FILE* stdout = fopen(...);
	FILE* fp = fopen("a.txt", "w");


	// printf("hello, world\n");
	fprintf(fp, "hello, world\n");
}




