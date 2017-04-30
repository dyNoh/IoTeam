#pragma once

#define TRUE 1
#define FALSE 0

typedef struct _stack
{
	int minRoute;	// 최소 경로
	struct _stackNode *head;
}Stack;

typedef struct _stackNode
{
	int minIndex;	// 인덱스값
	struct _stackNode *next;
}StackNode;

void stackInit(Stack *stack);		// 스택 초기화
int sIsEmpty(Stack *stack);			// 스택 비었는지 확인
void push(Stack *stack, int index);	// push 연산
int pop(Stack *stack);				// pop 연산
int peek(Stack *stack);			// peek 연산