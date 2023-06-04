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

Status InitLinkQueue(LinkQueue& q); //��ʼ��

Status EnQueue(LinkQueue& q, int val);//���

Status DeQueue(LinkQueue& q, int &val);//����