#pragma once

#include "data.h"

#define TRUE 1
#define FALSE 0

typedef struct _list
{
	struct _node *head;			// 헤드
	struct _node *before;		// 삭제용
	struct _node *cur;			// 검색용
	
	struct _data *listData;		// listData로 list 자체에 정보 표시
	int numOfData;				// 연결된 노드의 갯수
}List;

typedef struct _node
{
	struct _data *data;
	struct _node *next;
}Node;

void listInit(List *list, Data *data, int num);		// 리스트의 초기화
void LInsert(List *list, Data *d);					// 노드 생성
void showList(List *list);							// 리스트 출력
Node* findFList(List *list);						// 리스트 찾기(처음)
Node* findNList(List *list);						// 리스트 찾기(다음)
void LRemove(List *list);						// 리스트 노드 삭제