#include"status.h"
#include<iostream>
using namespace std;
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;

Status InitLinkStack(LinkStack& l);//初始化链栈

Status Push(LinkStack& l, int val);//入栈

Status Pop(LinkStack& l, int &e);//出栈

int GetTop(LinkStack& l);//取栈顶