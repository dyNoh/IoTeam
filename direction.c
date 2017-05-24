#include "direction.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void findDirection(Graph * graph, User * user, Queue * queue)
{
	Move move;
	User nUser;
	int index, x, y;
	int xT, yT;	// 현재 유저가 위치하는 값 1일경우 + 0일경우 -
	int xD, yD;	// 현재 유저가 가야할 방향
	int nxT, nyT; // 유저가 이동해온 길이
	int nxD, nyD; // 유저가 이동해온 값
	int nDirection = 0;
	int direction = 0;
	int flag;

	// 유저의 변경된 위치 받는 함수 사용해야 한다.(임시로 임의의 값 이용)
	srand((unsigned int)time(NULL));
	rand();	// 한번 낭비하여 시간순서대로 안나오게 함
	flag = rand() % 4;
	switch (flag)
	{
	case 0: // 오른쪽으로 이동
		nUser.x = user->x + 10;
		nUser.y = user->y;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 0\n");
		break;
	case 1: // 왼쪽으로 이동
		nUser.x = user->x - 10;
		nUser.y = user->y;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 1\n");
		break;
	case 2: // 아래로 이동
		nUser.x = user->x;
		nUser.y = user->y + 10;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 2\n");
		break;
	case 3: // 위로 이동
		nUser.x = user->x;
		nUser.y = user->y - 10;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 3\n");
		break;
	}
	
	nxT = nUser.x - user->x;
	nyT = nUser.y - user->y;
	// 현재 유저의 위치에 대한 식
	if (nxT >= 0)
	{
		nxD = 1;
	}
	else
	{
		nxD = 0;
		nxT = -nxT;
	}

	if (nyT >= 0)
	{
		nyD = 1;
	}
	else
	{
		nyD = 0;
		nyT = -nyT;
	}
	if (nxT >= nyT)
	{
		// x축에 대한 이동
		if (nxD == 1) // 오른쪽
		{
			nDirection = RIGHT;
		}
		else // 왼쪽
		{
			nDirection = LEFT;
		}
	}
	else
	{
		// y축에 대한 이동
		if (nyD == 1) // 아래쪽
		{
			nDirection = DOWN;
		}
		else // 위쪽
		{
			nDirection = UP;
		}
	}


	index = indexPeek(queue);
	x = graph->edgeList[index].listData->x;
	y = graph->edgeList[index].listData->y;

	xT = x - user->x;
	yT = y - user->y;
	// 현재 유저의 위치에 대한 식
	if (xT >= 0)
	{
		xD = 1;
	}
	else
	{
		xD = 0;
		xT = -xT;
	}

	if (yT >= 0)
	{
		yD = 1;
	}
	else
	{
		yD = 0;
		yT = -yT;
	}

	printf("xT = %d, yT = %d\n", xT, yT);
	printf("xD = %d, yD = %d\n", xD, yD);
	printf("nxT = %d, nyT = %d\n", nxT, nyT);
	printf("nxD = %d, nyD = %d\n", nxD, nyD);

	if (xT >= yT)
	{
		// x축에 대한 이동
		if (xD == 1) // 오른쪽
		{
			direction = RIGHT;
		}
		else // 왼쪽
		{
			direction = LEFT;
		}
	}
	else
	{
		// y축에 대한 이동
		if (yD == 1) // 아래쪽
		{
			direction = DOWN;
		}
		else // 위쪽
		{
			direction = UP;
		}
	}

	printf("direction = %d\n", direction);
	printf("nDirection = %d\n", nDirection);

	if (direction == nDirection)
	{
		printf("직진\n");
	}
	else if (direction == -nDirection)
	{
		printf("후진\n");
	}
	else
	{
		printf("오른쪽 or 왼쪽\n");
	}

}
