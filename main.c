#include <stdio.h>
#include "graph.h"
#include "user.h"
#include "route.h"

#define SIZE 16 
#define _a data[0]
#define _b data[1]
#define _c data[2]
#define _d data[3]
#define _e data[4]
#define _f data[5]
#define _g data[6]
#define _h data[7]
#define _i data[8]
#define _j data[9]
#define _k data[10]
#define _l data[11]
#define _m data[12]
#define _n data[13]
#define _o data[14]
#define _p data[15]

int main(void)
{
	Data data[SIZE];// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
	Graph graph;
	User user;
	int *route;
	int routeData[SIZE][SIZE];
	dataInit(&data[0], a_x, a_y, A, a_spec, a_horizontal, a_vertical);	//데이터 초기화 -> 데이터 구조체, x좌표, y좌표, 노드이름, 노드종류(NODE/BEACON/USER/EXIT), 수평, 수직
	dataInit(&data[1], b_x, b_y, B, b_spec, b_horizontal, b_vertical);
	dataInit(&data[2], c_x, c_y, C, c_spec, c_horizontal, c_vertical);
	dataInit(&data[3], d_x, d_y, D, d_spec, d_horizontal, d_vertical);
	dataInit(&data[4], e_x, e_y, E, e_spec, e_horizontal, e_vertical);
	dataInit(&data[5], f_x, f_y, F, f_spec, f_horizontal, f_vertical);
	dataInit(&data[6], g_x, g_y, G, g_spec, g_horizontal, g_vertical);
	dataInit(&data[7], h_x, h_y, H, h_spec, h_horizontal, h_vertical);
	dataInit(&data[8], i_x, i_y, I, i_spec, i_horizontal, i_vertical);
	dataInit(&data[9], j_x, j_y, J, j_spec, j_horizontal, j_vertical);
	dataInit(&data[10], k_x, k_y, K, k_spec, k_horizontal, k_vertical);
	dataInit(&data[11], l_x, l_y, L, l_spec, l_horizontal, l_vertical);
	dataInit(&data[12], m_x, m_y, M, m_spec, m_horizontal, m_vertical);
	dataInit(&data[13], n_x, n_y, N, n_spec, n_horizontal, n_vertical);
	dataInit(&data[14], o_x, o_y, O, o_spec, o_horizontal, o_vertical);
	dataInit(&data[15], p_x, p_y, P, p_spec, p_horizontal, p_vertical);
	
	for (int i = 0; i < SIZE; i++)
	{
		dataPrint(&data[i]); //데이터 출력(0~15번지 까지)
	}

	graphInit(&graph, data, SIZE); //그래프 초기화
	showGraph(&graph);	//그래프 출력

	makeRandomUser(&user);	// 랜덤 좌표 유저
	showUser(&user);		// 유저 위치 출력
	route = traceEXIT(&graph, &user, SIZE);	// 현재 유저의 위치를 바탕으로 경로 찾기
	showRoute(route, SIZE);	// 찾은 경로 전체 보여줌
	routeDataInit(&graph, routeData, SIZE); // 최단경로 알고리즘 넣기 전 경로 최솟값 초기화
	// 길찾는 알고리즘 삽입(다익스트라)


	graphRemove(&graph);	//그래프 삭제
	return 0;
}