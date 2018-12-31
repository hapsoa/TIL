
// program을 만드는 것 = 프로그래밍
// programming language - C
//   1. a.c(source file)
//      컴파일 단위: 파일이기 때문에, 다른 파일에 존재하는 함수의 존재를 알 수없다. 
//                   다른 파일에 구현된 함수가 존재한다는 사실을 컴파일러에게 알려주어야 한다.
//   2. preproceesor    -> 전처리기 
//          ; #으로 시작하는 모든 명령은 전처리기가 처리한다.
//   3. compile         -> a.o, b.o (compiler: gcc)
//   4. linking         -> a.out    (linker: collect2)


// 코드의 품질판단
//  유지보수가 용이해야 한다.
//   => 전체적인 개발의 비용을 절감할 수 있다.

#include <stdio.h>
// stdio library를 불러오기 위해 필요한 작업.

#define PI 3.141592

int main()
{
	printf("hello, world...\n");
	printf("%lf", PI);
	return 0;
}
