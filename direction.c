#include "direction.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void findDirection(Graph * graph, User * user, Queue * queue)
{
	Move move;
	User nUser;
	int index, x, y;
	int xT, yT;	// ���� ������ ��ġ�ϴ� �� 1�ϰ�� + 0�ϰ�� -
	int xD, yD;	// ���� ������ ������ ����
	int nxT, nyT; // ������ �̵��ؿ� ����
	int nxD, nyD; // ������ �̵��ؿ� ��
	int nDirection = 0;
	int direction = 0;
	int flag;

	// ������ ����� ��ġ �޴� �Լ� ����ؾ� �Ѵ�.(�ӽ÷� ������ �� �̿�)
	srand((unsigned int)time(NULL));
	rand();	// �ѹ� �����Ͽ� �ð�������� �ȳ����� ��
	flag = rand() % 4;
	switch (flag)
	{
	case 0: // ���������� �̵�
		nUser.x = user->x + 10;
		nUser.y = user->y;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 0\n");
		break;
	case 1: // �������� �̵�
		nUser.x = user->x - 10;
		nUser.y = user->y;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 1\n");
		break;
	case 2: // �Ʒ��� �̵�
		nUser.x = user->x;
		nUser.y = user->y + 10;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 2\n");
		break;
	case 3: // ���� �̵�
		nUser.x = user->x;
		nUser.y = user->y - 10;
		nUser.horizontal = user->horizontal;
		nUser.vertical = user->vertical;
		printf("flag = 3\n");
		break;
	}
	
	nxT = nUser.x - user->x;
	nyT = nUser.y - user->y;
	// ���� ������ ��ġ�� ���� ��
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
		// x�࿡ ���� �̵�
		if (nxD == 1) // ������
		{
			nDirection = RIGHT;
		}
		else // ����
		{
			nDirection = LEFT;
		}
	}
	else
	{
		// y�࿡ ���� �̵�
		if (nyD == 1) // �Ʒ���
		{
			nDirection = DOWN;
		}
		else // ����
		{
			nDirection = UP;
		}
	}


	index = indexPeek(queue);
	x = graph->edgeList[index].listData->x;
	y = graph->edgeList[index].listData->y;

	xT = x - user->x;
	yT = y - user->y;
	// ���� ������ ��ġ�� ���� ��
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
		// x�࿡ ���� �̵�
		if (xD == 1) // ������
		{
			direction = RIGHT;
		}
		else // ����
		{
			direction = LEFT;
		}
	}
	else
	{
		// y�࿡ ���� �̵�
		if (yD == 1) // �Ʒ���
		{
			direction = DOWN;
		}
		else // ����
		{
			direction = UP;
		}
	}

	printf("direction = %d\n", direction);
	printf("nDirection = %d\n", nDirection);

	if (direction == nDirection)
	{
		printf("����\n");
	}
	else if (direction == -nDirection)
	{
		printf("����\n");
	}
	else
	{
		printf("������ or ����\n");
	}

}
