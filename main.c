#include <stdio.h>
#include "list.h"
#include "graph.h"

// Init enum
enum { a_x = 0, a_y = 0, b_x = 5, b_y = 5, c_x = 7, c_y = 3, d_x = 9, d_y = 45, e_x = 12, e_y = 88, f_x = 95, f_y = 5, g_x = 3, g_y = 7, h_x = 22, h_y = 26, i_x = 9, i_y = 8, j_x = 12, j_y = 43 };

int main(void)
{
	Data a, b, c, d, e, f, g, h, i, j;
	Graph graph; 
	dataInit(&a, a_x, a_y, A);
	dataInit(&c, b_x, b_y, B);
	dataInit(&d, c_x, c_y, C);
	dataInit(&e, d_x, d_y, D);
	dataInit(&f, e_x, e_y, E);
	dataInit(&g, f_x, f_y, F);
	dataInit(&b, g_x, g_y, G);
	dataInit(&h, h_x, h_y, H);
	dataInit(&i, i_x, i_y, I);
	dataInit(&j, j_x, j_y, J);
	
	dataPrint(&a);
	dataPrint(&c);
	dataPrint(&d);
	dataPrint(&e);
	dataPrint(&f);
	dataPrint(&g);
	dataPrint(&b);
	dataPrint(&h);
	dataPrint(&i);
	dataPrint(&j);

	graphInit(&graph, 10);
	addEdge(&graph, &a, &b);
	addEdge(&graph, &b, &c);
	addEdge(&graph, &c, &d);
	addEdge(&graph, &d, &e);
	addEdge(&graph, &e, &g);
	addEdge(&graph, &f, &g);
	addEdge(&graph, &g, &i);
	addEdge(&graph, &h, &i);
	addEdge(&graph, &i, &j);

	showGraph(&graph);
	graphRemove(&graph);.
	return 0;
}