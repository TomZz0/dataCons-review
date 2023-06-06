#include"graph_linked.h"
void main_graph_linked() {
	ALGraph G{};
	createUDG(G);
	DFS(G,0);
}