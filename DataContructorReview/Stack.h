#include"status.h"
#define MAXSIZE 100
#include<iostream>
using namespace std;
typedef struct {
	int* base;
	int* top; //topָ��������λ�� ��ջ��Ԫ�ص���һ��λ��
	int StackSize; //ջ���õ��������
}SqStack;

Status InitStack(SqStack& S); //ջ�ĳ�ʼ��

Status Push(SqStack& S,int val); //��ջ

Status Pop(SqStack& S,int &e);//��ջ,Ԫ�طŵ�e��

int GetTop(SqStack& S);//ȡջ��Ԫ�ز�����