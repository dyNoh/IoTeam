#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueInit(Queue * queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->route = 0;
}

int qIsEmpty(Queue * queue)
{
	if (queue->front == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void enQueue(Queue * queue, int minRoute, int minIndex)
{
	QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->next = NULL;
	newNode->minRoute = minRoute;
	newNode->minIndex = minIndex;

	queue->route += minRoute;

	if (qIsEmpty(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

int deQueue(Queue * queue)
{
	QueueNode *delNode;
	int data;

	if (qIsEmpty(queue))
	{
		printf("queue에 값이 없습니다.\n");
		return NULL;
	}

	delNode = queue->front;
	data = delNode->minIndex;
	queue->front = queue->front->next;

	queue->route -= delNode->minRoute;

	free(delNode);
	return data;
}

int indexPeek(Queue * queue)
{
	if (qIsEmpty(queue))
	{
		printf("queue에 값이 없습니다.\n");
		return NULL;
	}

	return queue->front->minIndex;
}

int routePeek(Queue * queue)
{
	if (qIsEmpty(queue))
	{
		printf("queue에 값이 없습니다.\n");
		return NULL;
	}

	return queue->front->minRoute;
}
