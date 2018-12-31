// 선형 자료 구조
//   배열
//   리스트

// 우선순위 큐
//  => 데이터가 들어간 순서에 상관없이
//     우선순위가 가장 높은 원소가 먼저 나온다.
//  1. Stack - LIFO
//  2. Queue - FIFO

// C 언어는 오류를 함수의 반환값을 통해 전달한다.
#include <stdio.h>
#include <limits.h>

#define STACK_SIZE 10
#define STACK_ERR  INT_MAX

int data[STACK_SIZE];
int top = 0;  // -1

void push(int a)
{
	if (top == STACK_SIZE)
	{
		printf("stack overflow\n");
		return;
	}



	data[top++] = a;
}

int pop()
{
	if (top == 0)
	{
		printf("stack underflow\n");
		return STACK_ERR;
	}

	return data[--top];
}

int main()
{
	push(10);
	push(20);
	push(30);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}
















