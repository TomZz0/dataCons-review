#include"status.h"
#define MAXSIZE 100
#include<iostream>
using namespace std;
typedef struct {
	int* base;
	int head;
	int rear;
}SqQueue;

Status InitSqQueue(SqQueue& s); //初始化队列

int Length(SqQueue s);//求循环队列长度

Status EnQueue(SqQueue& s, int val);//入队

Status DeQueue(SqQueue& s, int& e);//出队

int GetHead(SqQueue s);//获取队头元素