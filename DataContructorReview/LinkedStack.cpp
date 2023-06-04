#include"LinkedStack.h"

Status InitLinkStack(LinkStack& l) {
	l = NULL;
	return OK;
}

Status Push(LinkStack& l, int val) {
	StackNode* n = new StackNode;
	n->data = val;
	n->next = l;
	l = n;
	return OK;
}

Status Pop(LinkStack& l, int& e) {
	if (l == NULL) return ERROR;
	StackNode* n = l;
	e = n->data;

	l = l->next;
	delete(n);
	
	return OK;
}

int GetTop(LinkStack& l) {
	if (l != NULL)
		return l->data;
}