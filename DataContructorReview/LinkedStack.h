#include"status.h"
#include<iostream>
using namespace std;
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;

Status InitLinkStack(LinkStack& l);//��ʼ����ջ

Status Push(LinkStack& l, int val);//��ջ

Status Pop(LinkStack& l, int &e);//��ջ

int GetTop(LinkStack& l);//ȡջ��