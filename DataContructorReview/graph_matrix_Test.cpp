#include"graph_maxtrix.h"
void main_graph_maxtrix() {
	AMGraph G{};
	createUDN(G);
	//showMatrix(G);
	Path* dist = new Path[G.vexnum];
	dijkstra(G, dist);
	for (int i = 0; i < G.vexnum; i++) {
		cout << dist[i].length << " " << dist[i].prevex<<"\n";
	}
}