#pragma once
#include<iostream>
using namespace std;
//������������
typedef struct BiThrNode {
	char data;
	struct BiThrNode* l, * r;
	int LTag, RTag;
}BiThrNode,*BiThrTree;


void CrateBTree(BiThrTree & T); //ǰ�򴴽�������

void InOrderRecursionTraverse(BiThrTree T); //����ݹ����������

void InThreading(BiThrTree& T);//������

void InOrderThreading(BiThrTree& Thrt, BiThrTree T);//���ͷ�ڵ㣬��������������

void InOrderTraverse(BiThrTree T);//���������������Ķ�����