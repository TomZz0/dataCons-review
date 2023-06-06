	#include"graph_maxtrix.h"


Status createUDN(AMGraph& G) {
	//�����ڽӾ����ʾ����������ͼ
	cout << "�������ܶ��������ܱ���:"; 
	cin >> G.vexnum >> G.arcnum; //�����ܶ����� �ܱ���

	for (int i = 0; i < G.vexnum; i++) {  //װ��
		cin >> G.vexes[i];
	}

	for (int i = 0; i < G.vexnum; i++) {  //��ʼ���������Ϊ�����
		for (int j = 0; j < G.vexnum; j++) {
			if (i == j) G.arcs[i][j] = 0;
			else G.arcs[i][j] = MaxInt;
		}
	}

	//�������붥���֮��ߵĴ�С �����ڽӾ���

	/*��Ȩֵ������ͼ
	for (int i = 0; i < G.arcnum; i++) {
		int pos1, pos2 = 0;
		char v1, v2 = '\0';
		cin >> v1 >> v2;
		pos1 = LocateVex(G, v1);
		pos2 = LocateVex(G, v2);
		G.arcs[pos1][pos2] = G.arcs[pos2][pos1] = 1;
	}*/
	//����ͼ ��Ȩֵ
	for (int i = 0; i < G.arcnum; i++) {
		int pos1, pos2, weight;
		char v1, v2 = '\0';
		cin >> v1 >> v2>> weight;
		pos1 = LocateVex(G, v1);
		pos2 = LocateVex(G, v2);
		G.arcs[pos1][pos2] = weight;
	}
	return OK; 
}

int LocateVex(AMGraph G, char v1) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexes[i] == v1) return i;
	return -1;
}
bool visited[MVNum]; // ���涥���Ƿ��ѷ���

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
		//��ֵΪ�� ˵�������� 
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

void initial(AMGraph& G, Path dist[]) {
	G.arcs[0][0] = 1;
	dist[0].length = 0;
	dist[0].prevex = 0;
	for (int i = 1; i < G.vexnum; i++) {
		dist[i].length = G.arcs[0][i]; //�������ͨ ����Ϊ0
		                              //arcs[i][i]=1˵�����뵽�˶��㼯U�� 
		if (dist[i].length == MaxInt) {
			dist[i].prevex = -1;
		}
		else {
			dist[i].prevex = 0;
		}
	}
}

void dijkstra(AMGraph& G, Path* dist ) {
	initial(G, dist);
	for (int i = 1; i < G.vexnum; i++) {
		int minW = MaxInt; int min = 0;
		for (int j = 1; j < G.vexnum; j++) {
			if (dist[j].length < minW && G.arcs[j][j] == 0) {
				minW = dist[j].length;
				min = j;
			}
		}
		cout <<"������Сֵ�����±�Ϊ:" << minW << " " << min << "\n";
		if (minW == MaxInt) break;//����ͨ
		G.arcs[min][min] = 1;
		for (int j = 1; j < G.vexnum; j++) {
			if (G.arcs[j][j] == 0 && dist[j].length > dist[min].length + G.arcs[min][j]) {
				dist[j].length = dist[min].length + G.arcs[min][j];
				dist[j].prevex = min;
			}
		}
	}
}