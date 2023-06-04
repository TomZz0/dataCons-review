#pragma once
#include"status.h"
#include<iostream>
using namespace std;
typedef struct LNode {
	int val;
	struct LNode* next;
}LNode,*LinkedList;

Status InitLinkedList(LinkedList& L); //��ʼ������

Status GetElem(LinkedList& L, int i, int& e);//��ȡ��i�����������

LNode* LocateElem(LinkedList L, int e); //��ȡ����Ϊe�Ľ��

Status InsertElem(LinkedList& L, int i, int e); //�ڵ�i��λ�ò���e

Status DeleteElem(LinkedList& L, int i);//ɾ����i��Ԫ��

Status InsertFront(LinkedList& L, int n);//ǰ�巨����n��Ԫ��

Status InsertBack(LinkedList& L, int n);//β�巨��������

void ShowList(LinkedList L);