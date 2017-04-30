#include <stdio.h>
#include "stack.h"

void stackInit(Stack * stack)
{
	stack->head = NULL;
}

int sIsEmpty(Stack * stack)
{
	if (stack->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void push(Stack * stack, int index)
{
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->minIndex = index;
	newNode->next = stack->head;
	stack->head = newNode;
}

int pop(Stack * stack)
{
	int data;
	StackNode * node;

	if (sIsEmpty(stack)) // 빈 스택일 경우
	{
		printf("stack에 값이 없습니다.\n");
		return NULL;
	}

	data = stack->head->minIndex;
	node = stack->head;

	stack->head = stack->head->next;
	free(node);

	return data;
}

int peek(Stack * stack)
{
	if (sIsEmpty(stack)) // 빈 스택일 경우
	{
		printf("stack에 값이 없습니다.\n");
		return NULL;
	}
	return stack->head->minIndex;
}
