#include"graph_linked.h"

Status createUDG(ALGraph& G) {
	cout << "�����붥��ͱߵĸ���:";
	cin >> G.vexnum >> G.arcnum;
	//����ÿ������ ���Ѷ���ĵ�һ�����ÿ�
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexes[i].data;
		G.vexes[i].firstArc = NULL;
	}
	//�����
	for (int i = 0; i < G.arcnum; i++) {
		char v1, v2;
		cin >> v1 >> v2;
		int pos1 = LocateVex(G, v1);
		int pos2 = LocateVex(G, v2);
		//��v2���뵽v1�������ͷ��
		ArcNode* arc1 = new ArcNode;
		arc1->to = pos2;
		arc1->nextArc = G.vexes[pos1].firstArc;
		G.vexes[pos1].firstArc = arc1;
		//��v1���뵽v2�������ͷ��
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
	//��ʼ����������
	for (int i = 0; i < G.vexnum; i++) {
		isVisited[i] = false;
	}
	DFS_AL(G, start);
}
void DFS_AL(ALGraph G, int start) {
	//���ʽ��
	cout << G.vexes[start].data;								
	isVisited[start] = true;
	ArcNode* p = G.vexes[start].firstArc;// ȡ�õ�һ���߽��
	while (p) {
		int nextPos = p->to;//ȡ�õ�һ���ڽӵ���±�
		if (!isVisited[nextPos]) DFS_AL(G, nextPos); //���û���� �͵ݹ���ʵ�һ���ڽӵ�
		p = p->nextArc; //����ָ����һ���� �ж���һ���ڽӵ��Ƿ����
	}
}