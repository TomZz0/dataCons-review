#include"SqList.h"


Status InitList(SqList& L) {
	//��ʼ��˳���
	L.elem = new int[MAXSIZE];
	//�洢����ʧ�� �˳�����
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 0;

	return OK;
}

Status GetElem(SqList L, int i, int& e) {
	// �ж�i�Ƿ�Ϸ�
	if (i < 1 || i > L.length) return ERROR;
	//��ֵ
	e = L.elem[i-1];

	return OK;
}

int LocateElem(SqList L, int e) {
	//Ѱ��ֵΪe��Ԫ��
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;
		else return 0;
}
Status InsertElem(SqList& L, int i, int e) {
	//����Ԫ��
	int index = i - 1;
	//�ж��Ƿ�ɲ�
	if (index < 0 || index > L.length) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	//Ԫ�غ���
	for (int j = L.length; j > index; j--) {
		L.elem[j] = L.elem[j - 1];
	}

	L.elem[index] = e;
	L.length++;
	return OK;
}


Status DeleteElem(SqList& L, int i) {
	//ɾ����i��Ԫ��
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