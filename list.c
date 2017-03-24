#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define Size 10


void listInit(List *list)		// 리스트의 초기화
{
	list->head = (Node*)malloc(sizeof(Node));	// 더미 노드 생성
	list->head->next = NULL;
	list->numOfData = 0;
}

void LInsert(List *list, Data *d)	// 노드 생성
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
	if (list->cur != NULL)	//  아무 데이터도 없을 경우 예외처리
	{
		printf("%c", list->cur->data->name + 65);
		while (list->cur->next != NULL)
		{
			list->cur = list->cur->next;
			printf(" -> %c", list->cur->data->name + 65);
		}
		printf("\t\t총 %d개", list->numOfData);
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
