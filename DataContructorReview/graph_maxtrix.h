/*
* ʹ���ڽӾ����ʾ����ͼ
*/
#include"status.h"
#include<iostream>
using namespace std;
#define MaxInt 32767 //��ʾ���뼫��
#define MVNum 100   //��ʾ��󶥵���
typedef struct {
	char vexes[MVNum]; //�����
	int arcs[MVNum][MVNum]; //�ڽӾ���
	int vexnum, arcnum;//����������ߵĸ���
}AMGraph;

Status createUDN(AMGraph& G); // ��������ͼ

int LocateVex(AMGraph G, char v1);//��λ����λ��

void AMG_DFS(AMGraph G,int v); //������ȱ�������ͼ

void AMG_DFS_PRE(AMGraph G, int v); //������ȱ�������ͼ

void showMatrix(AMGraph G);//��ӡ����