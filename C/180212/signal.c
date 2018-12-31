
#include <signal.h>

void (*signal(int, void(*handler)(int)))(int);

typedef void (*handler_t)(int);
handler_t signal(int, handler_t);

void foo(int signum)
{
	printf("foo\n");
}

// Ctrl+C: Interrupt
//  : 프로세스의 기본 동작은 종료. 
int main()
{
	void (*p)(int) = signal(SIGINT, &foo);


	while (1);
}
