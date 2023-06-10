#pragma once
#include<iostream>
using namespace std;
//线索化二叉树
typedef struct BiThrNode {
	char data;
	struct BiThrNode* l, * r;
	int LTag, RTag;
}BiThrNode,*BiThrTree;


void CreateBTree(BiThrTree & T); //前序创建二叉树

void InOrderRecursionTraverse(BiThrTree T); //中序递归遍历二叉树

void InThreading(BiThrTree& T);//线索化

void InOrderThreading(BiThrTree& Thrt, BiThrTree T);//添加头节点，调用线索化方法

void InOrderTraverse(BiThrTree T);//遍历中序线索化的二叉树

void AllPath(BiThrNode* b, char path[], int pathlen);