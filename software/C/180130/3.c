// 데이터 영역에는 수정 할 수 없고,
// 스택 영역은 왜 수정이 가능한가?

// C 언어의 변수 저장 클래스 - Storage class
//  1. 지역 변수 - stack 
//  2. 전역 변수 - data
//  3. 힙 변수   - heap

// "hello", "ok", "show"
//  => 실행 파일(.rodata)
//   : 수정이 불가능하다.

char s[] = "hello"; 
// .rodata의 문자열을 복사해 온 것이다.
char* p = "hello";
// .rodata의 문자열을 가르키는 것이다.
int main()
{
	char x[] = "hello";

}

