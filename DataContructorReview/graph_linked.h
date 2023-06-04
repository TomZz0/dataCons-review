#include"Status.h"
#include<iostream>
using namespace std;
#define MVNum 100

typedef struct ArcNode{ //边结点
	int to;
	struct ArcNode* nextArc;
}ArcNode;

typedef struct VNode { //顶点
	char data;
	ArcNode* firstArc; // 第一个边结点
}VNode,AdjList[MVNum];  //邻接表的表 存储顶点

typedef struct {   //邻接表
	AdjList vexes;  //表
	int vexnum, arcnum;  //顶点和边的个数
}ALGraph;

Status createUDG(ALGraph& G);//创建无向图

int LocateVex(ALGraph G, char v1);//定位顶点位置

void DFS(ALGraph G, int start);//从start开始深度优先遍历

void DFS_AL(ALGraph G, int start);//深度优先遍历具体实现
