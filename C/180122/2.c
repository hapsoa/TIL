// 다른 파일에 존재하는 함수에 대해서 알려준다.
//  => 컴파일러가 함수에 대해서 알고 싶은 정보
//      1. 반환 타입
//      2. 인자의 개수와 타입

void foo();  // 선언 - 함수의 프로토타입 

int main()
{
	foo();
}
