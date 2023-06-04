#include"Stack.h"
int main3() {
	SqStack q;
	InitStack(q);
	Push(q, 1);
	Push(q, 2);
	Push(q, 3);
	int x = 0;
	Pop(q, x);
	cout << "x=" << x;
	cout << "\ntop=" << GetTop(q);
	return 0;
}