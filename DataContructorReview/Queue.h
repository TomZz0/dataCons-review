#include"status.h"
#define MAXSIZE 100
#include<iostream>
using namespace std;
typedef struct {
	int* base;
	int head;
	int rear;
}SqQueue;

Status InitSqQueue(SqQueue& s); //��ʼ������

int Length(SqQueue s);//��ѭ�����г���

Status EnQueue(SqQueue& s, int val);//���

Status DeQueue(SqQueue& s, int& e);//����

int GetHead(SqQueue s);//��ȡ��ͷԪ��