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
	Node *newNode = (Node*)malloc(sizeof(Node)); //새로운 노드 할당
	newNode->data = d; //새 노드의 데이터

	newNode->next = list->head->next;
	list->head->next = newNode;

	(list->numOfData)++; //연결된 노드의 갯수 증가
}

void showList(List *list)
{
	list->cur = list->head->next;
	if (list->cur != NULL)	//  아무 데이터도 없을 경우 예외처리
	{
		printf("%c", list->cur->data->name + 65);	//노드이름 표현을 위해 ASCII코드 번호 65를 더해줌 
		while (list->cur->next != NULL)	//다음 주소값이 null이 아닐 때까지
		{
			list->cur = list->cur->next; //다음 노드로 이동
			printf(" -> %c", list->cur->data->name + 65); //노드이름 출력
		}
		printf("\t\t총 %d개", list->numOfData); //연결된 노드의 갯수 출력
	}
	printf("\n");
}

Node * findFList(List * list) //리스트 찾기(처음)
{
	list->before = list->head;	//리스트의 헤드노드 값을 전 노드값으로 변경
	list->cur = list->head->next;	//헤드노드의 다음주소값을 현재주소값으로 변경
	return list->cur;	//현재 노드 반환
}

Node * findNList(List * list) //리스트 찾기(다음)
{
	list->before = list->cur;	//현재노드값을 전노드값으로 변경
	list->cur = list->cur->next;	//현재노드의 다음주소값을 현재노드값으로 변경
	return list->cur;	//현재 노드 반환
}

void LRemove(List * list)	//리스트 노드 삭제
{
	Node *pos = list->cur;	//현재 노드를 새로운 노드에 삽입
	list->before->next = list->cur->next; //현재 노드의 다음주소값을 전 노드값의 다음주소값으로 변경
	list->cur = list->before;	//전 노드값을 현재 노드값으로 변경

	free(pos);	//메모리 동적할당 해제
	(list->numOfData)--;	//연결된 노드의 갯수 감소
}
