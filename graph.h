#pragma once

#include "list.h"

typedef struct _graph
{
	int numOfVertex;		// ���� ��
	int numOfEdge;			// ���� ��
	struct _list *edgeList;	// �׷����� ����Ʈ��
}Graph;

void graphInit(Graph *graph, Data *data, int num);						// �׷��� �ʱ�ȭ
void graphDataInit(Graph *graph, Data *data, int num);					// �׷��� �ʱ�ȭ(���� ��ĥ����)
void graphRemove(Graph *graph);
void addEdge(Graph *graph, Data *from, Data *to/*, int num*/);	// ���� ����
void showGraph(Graph *graph);