#pragma once

enum { NODE, BEACON, USER, EXIT };							// 종류
enum { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P };	// 이름

// Init mapData (cm)
enum {
	a_x = 106, a_y = 0, a_spec = NODE, a_horizontal = 106, a_vertical = 0,
	b_x = 106, b_y = 904, b_spec = NODE, b_horizontal = 106, b_vertical = 91,
	c_x = 782, c_y = 1, c_spec = NODE, c_horizontal = 96, c_vertical = 0,
	d_x = 662, d_y = 904, d_spec = NODE, d_horizontal = 217, d_vertical = 91,
	e_x = 782, e_y = 904, e_spec = NODE, e_horizontal = 96, e_vertical = 91,
	f_x = 662, f_y = 1735, f_spec = NODE, f_horizontal = 217, f_vertical = 130,
	g_x = 3715, g_y = 1735, g_spec = NODE, g_horizontal = 100, g_vertical = 130,
	h_x = 3715, h_y = 1650, h_spec = NODE, h_horizontal = 100, h_vertical = 215,
	i_x = 3715, i_y = 1284, i_spec = NODE, i_horizontal = 100, i_vertical = 0,
	j_x = 4486, j_y = 1650, j_spec = NODE, j_horizontal = 420, j_vertical = 215,
	k_x = 4486, k_y = 1211, k_spec = EXIT, k_horizontal = 420, k_vertical = 0,
	l_x = 5256, l_y = 1650, l_spec = NODE, l_horizontal = 100, l_vertical = 215,
	m_x = 5256, m_y = 1005, m_spec = NODE, m_horizontal = 100, m_vertical = 0,
	n_x = 5256, n_y = 1735, n_spec = NODE, n_horizontal = 100, n_vertical = 131,
	o_x = 8536, o_y = 1735, o_spec = NODE, o_horizontal = 290, o_vertical = 131,
	p_x = 8536, p_y = 985, p_spec = NODE, p_horizontal = 290, p_vertical = 0
};

typedef struct _data // 데이터
{
	int x;			// x 좌표
	int y;			// y 좌표
	int name;		// 노드 이름
	int spec;		// 노드 종류
	int horizontal;	// 수평
	int vertical;	// 수직
}Data;

void dataInit(Data *d, int x, int y, int name,
	int spec, int horizontal, int vertical);		// 좌표의 초기화
void dataPrint(Data *d);							// 데이터 출력