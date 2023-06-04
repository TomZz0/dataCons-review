#include"SqList.h"


Status InitList(SqList& L) {
	//初始化顺序表
	L.elem = new int[MAXSIZE];
	//存储分配失败 退出程序
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 0;

	return OK;
}

Status GetElem(SqList L, int i, int& e) {
	// 判断i是否合法
	if (i < 1 || i > L.length) return ERROR;
	//赋值
	e = L.elem[i-1];

	return OK;
}

int LocateElem(SqList L, int e) {
	//寻找值为e的元素
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;
		else return 0;
}
Status InsertElem(SqList& L, int i, int e) {
	//插入元素
	int index = i - 1;
	//判断是否可插
	if (index < 0 || index > L.length) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	//元素后移
	for (int j = L.length; j > index; j--) {
		L.elem[j] = L.elem[j - 1];
	}

	L.elem[index] = e;
	L.length++;
	return OK;
}


Status DeleteElem(SqList& L, int i) {
	//删除第i个元素
	int index = i - 1;
	if (index<0 || index > L.length - 1||L.length<1) return ERROR;

	for (; index < L.length - 1; index++) L.elem[index] = L.elem[index + 1];

	L.length--;

	return OK;
}

void ShowList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	}
}