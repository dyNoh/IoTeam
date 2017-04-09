#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void graphInit(Graph * graph, Data *data, int num)	//그래프 초기화
{
	graph->edgeList = (List*)malloc(sizeof(List)*num);	//리스트 생성

	graph->numOfVertex = num;	
	graph->numOfEdge = 0;		//데이터 초기화

	for (int i = 0; i < num; i++) // init
	{
		listInit(&(graph->edgeList[i]), &data[i], num);	//리스트초기화(그래프의 리스트배열, 데이터배열, 정점갯수)
	}
}

void graphDataInit(Graph * graph, Data *data, int num)	//그래프데이터 초기화
{
	int bNX, bNY, bNH, bNV, nNX, nNY, nNH, nNV;	// beforeNode, nextNode
	int Xcount = 0, Ycount = 0, minX, minY, x, y, removeCount = 0;
	Node *node;

	for (int i = 0; i < num; i++) // 1STEP
	{
		for (int j = i + 1; j < num; j++)
		{
			// 값의 비교를 위한 삽입
			bNX = graph->edgeList[i].listData->x;
			bNY = graph->edgeList[i].listData->y;
			bNH = graph->edgeList[i].listData->horizontal;
			bNV = graph->edgeList[i].listData->vertical;
			nNX = graph->edgeList[j].listData->x;
			nNY = graph->edgeList[j].listData->y;
			nNH = graph->edgeList[j].listData->horizontal;
			nNV = graph->edgeList[j].listData->vertical;

			// x값과 horizontal 값이 서로 같을 경우 인접노드, y값과 vertical 값이 서로 같을 경우 인접노드
			if ((bNX == nNX &&bNH == nNH) || (bNY == nNY && bNV == nNV))
			{
				LInsert(&(graph->edgeList[i]), &data[j]);
				LInsert(&(graph->edgeList[j]), &data[i]);
				(graph->numOfEdge)++;	// 간선 수 증가
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

		node = findFList(&graph->edgeList[i]); // 첫번째 노드 확인

		if (node != NULL)
		{
			nNX = node->data->x;
			nNY = node->data->y;
			nNH = node->data->horizontal;
			nNV = node->data->vertical;
			if (bNX == nNX &&bNH == nNH)
			{
				Xcount++; // x값 겹침
			}
			if (bNY == nNY && bNV == nNV)
			{
				Ycount++; // y 값 겹침
			}

			while (1)
			{
				node = findNList(&graph->edgeList[i]); // 두번째 이후 노드 확인
				if (node != NULL)
				{
					nNX = node->data->x;
					nNY = node->data->y;
					nNH = node->data->horizontal;
					nNV = node->data->vertical;
					if (bNX == nNX &&bNH == nNH)
					{
						Xcount++; // x값 겹침
					}
					if (bNY == nNY && bNV == nNV)
					{
						Ycount++; // y 값 겹침
					}
				}
				else
				{
					break;
				}
			}
		}

		// D점, H점, J점,L점등은 생각해 봐야함

		if (Xcount > 1) // x값 겹칠경우 y값 짧은 경로 유지 나머지 삭제
		{
			node = findFList(&graph->edgeList[i]);
			if (node != NULL)
			{
				if (graph->edgeList[i].listData->x == node->data->x)
				{
					minY = graph->edgeList[i].listData->y - node->data->y;
					if (minY < 0) // 음수일 경우 절대값
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
							if (y < 0) // 음수일 경우 절대값
							{
								y = -y;
							}
							if (minY > y)
							{
								y = minY; // 노드 변경
								// 앞의 값 삭제 필요함
							}
							else
							{
								printf("%c에서 %c를 삭제합니다.\n", i+65, graph->edgeList[i].cur->data->name +65);
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
						printf("%c에서 %c를 삭제합니다.\n", i + 65, graph->edgeList[i].cur->data->name + 65);
						LRemove(&graph->edgeList[i]);
					}
				}
				removeCount = 0;
			}
		}

		if (Ycount > 1) // y값 겹칠경우 x값 짧은 경로 유지 나머지 삭제
		{
			node = findFList(&graph->edgeList[i]);
			if (node != NULL)
			{
				if (graph->edgeList[i].listData->y == node->data->y)
				{
					minX = graph->edgeList[i].listData->x - node->data->x;
					if (minX < 0) // 음수일 경우 절대값
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
							if (x < 0) // 음수일 경우 절대값
							{
								x = -x;
							}
							if (minY > x)
							{
								x = minX; // 노드 변경
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

void graphRemove(Graph * graph)	//그래프 삭제
{
	if (graph->edgeList != NULL)	//그래프의 리스트들이 없을때까지
	{
		free(graph->edgeList);	//메모리 동적할당 해제
	}
}

void addEdge(Graph * graph, Data *from, Data *to/*, int num*/)	//연결된 그래프 추가
{
	LInsert(&(graph->edgeList[from->name]), to);	//리스트 추가
	LInsert(&(graph->edgeList[to->name]), from);
	(graph->numOfEdge)++;	// 간선 수 증가
}

void showGraph(Graph * graph)	//그래프 출력
{
	for (int i = 0; i < graph->numOfVertex; i++)	//정점 수만큼 반복
	{
		printf("%c와 연결된 정점 : ", i + 65);	//ASCII코드번호 65번 더하여 출력
		
		showList(&(graph->edgeList[i]));	//리스트 출력
	}
}
