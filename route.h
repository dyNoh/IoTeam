#pragma once
#include "graph.h"
#include "user.h"
#include "stack.h"
#include "queue.h"

#define LEFT_END 0
#define RIGHT_END 8826
#define UP_END 0
#define DOWN_END 1866
#define SIZE 16
#define MM 99999

Queue* traceEXIT(Graph * graph, User * user, Queue *queue, int(*routeData)[SIZE], int size);	// 탈출경로를 찾는다.
void showRoute(int* route, int size); // 현재 user의 오차도를 판별하여 가까운 노드 계산
Min* findNextNode(List *list);	// 다음 노드까지의 경로 찾고 반환
Min* findRoute(Graph *graph, User *user, Min *min, int *route, int size); // 모든 노드까지의 거리를 찾는다.
void routeDataInit(Graph *graph, int (*route)[SIZE], int size);	// 최단경로 데이터를 초기화한다.
void dijkstra(int(*route)[SIZE], int src); // 다익스트라 알고리즘 수행