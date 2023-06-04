#include"graph_maxtrix.h"
void main_graph_maxtrix() {
	AMGraph G{};
	createUDN(G);
	showMatrix(G);
	AMG_DFS_PRE(G, 0);
}