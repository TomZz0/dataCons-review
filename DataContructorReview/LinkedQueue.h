#pragma once
#include"status.h"
#include<iostream>
using namespace std;
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr head;
	QueuePtr rear;
}LinkQueue;

Status InitLinkQueue(LinkQueue& q); //初始化

Status EnQueue(LinkQueue& q, int val);//入队

Status DeQueue(LinkQueue& q, int &val);//出队