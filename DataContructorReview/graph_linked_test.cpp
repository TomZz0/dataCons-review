#include"graph_linked.h"
void main() {
	ALGraph G{};
	createUDG(G);
	DFS(G,0);
}