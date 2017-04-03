#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void listInit(List *list, Data *data, int num)		// 리스트의 초기화
{
	list->head = (Node*)malloc(sizeof(Node));	// 더미 노드 생성
	list->head->next = NULL;
	list->numOfData = 0;
	list->listData = data;						// 데이터 초기화
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

Node * findFList(List * list)
{
	list->before = list->head;
	list->cur = list->head->next;
	return list->cur;
}

Node * findNList(List * list)
{
	list->before = list->cur;
	list->cur = list->cur->next;
	return list->cur;
}

void LRemove(List * list)
{
	Node *pos = list->cur;
	list->before->next = list->cur->next;
	list->cur = list->before;

	free(pos);
	(list->numOfData)--;
}
