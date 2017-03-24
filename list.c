#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define Size 10


void listInit(List *list)		// ����Ʈ�� �ʱ�ȭ
{
	list->head = (Node*)malloc(sizeof(Node));	// ���� ��� ����
	list->head->next = NULL;
	list->numOfData = 0;
}

void LInsert(List *list, Data *d)	// ��� ����
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = d;

	newNode->next = list->head->next;
	list->head->next = newNode;

	(list->numOfData)++;
}

void showList(List *list)
{
	list->cur = list->head->next;
	if (list->cur != NULL)	//  �ƹ� �����͵� ���� ��� ����ó��
	{
		printf("%c", list->cur->data->name + 65);
		while (list->cur->next != NULL)
		{
			list->cur = list->cur->next;
			printf(" -> %c", list->cur->data->name + 65);
		}
		printf("\t\t�� %d��", list->numOfData);
	}
	printf("\n");
}

void dataInit(Data * d, int x, int y, int name)
{
	d->x = x;
	d->y = y;
	d->name = name;
}

void dataPrint(Data * d)
{
	printf("x : %d\n", d->x);
	printf("y : %d\n", d->y);
	printf("name : %c\n\n", d->name + 65);
}
