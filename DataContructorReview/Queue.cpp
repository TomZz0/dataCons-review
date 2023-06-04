#include"Queue.h"

Status InitSqQueue(SqQueue& s) {
	s.base = new int[MAXSIZE];
	if (!s.base)exit(OVERFLOW);
	s.head = s.rear = 0;
	return OK;
}

int Length(SqQueue s) {
	//返回循环队列长度
	return (s.rear + MAXSIZE - s.head) % MAXSIZE;
}

Status EnQueue(SqQueue& s, int val) {
	if( (s.rear+1) % MAXSIZE == s.head)
	if (Length(s) == MAXSIZE) return ERROR;
	s.base[s.rear] =  val;
	s.rear = (s.rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue& s, int& e) {
	if (s.head == s.rear) return ERROR;
	e = s.base[s.rear];
	s.head = (s.head + 1) % MAXSIZE;
	return OK;
}


int GetHead(SqQueue s) {
	if (s.rear != s.head)
		return s.base[s.head];

}