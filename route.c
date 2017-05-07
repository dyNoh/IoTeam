#include "route.h"
#include <stdlib.h>
#include <stdio.h>

Queue* traceEXIT(Graph * graph, User * user, Queue *queue, int(*routeData)[SIZE], int size)
{
	int *route = (int*)malloc(sizeof(int) * size);
	int x, y;
	int name;
	Min _min = { RIGHT_END, 0 };
	Min *min = &_min;
	int num;
	int findNode[SIZE] = { 0 };
	int findNodeValue = MM;
	int max = 0, maxIndex;
	int index;

	// 1STEP EXIT 노드 찾는다.
	for (int i = 0; i < size; i++)
	{
		if (graph->edgeList[i].listData->spec == EXIT)
		{
			name = graph->edgeList[i].listData->name;
		}
	}

	// 2STEP User와 가까운 노드 찾는다. if User와 가까운 노드가 EXIT노드일 경우 종료
	min = findRoute(graph, user, min, route, size);

	printf("minRoute : %d\n", min->minRoute);
	printf("minNode : %c\n", min->minIndex + 65);

	enQueue(queue, min->minRoute, min->minIndex);

	showRoute(route, size);

	if (min->minIndex == name)
	{
		return queue;
	}
	// 3STEP 다익스트라 알고리즘을 통해 경로를 전부 구한다.
	routeDataInit(graph, routeData, size);

	// 4STEP 가까운 노드를 X라 했을 때 X->K 보다 Y->K가 작고 X->Y + Y->EXIT == X->EXIT && !name인 노드들 찾는다.
	printf("[ ");
	for (int i = 0; i < size; i++)
	{
		if (routeData[min->minIndex][name] > routeData[i][name] && (routeData[min->minIndex][i] + routeData[i][name]) == routeData[min->minIndex][name] && i != name)
		{
			findNode[i] = TRUE;
		}
		printf("%d ", findNode[i]);
	}
	printf("]\n");
	
	// 5STEP 찾은 노드들 중 거리가 큰 수부터 큐에 넣는다.

	while (findNodeValue != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (findNode[i] == TRUE)
			{
				if (max < routeData[i][name])
				{
					max = routeData[i][name];
					maxIndex = i;
				}
			}
		}
		printf("maxIndex = %c\n", maxIndex + 65);
		printf("max = %d\n", max);
		enQueue(queue, max, maxIndex);
		max = 0;
		findNode[maxIndex] = 0;
		printf("[ ");
		findNodeValue = 0;
		for (int i = 0; i < size; i++)
		{
			findNodeValue += findNode[i];
			printf("%d ", findNode[i]);
		}
		printf("]\n");
		printf("value : %d\n", findNodeValue);
	}

	// 6STEP EXIT 노드 넣는다.
	enQueue(queue, routeData[maxIndex][name], name);

	return queue;
}

void showRoute(int * route, int size)
{
	for (int i = 0; i < size; i++) // i SIZE까지 돌아야 함
	{
		printf("현재 user의 위치에서 %c까지의 거리 : %dcm\n", i + 65, route[i]);
	}
}

Min* findNextNode(List * list)
{
	int *numOfData = (int*)malloc(sizeof(int) * list->numOfData);
	return 0;
}

Min * findRoute(Graph * graph, User * user, Min *min, int *route, int size)
{
	int x, y;

	for (int i = 0; i < size; i++)
	{
		x = user->x - graph->edgeList[i].listData->x;
		y = user->y - graph->edgeList[i].listData->y;
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		route[i] = x + y;
		if (min->minRoute > route[i])
		{
			min->minRoute = route[i];
			min->minIndex = i;
		}
	}
	return min;
}

void routeDataInit(Graph * graph, int(*route)[SIZE], int size)
{
	int num;
	int x, y;
	Node *temp;
	// i와 j가 같을 경우 0, 나머지 MM에서 시작

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				route[i][j] = 0;
			}
			else
			{
				route[i][j] = MM;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		num = graph->edgeList[i].numOfData; // data의 갯수를 구한다.
		for (int j = 0; j < num; j++) // data의 갯수만큼 돌면서 최단경로 찾는다.
		{
			if (j == 0) // 처음
			{
				temp = findFList(&(graph->edgeList[i]));
			}
			else // 2번째 이후
			{
				temp = findNList(&(graph->edgeList[i]));
			}
			for (int k = 0; k < size; k++)
			{
				if (temp->data->name == k)
				{
					x = graph->edgeList[i].listData->x - temp->data->x;
					y = graph->edgeList[i].listData->y - temp->data->y;
					if (x < 0) x = -x;
					if (y < 0) y = -y;
					route[i][k] = x + y;
					//graph->edgeList[i]
				}
			}
		}
	}

	// 다익스트라 알고리즘

	for (int i = 0; i < size; i++)
	{
		dijkstra(route, i); // 그래프, 시작 정점
	}
	
	/*printf("\n\n\n\n*****\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%c -> %c : ", (i + 65), (j + 65));
			if (route[i][j] == MM)
			{
				printf("MAX\n");
			}
			else
			{
				printf("%d\n", route[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n*****\n\n\n\n");*/
}

void dijkstra(int(*route)[SIZE], int src)
{
	int min, index;
	int set[SIZE] = { 0 };
	int dist[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		dist[i] = MM;
	}

	dist[src] = 0;

	for (int i = 0; i < SIZE; i++)
	{
		min = MM;

		for (int j = 0; j < SIZE; j++)
		{
			if (min > dist[j] && set[j] == 0)
			{
				min = dist[j];
				index = j;
			}
		}

		for (int j = 0; j < SIZE; j++)
		{
			if (dist[j] > route[index][j] + dist[index] && route[index][j] != MM && set[index] == 0)
			{
				dist[j] = route[index][j] + dist[index];
			}
		}
		set[index] = 1;
	}

	/*for (int i = 0; i < SIZE; i++)
	{
		printf("set[%d] = %d\n", i, set[i]);
	}*/

	printf("---------------------\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%c -> %c : %d\n", src+65, i + 65, dist[i]);
		// 추가
		route[src][i] = dist[i];
	}
}
