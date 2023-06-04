#include"graph_linked.h"

Status createUDG(ALGraph& G) {
	cout << "请输入顶点和边的个数:";
	cin >> G.vexnum >> G.arcnum;
	//键入每个顶点 并把顶点的第一条边置空
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexes[i].data;
		G.vexes[i].firstArc = NULL;
	}
	//键入边
	for (int i = 0; i < G.arcnum; i++) {
		char v1, v2;
		cin >> v1 >> v2;
		int pos1 = LocateVex(G, v1);
		int pos2 = LocateVex(G, v2);
		//将v2插入到v1边链表的头部
		ArcNode* arc1 = new ArcNode;
		arc1->to = pos2;
		arc1->nextArc = G.vexes[pos1].firstArc;
		G.vexes[pos1].firstArc = arc1;
		//将v1插入到v2边链表的头部
		ArcNode* arc2 = new ArcNode;
		arc2->to = pos1;
		arc2->nextArc = G.vexes[pos2].firstArc;
		G.vexes[pos2].firstArc = arc2;
	}
	return OK;
}

int LocateVex(ALGraph G, char v1) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexes[i].data == v1) return i;
	return -1;
}
bool isVisited[MVNum];

void DFS(ALGraph G, int start) {
	//初始化访问数组
	for (int i = 0; i < G.vexnum; i++) {
		isVisited[i] = false;
	}
	DFS_AL(G, start);
}
void DFS_AL(ALGraph G, int start) {
	//访问结点
	cout << G.vexes[start].data;								
	isVisited[start] = true;
	ArcNode* p = G.vexes[start].firstArc;// 取得第一条边结点
	while (p) {
		int nextPos = p->to;//取得第一个邻接点的下标
		if (!isVisited[nextPos]) DFS_AL(G, nextPos); //如果没访问 就递归访问第一个邻接点
		p = p->nextArc; //否则指向下一个边 判断下一个邻接点是否访问
	}
}