/*
* 使用邻接矩阵表示无向图
*/
#include"status.h"
#include<iostream>
using namespace std;
#define MaxInt 32767 //表示距离极大
#define MVNum 100   //表示最大顶点数
typedef struct {
	char vexes[MVNum]; //顶点表
	int arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum;//顶点个数，边的个数
}AMGraph;
typedef struct {
	int length;//长度
	int prevex;//前驱顶点
}Path;
Status createUDN(AMGraph& G); // 创建无向图

int LocateVex(AMGraph G, char v1);//定位顶点位置

void AMG_DFS(AMGraph G,int v); //深度优先遍历无向图

void AMG_DFS_PRE(AMGraph G, int v); //深度优先遍历无向图

void showMatrix(AMGraph G);//打印矩阵

void initial(AMGraph& G, Path dist[] );//迪杰斯特拉前的初始化

void dijkstra(AMGraph& G, Path dist[] );//迪杰斯特拉算法 寻找最短路径