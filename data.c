#include <stdio.h>
#include "data.h"

void dataInit(Data * d, int x, int y, int name,
	int spec, int horizontal, int vertical)
{
	d->x = x;
	d->y = y;
	d->name = name;
	d->spec = spec;
	d->horizontal = horizontal;
	d->vertical = vertical;
}

void dataPrint(Data * d)
{
	printf("===============\n");
	printf("name : %c\n", d->name + 65);
	switch (d->spec)
	{
	case NODE:
		printf("type : NODE\n");
		break;
	case BEACON:
		printf("type : BEACON\n");
		break;
	case USER:
		printf("type : USER\n");
		break;
	case EXIT:
		printf("type : EXIT\n");
		break;
	default:
		printf("type : \n");
	}
	printf("x : %d\n", d->x);
	printf("y : %d\n", d->y);
	printf("horizontal : %d\n", d->horizontal);
	printf("vertical : %d\n", d->vertical);
	printf("===============\n\n");
}