#include "route.h"
#include <stdlib.h>
#include <stdio.h>

int* traceEXIT(Graph * graph, User * user, int size)
{
	int *route = (int*)malloc(sizeof(int) * size);
	int x, y;
	Min _min = { RIGHT_END, 0 };
	Min *min = &_min;
	Stack stack;
	int num;

	stackInit(&stack);

	// 1STEP 모든 노드까지의 경로를 찾는다.
	min = findRoute(graph, user, min, route, size);
	/*for (int i = 0; i < size; i++)
	{
		x = user->x - graph->edgeList[i].listData->x;
		y = user->y - graph->edgeList[i].listData->y;
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		route[i] = x + y;
		if (min.minRoute > route[i])
		{
			min.minRoute = route[i];
			min.minIndex = i;
		}
	}*/

	printf("minRoute : %d\n", min->minRoute);
	printf("minNode : %c\n", min->minIndex + 65);

	push(&stack, min->minIndex);
	num = peek(&stack);
	printf("num = %c\n", num + 65);

	// 연결된 노드와 근접노드를 구한다.

	return route;
	
	// 2STEP 가까운 노드로 이동 후 경로를 찾는다.
	// 2_1 경로를 찾아나간다.
	// 2_2 EXIT 노드일 경우 종료
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
	
	printf("\n\n\n\n*****\n");
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
	printf("\n*****\n\n\n\n");
}