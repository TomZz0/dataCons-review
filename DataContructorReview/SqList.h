#pragma once
#include"status.h"
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct {
	int* elem; //基地址
	int length; //长度
}SqList;

Status InitList(SqList& L); //初始化顺序表

Status GetElem(SqList L, int i, int& e);//获取表中第i个元素

int LocateElem(SqList L, int e);//查询第一个值为e的元素的位置

Status InsertElem(SqList& L, int i,int e);//向位置i插入元素e

Status DeleteElem(SqList& L, int i); //删除第i的元素

void ShowList(SqList L);//打印