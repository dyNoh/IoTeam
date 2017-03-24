#pragma once

#define TRUE 1
#define FALSE 0

enum { A, B, C, D, E, F, G, H, I, J }; // name

typedef struct _list
{
	struct _node *head;
	struct _node *before;
	struct _node *cur;

	int numOfData;	//데이터 개수
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

void listInit(List *list);									// 리스트의 초기화
void LInsert(List *list, Data *d);							// 노드 생성
void showList(List *list);									// 리스트 출력
void dataInit(Data *d, int x, int y, int name);			// 좌표의 초기화
void dataPrint(Data *d);