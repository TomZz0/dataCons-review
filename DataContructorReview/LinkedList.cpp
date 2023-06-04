#include"LinkedList.h"
Status InitLinkedList(LinkedList& L) {
	L = new LNode; //ͷ�ڵ�
	if (!L) exit(OVERFLOW);
	L->next = NULL;//�ÿ�
	return OK;
}

Status GetElem(LinkedList& L, int i, int& e) {
	int j = 0;
	LNode* p = L->next;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j >= i - 1) return ERROR;
	
	e = p->val;
	return OK;
}

LNode* LocateElem(LinkedList L, int e) {
	//��������Ϊe�Ľ��
	LNode* p = L->next;
	                            
	while (&p && p->val != e)p = p->next;

    return p;
}

Status InsertElem(LinkedList& L, int i, int e) {
	LNode* r = L;
	int j = 0;
	//��λ
	while (r && j < i - 1) {
		r = r->next;												
		j++;
	}
	if (!r || j > i) return ERROR;
	//�����½ڵ�
	LNode* node = new LNode;
	node->val = e;
	//����ָ����
	node->next = r->next;
	r->next = node;

	return OK;
}

Status DeleteElem(LinkedList& L, int i) {
	//ɾ��Ԫ��
	LNode* p = L;
	int j = 0;
	//��λ
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	//λ�ò��Ϸ�
	if (!p->next || j > i - 1) return ERROR;
	//ɾ�����ͷſռ�
	LNode* q = p->next;
	p->next = q->next;
	delete(q);
	return OK;

}

Status InsertFront(LinkedList& L, int n) {
	//ǰ�巨��������
	L = new LNode;
	L->next = NULL;
	if (n <= 0) return ERROR;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		p->next = L->next;
		cin >> p->val;
		L->next = p;
	}
	return OK;
}

Status InsertBack(LinkedList& L, int n) {
	//β�巨��������
	L = new LNode;
	L->next = NULL;
	if (n <= 0) return ERROR;
	LNode* b = L;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		p->next = NULL;
		cin >> p->val;
		b->next = p;
		b = b->next;
	}
	return OK;
}

void ShowList(LinkedList L) {
	LNode* p = L->next;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << "\n";
}