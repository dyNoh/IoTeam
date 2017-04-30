#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeRandomUser(User * user)
{
	srand((unsigned int)time(NULL));
	rand();	// 한번 낭비하여 시간순서대로 안나오게 함
	user->x = rand() % MAX_X + 1;
	user->y = rand() % MAX_Y + 1;
	user->horizontal = PRECISION;
	user->vertical = PRECISION;
}

void showUser(User * user)
{
	printf("user X : %d\n", user->x);
	printf("user Y : %d\n", user->y);
}