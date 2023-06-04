#include"status.h"
#define MAXSIZE 100
#include<iostream>
using namespace std;
typedef struct {
	int* base;
	int* top; //top指向待插入的位置 即栈顶元素的上一个位置
	int StackSize; //栈可用的最大容量
}SqStack;

Status InitStack(SqStack& S); //栈的初始化

Status Push(SqStack& S,int val); //入栈

Status Pop(SqStack& S,int &e);//出栈,元素放到e中

int GetTop(SqStack& S);//取栈顶元素并返回