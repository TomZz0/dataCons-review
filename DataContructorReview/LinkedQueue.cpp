#include"LinkedQueue.h"
Status InitLinkQueue(LinkQueue& q) {
	q.head = q.rear = new QNode;
	q.head->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue& q, int val) {
	QNode* p = new QNode;
	p->data = val;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& q, int& val) {
	if (q.head == q.rear) return ERROR;
	QNode* p = q.head->next;
	q.head->next = p->next;
	val = p->data;
	if (q.rear == p) q.rear = q.head; 
	delete p;
	return OK;
} 