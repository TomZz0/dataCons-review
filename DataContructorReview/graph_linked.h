#include"Status.h"
#include<iostream>
using namespace std;
#define MVNum 100

typedef struct ArcNode{ //�߽��
	int to;
	struct ArcNode* nextArc;
}ArcNode;

typedef struct VNode { //����
	char data;
	ArcNode* firstArc; // ��һ���߽��
}VNode,AdjList[MVNum];  //�ڽӱ�ı� �洢����

typedef struct {   //�ڽӱ�
	AdjList vexes;  //��
	int vexnum, arcnum;  //����ͱߵĸ���
}ALGraph;

Status createUDG(ALGraph& G);//��������ͼ

int LocateVex(ALGraph G, char v1);//��λ����λ��

void DFS(ALGraph G, int start);//��start��ʼ������ȱ���

void DFS_AL(ALGraph G, int start);//������ȱ�������ʵ��
