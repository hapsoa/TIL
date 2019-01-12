
// 사용자 정의 타입 - 상수를 관리하기 위해 사용합니다.

// 상수를 관리하는 방법
// 1. #define STATE_RUNNING         0
//    #define STATE_STOP            1
//    #define STATE_INTERRUPTABLE   2

#if 0
#define STATE_RUNNING         0
#define STATE_STOP            1
#define STATE_INTERRUPTABLE   2
#endif
// => 전처리기의 문법은 컴파일러를 통해서 정보를 확인하는 것이 어렵다.

#include <stdio.h>

// enum 개념을 사용하면 좀 더 편리하게 사용할 수 있다.
enum State {
	STATE_RUNNING = 422131313123123123123,
	STATE_STOP,
	STATE_INTERRUPTABLE
};

// enum의 문제점
// 1. 타입 안정성이 떨어진다.
//    int로 취급되기 때문에, 이상한 값이 들어오는 부분을 컴파일 에러로
//    감지할 수 없다.
// 2. enum의 요소가 전역적인 공간에 존재한다.
//    STATE_RUNNING -> State.STATE_RUNNING
// 3. swich / if , else if ... 같은 코드가 계속 발생한다. 
//    => OCP를 만족하지 않는다.
// 4. 정수 타입으로 취급이 되는데 정확한 크기에 대한 정의가 없다.
//    sizeof(enum State);
//    => C++은 enum class 라는 개념을 도입하였다.



int main()
{
	enum State state;
	// state = STATE_RUNNING;
	state = 100;
	// => C 언어에서는 해당 문제를 해결할 수 없다.
	// => C++은 State와 정수 타입을 별도의 타입으로 취급한다. 
	
	printf("%d\n", state);
	printf("%ld\n", sizeof(enum State));
}


#if 0
int main()
{
	int state = 42;
	printf("%d\n", state);
}
#endif
