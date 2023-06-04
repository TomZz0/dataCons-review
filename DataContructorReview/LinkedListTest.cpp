#include"LinkedList.h"

int main2() {
	LinkedList L;
	InsertBack(L, 6);
	ShowList(L);
	DeleteElem(L, 3);
	ShowList(L);
	InsertElem(L, 4, 666);
	ShowList(L);
	return 0;
}