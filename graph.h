#pragma once

#include "list.h"

typedef struct _graph
{
	int numOfVertex;		// 정점 수
	int numOfEdge;			// 간선 수
	struct _list *edgeList;	// 그래프의 리스트들
}Graph;

void graphInit(Graph *graph, int num);
void graphRemove(Graph *graph);
void addEdge(Graph *graph, Data *from, Data *to);
void showGraph(Graph *graph);