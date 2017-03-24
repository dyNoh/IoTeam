#pragma once

#include "list.h"

typedef struct _graph
{
	int numOfVertex;		// ���� ��
	int numOfEdge;			// ���� ��
	struct _list *edgeList;	// �׷����� ����Ʈ��
}Graph;

void graphInit(Graph *graph, int num);
void graphRemove(Graph *graph);
void addEdge(Graph *graph, Data *from, Data *to);
void showGraph(Graph *graph);