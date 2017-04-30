#pragma once

#define MAX_X 8826
#define MAX_Y 1866
#define PRECISION 50	// 오차도

typedef struct _user
{
	int x;			// x 좌표
	int y;			// y 좌표
	int horizontal;	// 수평_정밀도
	int vertical;	// 수직_정밀도
}User;

void makeRandomUser(User *user);	// 랜덤 유저 생성

void showUser(User *user);			// 유저 상태 출력