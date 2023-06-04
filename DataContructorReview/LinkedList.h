#pragma once
#include"status.h"
#include<iostream>
using namespace std;
typedef struct LNode {
	int val;
	struct LNode* next;
}LNode,*LinkedList;

Status InitLinkedList(LinkedList& L); //初始化链表

Status GetElem(LinkedList& L, int i, int& e);//获取第i个与结点的数据

LNode* LocateElem(LinkedList L, int e); //获取数据为e的结点

Status InsertElem(LinkedList& L, int i, int e); //在第i个位置插入e

Status DeleteElem(LinkedList& L, int i);//删除第i个元素

Status InsertFront(LinkedList& L, int n);//前插法插入n个元素

Status InsertBack(LinkedList& L, int n);//尾插法创建链表

void ShowList(LinkedList L);