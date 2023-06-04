#include"BiTree.h"

void InOrderRecursionTraverse(BiTree T) {
	//�ݹ�������� ���� ����� ����
	if (!T) return;
	InOrderRecursionTraverse(T->l);
	cout << T->data << " ";
	InOrderRecursionTraverse(T->r);
}

void InOrderTraverse(BiTree T) {
	//�ǵݹ���������� ��Ҫʹ�ô洢������ջ ֻ������
	//StackCreate(S);
	//BiTNode* p = T; //��ǰ���
	//BiTNode* q = NULL; //���ڽ��ճ�ջ��Ԫ��
	//while (p || !EmptyStack(S)) {
	//	if (p) {
	//		//�ǿ� ��ջ ����
	//		Push(S, p);
	//		p = p->l;
	//	}
	//	else {
	//		//Ϊ�� ��� ����
	//		Pop(S, q);
	//		cout << q->data;
	//		p = q->r;
	//	}
	//}
}

void CrateBTree(BiTree& T) {
	char ch;
	cin >> ch;
	//����# ˵��Ϊnull
	if (ch == '#') T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CrateBTree(T->l);
		CrateBTree(T->r);
	}
}

void CopyBTree(BiTree T, BiTree& newT) {
	if (T == NULL) {
		newT = NULL;
	}
	else {
		newT = new BiTNode;
		newT->data = T->data;
		CopyBTree(T->l, newT->l);
		CopyBTree(T->r, newT->r);
	}
}

int GetHeight(BiTree T) {
	if (!T) return 0;
	else return max(GetHeight(T->l), GetHeight(T->r))+1;
}


int GetTotalNodes(BiTree T) {
	if (!T) return 0;
	else return 1 + GetTotalNodes(T->l) + GetTotalNodes(T->r);
}

BiTree createBiSortedTree(int n) {
	BiTree T = NULL;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		insertToBiSortedTree(T, val);
	}
	return T;
}

void insertToBiSortedTree(BiTree &T, int val) {
	//������������в�������
	if (!T) {
		BiTNode* p = new BiTNode;
		p->data = val;
		p->l = p->r = NULL;
		T = p;
		return;
	}
	if (T->data < val) insertToBiSortedTree(T->r, val);
	else insertToBiSortedTree(T->l, val);
}

BiTree searchInBiSortedTree(BiTree T, int val) {
	if (!T || T->data == val) return T;
	return T->data > val ? 
		searchInBiSortedTree(T->l, val) : searchInBiSortedTree(T->r, val);
}

void deleteNode(BiTree& T, int val) {
	//ɾ��ֵΪval�Ľ�� ������ǰ����� 
	BiTNode* father = T;
	BiTNode* toBeDeleted = T;
	while (toBeDeleted && toBeDeleted->data != val) {
		father = toBeDeleted;
		if (toBeDeleted->data > val) toBeDeleted = toBeDeleted->l;
		else toBeDeleted = toBeDeleted->r;
	}
	if (!toBeDeleted) {
		cout << "ֵΪ" << val << "�Ľ�㲻����";
		return;
	}
	//�����Ҷ�ӽ�� ֱ��ɾ������
	if (toBeDeleted->l == NULL && toBeDeleted->r == NULL) {
		if (toBeDeleted == father->l) father->l = NULL;
		else father->r = NULL;
		return;
	}
	//���Ҫɾ���Ľ��ֻ��һ������ ֱ���������Ҫɾ���Ľ��
	if (toBeDeleted->l == NULL) {
		if (toBeDeleted == father->l) father->l = toBeDeleted->r;
		else father->r = toBeDeleted->r;
		return;
	}
	else if(toBeDeleted->r == NULL){ 
		if (toBeDeleted == father->l) father->l = toBeDeleted->l;
		else father->r = toBeDeleted->l;
		return;
	}
	//�����ɾ���Ľ�� ���������� ����ǰ�������� ע�͵�Ϊ������
	BiTNode* preOfInOrder = toBeDeleted->l;
	BiTNode* preFather = toBeDeleted;
	while (preOfInOrder->r) {  //preOfInOrder->l
		preFather = preOfInOrder;
		preOfInOrder = preOfInOrder->r; //preOfInOrder =preOfInOrder->l
	}
	//1���preFather==toBeDelete ˵��Ҫɾ����������û���ҽ�� ������ڵ����ֱ��ǰ��
	//��ֱ��ǰ��һ����û���ҽڵ�� Ҫ��preFather�����������ΪpreOfInorder����ڵ�
	//�����ȡ����preOfInOrder�Ƿ����toBeDelete������ 
	//2 �����ʹ�������� ����ֱ�Ӻ��һ��û�����ӽ�� ��������
	toBeDeleted->data = preOfInOrder->data;
	if (preFather == toBeDeleted) {
		preFather->l = preOfInOrder->l;  //preFather->r = preOfInOrder->r;
	}else{
		preFather->r = preOfInOrder->l;  //preFather->l = preOfInOrder->r;
	}
	delete preOfInOrder;
}