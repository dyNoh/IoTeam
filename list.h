#pragma once

#include "data.h"

#define TRUE 1
#define FALSE 0

typedef struct _list
{
	struct _node *head;			// ���
	struct _node *before;		// ������
	struct _node *cur;			// �˻���
	
	struct _data *listData;		// listData�� list ��ü�� ���� ǥ��
	int numOfData;				// ����� ����� ����
}List;

typedef struct _node
{
	struct _data *data;
	struct _node *next;
}Node;

void listInit(List *list, Data *data, int num);		// ����Ʈ�� �ʱ�ȭ
void LInsert(List *list, Data *d);					// ��� ����
void showList(List *list);							// ����Ʈ ���
Node* findFList(List *list);						// ����Ʈ ã��(ó��)
Node* findNList(List *list);						// ����Ʈ ã��(����)
void LRemove(List *list);						// ����Ʈ ��� ����