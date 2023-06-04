#include"LinkedList.h"
Status InitLinkedList(LinkedList& L) {
	L = new LNode; //头节点
	if (!L) exit(OVERFLOW);
	L->next = NULL;//置空
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
	//返回数据为e的结点
	LNode* p = L->next;
	                            
	while (&p && p->val != e)p = p->next;

    return p;
}

Status InsertElem(LinkedList& L, int i, int e) {
	LNode* r = L;
	int j = 0;
	//定位
	while (r && j < i - 1) {
		r = r->next;												
		j++;
	}
	if (!r || j > i) return ERROR;
	//创建新节点
	LNode* node = new LNode;
	node->val = e;
	//调整指针域
	node->next = r->next;
	r->next = node;

	return OK;
}

Status DeleteElem(LinkedList& L, int i) {
	//删除元素
	LNode* p = L;
	int j = 0;
	//定位
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	//位置不合法
	if (!p->next || j > i - 1) return ERROR;
	//删除并释放空间
	LNode* q = p->next;
	p->next = q->next;
	delete(q);
	return OK;

}

Status InsertFront(LinkedList& L, int n) {
	//前插法创建链表
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
	//尾插法创建链表
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