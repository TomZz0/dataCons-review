#include"graph_maxtrix.h"


Status createUDN(AMGraph& G) {
	//采用邻接矩阵表示法创建无向图
	cout << "请输入总定点数和总边数:"; 
	cin >> G.vexnum >> G.arcnum; //输入总顶点数 总边数

	for (int i = 0; i < G.vexnum; i++) {  //装点
		cin >> G.vexes[i];
	}

	for (int i = 0; i < G.vexnum; i++) {  //初始化顶点距离为无穷大
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = 0;
		}
	}

	//依次输入顶点和之间边的大小 构建邻接矩阵
	for (int i = 0; i < G.arcnum; i++) {
		int pos1, pos2 = 0;
		char v1, v2 = '\0';
		cin >> v1 >> v2;
		pos1 = LocateVex(G, v1);
		pos2 = LocateVex(G, v2);
		G.arcs[pos1][pos2] = G.arcs[pos2][pos1] = 1;
	}
	return OK; 
}

int LocateVex(AMGraph G, char v1) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexes[i] == v1) return i;
	return -1;
}
bool visited[MVNum]; // 保存顶点是否已访问

void initialVisited() {
	for (int i = 0; i < MVNum; i++) visited[i] = false;
}

void AMG_DFS_PRE(AMGraph G, int v) {
	initialVisited();
	AMG_DFS(G, v);
}

void AMG_DFS(AMGraph G,int v) {
	cout << G.vexes[v]; visited[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		//边值为零 说明不相邻 
		if (G.arcs[v][w] != 0 && !visited[w])
			AMG_DFS(G, w);
	}
}

void showMatrix(AMGraph G) {
	for (int i = 0; i < G.vexnum; i++) {  
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.arcs[i][j]<<" ";
		}
		cout << "\n";
	}
}