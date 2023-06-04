#include"Stack.h"

Status InitStack(SqStack& S) {
	//初始化栈
	S.base = new int[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base; 
	S.StackSize = MAXSIZE;

	return OK;
}

Status Push(SqStack& S,int val) {
	if (S.top - S.base == S.StackSize) return ERROR; //栈已满
	*S.top++ = val; //栈顶指针移动 先赋值 在移动 
	return OK;
}

Status Pop(SqStack& S, int& e) {
	if (S.base == S.top) return ERROR;
	e = *(--S.top);
	return OK;
}


int GetTop(SqStack& S) {
	if (S.base != S.top)//返回栈顶元素
		return *(S.top-1);
}