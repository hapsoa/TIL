#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;

#if 0
	d = ++a ||(b++ && c++);
	printf("%d %d %d %d\n", a, b, c, d);
#endif
	f = a++ || (++b && ++c) || (++d && e++);
	printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
	// 1  1  1 0  0 1
	
	
	// 1. 우선 순위가 다르다.
	// &&가 우선순위가 높다.
	// 2. 단회로의 특성
	// && -> 앞에 것이 거짓이면, 뒤에 것을 판단하지 않는다.
	// || -> 앞의 것이 참이면,    "
	// 3. 우선 순위는 연산을 먼저하는 것이 아니라
	//    결합을 결정하는 것이다.
}
