#include"SqList.h"

int main_1() {
	SqList l;
	InitList(l);
	for (int i = 0; i < 10; i++) {
		InsertElem(l, i + 1, i * 2);
	}
	ShowList(l);
	DeleteElem(l, 4);
	ShowList(l);
    return 0;
}