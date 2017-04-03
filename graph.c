#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void graphInit(Graph * graph, Data *data, int num)
{
	graph->edgeList = (List*)malloc(sizeof(List)*num);

	graph->numOfVertex = num;
	graph->numOfEdge = 0;

	for (int i = 0; i < num; i++) // init
	{
		listInit(&(graph->edgeList[i]), &data[i], num);
	}
}

void graphDataInit(Graph * graph, Data *data, int num)
{
	int bNX, bNY, bNH, bNV, nNX, nNY, nNH, nNV;	// beforeNode, nextNode
	int Xcount = 0, Ycount = 0, minX, minY, x, y, removeCount = 0;
	Node *node;

	for (int i = 0; i < num; i++) // 1STEP
	{
		for (int j = i + 1; j < num; j++)
		{
			// ���� �񱳸� ���� ����
			bNX = graph->edgeList[i].listData->x;
			bNY = graph->edgeList[i].listData->y;
			bNH = graph->edgeList[i].listData->horizontal;
			bNV = graph->edgeList[i].listData->vertical;
			nNX = graph->edgeList[j].listData->x;
			nNY = graph->edgeList[j].listData->y;
			nNH = graph->edgeList[j].listData->horizontal;
			nNV = graph->edgeList[j].listData->vertical;

			// x���� horizontal ���� ���� ���� ��� �������, y���� vertical ���� ���� ���� ��� �������
			if ((bNX == nNX &&bNH == nNH) || (bNY == nNY && bNV == nNV))
			{
				LInsert(&(graph->edgeList[i]), &data[j]);
				LInsert(&(graph->edgeList[j]), &data[i]);
				(graph->numOfEdge)++;	// ���� �� ����
			}
		}
	}

	/*for (int i = 0; i < num; i++) // 2STEP
	{
		//now
		bNX = graph->edgeList[i].listData->x;
		bNY = graph->edgeList[i].listData->y;
		bNH = graph->edgeList[i].listData->horizontal;
		bNV = graph->edgeList[i].listData->vertical;

		node = findFList(&graph->edgeList[i]); // ù��° ��� Ȯ��

		if (node != NULL)
		{
			nNX = node->data->x;
			nNY = node->data->y;
			nNH = node->data->horizontal;
			nNV = node->data->vertical;
			if (bNX == nNX &&bNH == nNH)
			{
				Xcount++; // x�� ��ħ
			}
			if (bNY == nNY && bNV == nNV)
			{
				Ycount++; // y �� ��ħ
			}

			while (1)
			{
				node = findNList(&graph->edgeList[i]); // �ι�° ���� ��� Ȯ��
				if (node != NULL)
				{
					nNX = node->data->x;
					nNY = node->data->y;
					nNH = node->data->horizontal;
					nNV = node->data->vertical;
					if (bNX == nNX &&bNH == nNH)
					{
						Xcount++; // x�� ��ħ
					}
					if (bNY == nNY && bNV == nNV)
					{
						Ycount++; // y �� ��ħ
					}
				}
				else
				{
					break;
				}
			}
		}

		// D��, H��, J��,L������ ������ ������

		if (Xcount > 1) // x�� ��ĥ��� y�� ª�� ��� ���� ������ ����
		{
			node = findFList(&graph->edgeList[i]);
			if (node != NULL)
			{
				if (graph->edgeList[i].listData->x == node->data->x)
				{
					minY = graph->edgeList[i].listData->y - node->data->y;
					if (minY < 0) // ������ ��� ���밪
					{
						minY = -minY;
					}
				}
				while (1)
				{
					node = findNList(&graph->edgeList[i]);
					if (node != NULL)
					{
						if (graph->edgeList[i].listData->x == node->data->x)
						{
							y = graph->edgeList[i].listData->y - node->data->y;
							if (y < 0) // ������ ��� ���밪
							{
								y = -y;
							}
							if (minY > y)
							{
								y = minY; // ��� ����
								// ���� �� ���� �ʿ���
							}
							else
							{
								printf("%c���� %c�� �����մϴ�.\n", i+65, graph->edgeList[i].cur->data->name +65);
								LRemove(&graph->edgeList[i]);
								removeCount++;
							}
						}
					}
					else
					{
						break;
					}
				}
				if (removeCount == 0)
				{
					if (findFList(&graph->edgeList[i]) != NULL)
					{
						printf("%c���� %c�� �����մϴ�.\n", i + 65, graph->edgeList[i].cur->data->name + 65);
						LRemove(&graph->edgeList[i]);
					}
				}
				removeCount = 0;
			}
		}

		if (Ycount > 1) // y�� ��ĥ��� x�� ª�� ��� ���� ������ ����
		{
			node = findFList(&graph->edgeList[i]);
			if (node != NULL)
			{
				if (graph->edgeList[i].listData->y == node->data->y)
				{
					minX = graph->edgeList[i].listData->x - node->data->x;
					if (minX < 0) // ������ ��� ���밪
					{
						minX = -minX;
					}
				}
				while (1)
				{
					node = findNList(&graph->edgeList[i]);
					if (node != NULL)
					{
						if (graph->edgeList[i].listData->y == node->data->y)
						{
							x = graph->edgeList[i].listData->x - node->data->x;
							if (x < 0) // ������ ��� ���밪
							{
								x = -x;
							}
							if (minY > x)
							{
								x = minX; // ��� ����
							}
							else
							{
								LRemove(&graph->edgeList[i]);
								removeCount++;
							}
						}
					}
					else
					{
						break;
					}
				}
				if (removeCount == 0)
				{
					if (findFList(&graph->edgeList[i]) != NULL)
					{
						LRemove(&graph->edgeList[i]);
					}
				}
				removeCount = 0;
			}
		}

		Xcount = 0;
		Ycount = 0;
	}*/
}

void graphRemove(Graph * graph)
{
	if (graph->edgeList != NULL)
	{
		free(graph->edgeList);
	}
}

void addEdge(Graph * graph, Data *from, Data *to/*, int num*/)
{
	LInsert(&(graph->edgeList[from->name]), to);
	LInsert(&(graph->edgeList[to->name]), from);
	(graph->numOfEdge)++;	// ���� �� ����
}

void showGraph(Graph * graph)
{
	for (int i = 0; i < graph->numOfVertex; i++)
	{
		printf("%c�� ����� ���� : ", i + 65);

		showList(&(graph->edgeList[i]));
	}
}
