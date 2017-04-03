#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void listInit(List *list, Data *data, int num)		// ����Ʈ�� �ʱ�ȭ
{
	list->head = (Node*)malloc(sizeof(Node));	// ���� ��� ����
	list->head->next = NULL;
	list->numOfData = 0;
	list->listData = data;						// ������ �ʱ�ȭ
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
