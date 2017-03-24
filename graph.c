#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void graphInit(Graph * graph, int num)
{
	graph->edgeList = (List*)malloc(sizeof(List)*num);

	graph->numOfVertex = num;
	graph->numOfEdge = 0;

	for (int i = 0; i < num; i++)
	{
		listInit(&(graph->edgeList[i]));
	}
}

void graphRemove(Graph * graph)
{
	if (graph->edgeList != NULL)
	{
		free(graph->edgeList);
	}
}

void addEdge(Graph * graph, Data *from, Data *to)
{
	LInsert(&(graph->edgeList[from->name]), to);
	LInsert(&(graph->edgeList[to->name]), from);
	(graph->numOfEdge)++;
}

void showGraph(Graph * graph)
{
	for (int i = 0; i < graph->numOfVertex; i++)
	{
		printf("%c와 연결된 정점 : ", i + 65);

		showList(&(graph->edgeList[i]));
	}
}
