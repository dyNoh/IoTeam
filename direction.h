#pragma once

#include "graph.h"
#include "user.h"
#include "queue.h"

#define LEFT 222
#define RIGHT -222
#define UP 333
#define DOWN -333

typedef struct move
{
	int direction;	// 방향
	int distance;	// 거리
}Move;

void findDirection(Graph * graph, User * user, Queue *queue);