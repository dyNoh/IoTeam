#pragma once

#define TRUE 1
#define FALSE 0

enum { A, B, C, D, E, F, G, H, I, J }; // name

typedef struct _list
{
	struct _node *head;
	struct _node *before;
	struct _node *cur;

	int numOfData;	//������ ����
}List;

typedef struct _node
{
	struct _data *data;
	struct _node *next;
}Node;

typedef struct _data
{
	int x;
	int y;
	int name;
}Data;

void listInit(List *list);									// ����Ʈ�� �ʱ�ȭ
void LInsert(List *list, Data *d);							// ��� ����
void showList(List *list);									// ����Ʈ ���
void dataInit(Data *d, int x, int y, int name);			// ��ǥ�� �ʱ�ȭ
void dataPrint(Data *d);