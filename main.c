#include <stdio.h>
#include <Windows.h>
#include "graph.h"
#include "user.h"
#include "route.h"
#include "queue.h"

#define SIZE 16 

void gotoxy(int x, int y);

int main(void)
{
	Data data[SIZE];// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
	Graph graph;
	User user;	// 현재 유저
	User buser;	// beforeUser
	Queue _queue;
	Queue *queue = NULL;
	Min _min = { RIGHT_END,0 };
	int *route;
	int routeData[SIZE][SIZE];
	int minIndex, minRoute;
	int i = 0;
	int temp_x, temp_y;

	FILE *f = fopen("data.txt", "r");

	while (1)
	{
		if (i == SIZE)
		{
			break;
		}
		fscanf(f, "%d %d %d %d %d", &(data[i].x), &(data[i].y), &(data[i].spec), &(data[i].horizontal), &(data[i].vertical));
		data[i].name = i;
		dataInit(&data[i], data[i].x, data[i].y, data[i].name, data[i].spec, data[i].horizontal, data[i].vertical);
		i++;
	}
	
	// 큐 초기화
	queueInit(&_queue);
	queue = &_queue;

	/*for (int i = 0; i < SIZE; i++)
	{
		dataPrint(&data[i]); //데이터 출력(0~15번지 까지)
	}*/
	
	graphInit(&graph, data, SIZE); //그래프 초기화
	//showGraph(&graph);	//그래프 출력

	makeRandomUser(&user);	// 랜덤 좌표 유저
	showUser(&user);		// 유저 위치 출력
	
	//traceEXIT에서 오류 발생 원인 찾아야 함.
	queue = traceEXIT(&graph, &user, queue, routeData, SIZE);	// 현재 유저의 위치를 바탕으로 경로 찾기
	findDirection(&graph, &user, queue);

	printf("현재 User의 위치 x : %d, y : %d\n", user.x, user.y);
	/*while (!qIsEmpty(queue))
	{
		printf("현재 User의 위치에서 탈출구까지의 거리 : %dcm\n", queue->route);
		minRoute = routePeek(queue);
		minIndex = deQueue(queue);
		printf("다음 노드 %c", minIndex + 65);
		if (queue->front == NULL)
		{
			printf("(EXIT 노드(탈출구))");
		}
		printf("\n");
		printf("다음 노드까지의 거리 : %dcm\n", minRoute);
	}*/

	/*while (!qIsEmpty(queue))
	{
		printf("현재 User의 위치 x : %d, y : %d\n", user.x, user.y);
		printf("현재 User의 위치에서 탈출구까지의 거리 : %dcm\n", queue->route);


		for (int i = 0; i < routePeek(queue); i++)
		{
			minRoute = routePeek(queue);
			minIndex = deQueue(queue);

			printf("현재노드 %c\n", minIndex + 65);
			user.x = data[minIndex].x; // 현재노드
			user.y = data[minIndex].y; // 현재노드

			showUser(&user);

			if (queue->front != NULL)
			{
				temp_x = data[queue->front->minIndex].x; // 다음노드
				temp_y = data[queue->front->minIndex].y; // 다음노드
				printf("다음 노드 %c\n", (queue->front->minIndex) + 65);
				printf("다음 노드까지의 거리 : %dcm\n", minRoute);
			}



			if (temp_x > user.x && temp_y == user.y)
			{
				while (user.x < temp_x)
				{
					if (user.x++ % 100 == 0)
					{
						printf("user.x = %d\n", user.x);
						Sleep(500);
					}
				}
			}
			else if (temp_x < user.x && temp_y == user.y)
			{
				while (user.x > temp_x)
				{
					if (user.x-- % 100 == 0)
					{
						printf("user.x = %d\n", user.x);
						Sleep(500);
					}
				}
			}
			else if (temp_y > user.y && temp_x == user.x)
			{
				while (user.y < temp_y)
				{
					if (user.y++ % 100 == 0)
					{
						printf("user.y = %d\n", user.y);
						Sleep(500);
					}
				}
			}
			else if (temp_y < user.y && temp_x == user.x)
			{
				while (user.y > temp_y)
				{
					if (user.y-- % 100 == 0)
					{
						printf("user.y = %d\n", user.y);
						Sleep(500);
					}
				}
			}


		}

	}*/

	for (int i = 0; i < routePeek(queue); i++)
	{
		minRoute = routePeek(queue);
		minIndex = deQueue(queue);

		if (user.x > data[minIndex].x)
		{
			while (user.x > data[minIndex].x)
			{
				if (user.x-- % 100 == 0)
				{
					printf("user.x = %d\n", user.x);
					Sleep(500);
				}
			}
		}
		else if (user.x < data[minIndex].x)
		{
			while (user.x < data[minIndex].x)
			{
				if (user.x++ % 100 == 0)
				{
					printf("user.x = %d\n", user.x);
					Sleep(500);
				}
			}
		}
		if (user.x == data[minIndex].x)
		{
			if (user.y > data[minIndex].y)
			{
				while (user.y > data[minIndex].y)
				{
					if (user.y-- % 50 == 0)
					{
						printf("user.y = %d\n", user.y);
						Sleep(500);
					}
				}
			}
			else if (user.y < data[minIndex].y)
			{
				while (user.y < data[minIndex].y)
				{
					if (user.y++ % 50 == 0)
					{
						printf("user.y = %d\n", user.y);
						Sleep(500);
					}
				}

			}
			if (user.y == data[minIndex].y)
			{
				printf("현재노드 %c\n", minIndex + 65);
				user.x = data[minIndex].x; // 현재노드
				user.y = data[minIndex].y; // 현재노드

			}
		}



		//showUser(&user);

		if (queue->front != NULL)
		{
			temp_x = data[queue->front->minIndex].x; // 다음노드
			temp_y = data[queue->front->minIndex].y; // 다음노드
			printf("다음 노드 %c\n", (queue->front->minIndex) + 65);
			printf("다음 노드까지의 거리 : %dcm\n", minRoute);
		}



		if (temp_x > user.x && temp_y == user.y)
		{
			while (user.x < temp_x)
			{
				if (user.x++ % 100 == 0)
				{
					printf("user.x = %d\n", user.x);
					Sleep(500);
				}
			}
		}
		else if (temp_x < user.x && temp_y == user.y)
		{
			while (user.x > temp_x)
			{
				if (user.x-- % 100 == 0)
				{
					printf("user.x = %d\n", user.x);
					Sleep(500);
				}
			}
		}
		else if (temp_y > user.y && temp_x == user.x)
		{
			while (user.y < temp_y)
			{
				if (user.y++ % 100 == 0)
				{
					printf("user.y = %d\n", user.y);
					Sleep(500);
				}
			}
		}
		else if (temp_y < user.y && temp_x == user.x)
		{
			while (user.y > temp_y)
			{
				if (user.y-- % 100 == 0)
				{
					printf("user.y = %d\n", user.y);
					Sleep(500);
				}
			}
		}


	}

   


	graphRemove(&graph);	//그래프 삭제
	
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}