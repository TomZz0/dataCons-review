#include"Stack.h"

Status InitStack(SqStack& S) {
	//��ʼ��ջ
	S.base = new int[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base; 
	S.StackSize = MAXSIZE;

	return OK;
}

Status Push(SqStack& S,int val) {
	if (S.top - S.base == S.StackSize) return ERROR; //ջ����
	*S.top++ = val; //ջ��ָ���ƶ� �ȸ�ֵ ���ƶ� 
	return OK;
}

Status Pop(SqStack& S, int& e) {
	if (S.base == S.top) return ERROR;
	e = *(--S.top);
	return OK;
}


int GetTop(SqStack& S) {
	if (S.base != S.top)//����ջ��Ԫ��
		return *(S.top-1);
}