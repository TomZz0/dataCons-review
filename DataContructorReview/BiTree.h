#include<math.h>
#include<iostream>
using namespace std;
typedef struct BiTNode { //������
	//char data;
	int data;
	struct BiTNode* l, * r;
}BiTNode,*BiTree;

BiTree createBiSortedTree(int n);//�������������� ������Ϊint

void insertToBiSortedTree(BiTree &T, int val);//������������в������� ������Ϊint

BiTree searchInBiSortedTree(BiTree T, int val);//����ָ��ֵ�Ľ��

void deleteNode(BiTree& T, int val);//ɾ��ֵΪval�Ľ�� ������ǰ������

void InOrderRecursionTraverse(BiTree T); //����ݹ����������

void InOrderTraverse(BiTree T); //����ǵݹ����������

void CrateBTree(BiTree& T); //ǰ�򴴽������� ������Ϊchar

void CopyBTree(BiTree T,BiTree &newT); //���ƶ�����

int GetHeight(BiTree T); //�ݹ������������

int GetTotalNodes(BiTree T);//ͳ�ƽ���ܸ���