#pragma once
#include"status.h"
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct {
	int* elem; //����ַ
	int length; //����
}SqList;

Status InitList(SqList& L); //��ʼ��˳���

Status GetElem(SqList L, int i, int& e);//��ȡ���е�i��Ԫ��

int LocateElem(SqList L, int e);//��ѯ��һ��ֵΪe��Ԫ�ص�λ��

Status InsertElem(SqList& L, int i,int e);//��λ��i����Ԫ��e

Status DeleteElem(SqList& L, int i); //ɾ����i��Ԫ��

void ShowList(SqList L);//��ӡ