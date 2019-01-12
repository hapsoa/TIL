#include <stdio.h>
#include <limits.h>

#define STACK_SIZE 10
#define STACK_ERR  INT_MAX

struct stack
{
	int data[STACK_SIZE];
	int top;  // 0 or -1
};


void init(struct stack* s)
{
	s->top = 0;
}

void push(struct stack* s, int a)
{
	if (s->top == STACK_SIZE)
	{
		printf("stack overflow\n");
		return;
	}

	s->data[s->top++] = a;
}


int pop(struct stack* s)
{
	if (s->top == 0)
	{
		printf("stack underflow\n");
		return STACK_ERR;
	}

	return s->data[--s->top];
}

int main()
{
	struct stack s1;
	init(&s1);

	s1->top = 100;
	// 이 방법을 막을 수 없습니다.

	push(&s1, 10);
	push(&s1, 20);
	push(&s1, 30);

	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s1));
}
