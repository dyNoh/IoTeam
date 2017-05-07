#pragma once

#define TRUE 1
#define FALSE 0

typedef struct _queue
{
	struct _queueNode *front;
	struct _queueNode *rear;
	int route;	// 도착하려는 최단 경로 값
}Queue;

typedef struct _queueNode
{
	int minRoute;	// 인덱스값
	int minIndex;	// 최단경로
	struct _queueNode *next;
}QueueNode;

typedef struct _min
{
	int minRoute;	// 인덱스값
	int minIndex;	// 최단경로
}Min;

void queueInit(Queue *queue);							// 큐 초기화
int qIsEmpty(Queue *queue);								// 큐 비었는지 확인
void enQueue(Queue *queue, int minRoute, int minIndex);	// enqueue 연산
int deQueue(Queue *queue);								// dequeue 연산
int indexPeek(Queue *queue);							// peek 연산(index)
int routePeek(Queue *queue);							// peek 연산(route)