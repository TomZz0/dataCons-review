#include"BiThrTree.h"

BiThrNode* pre;
void InOrderRecursionTraverse(BiThrTree T) {
	//�ݹ�������� ���� ����� ����
	if (!T) return;
	InOrderRecursionTraverse(T->l);
	cout << T->data << " ";
	InOrderRecursionTraverse(T->r);
}


void CrateBTree(BiThrTree& T) {
	char ch;
	cin >> ch;
	if (ch == '#') T = NULL;
	else {
		T = new BiThrNode;
		T->data = ch;
		CrateBTree(T->l);
		CrateBTree(T->r);
	}
}
void InThreading(BiThrTree& T) {
	if (!T) return;
	InThreading(T->l);
	if (!T->l) {
		T->LTag = 1;
		T->l = pre;
	}
	else T->LTag = 0;

	if (!pre->r) {
		pre->RTag = 1;
		pre->r = T;
	}
	else pre->RTag = 0;

	pre = T;
	InThreading(T->r);
}

void InOrderThreading(BiThrTree& Thrt, BiThrTree T) {
	Thrt = new BiThrNode;
	Thrt->LTag = 0;   //ͷ�ڵ�����ӽ��Ϊ���ĸ��ڵ�
	Thrt->RTag = 1;  //���ӽ��Ϊ������������һ�����
	Thrt->r = Thrt; // ��ʼʱָ������
	if (!T)Thrt->l = Thrt;
	else {
		Thrt->l = T;
		pre = Thrt;
		InThreading(T);
		//��������Ϻ�preΪ���ұߵĽ��
		pre->r = Thrt;
		pre->RTag = 1;
		Thrt->r = pre;
	}
} 

void InOrderTraverse(BiThrTree T) {
	BiThrNode* p = T->l;
	while (p != T) {
		//�ҵ������������ʼ���
		while (p->LTag==0)p = p->l;
		//����
		cout << p->data << "";
		//�����ӽڵ�Ϊ���ʱ ѭ������
		while (p->RTag == 1 && p->r != T) {
			p = p->r;
			cout << p->data << "";
		}
		//������ʱ ���� �����о�ѭ������ ����˵��p�Ѿ���ͷ�ڵ��� �������
		p = p->r;

	}
}