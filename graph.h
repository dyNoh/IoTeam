#pragma once //한번만 컴파일 하도록 명령(헤더의 중복을 막음)

#include "list.h"

typedef struct _graph
{
	int numOfVertex;		// 정점 수
	int numOfEdge;			// 간선 수
	struct _list *edgeList;	// 그래프의 리스트들
}Graph;

void graphInit(Graph *graph, Data *data, int num);						// 그래프 초기화
void graphRemove(Graph *graph);
void addEdge(Graph *graph, Data *from, Data *to/*, int num*/);	// 간선 연결
void showGraph(Graph *graph);