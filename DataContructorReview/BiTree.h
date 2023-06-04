#include<math.h>
#include<iostream>
using namespace std;
typedef struct BiTNode { //二叉树
	//char data;
	int data;
	struct BiTNode* l, * r;
}BiTNode,*BiTree;

BiTree createBiSortedTree(int n);//构建二叉排序树 数据域为int

void insertToBiSortedTree(BiTree &T, int val);//向二叉排序树中插入数据 数据域为int

BiTree searchInBiSortedTree(BiTree T, int val);//查找指定值的结点

void deleteNode(BiTree& T, int val);//删除值为val的结点 用中序前驱代替

void InOrderRecursionTraverse(BiTree T); //中序递归遍历二叉树

void InOrderTraverse(BiTree T); //中序非递归遍历二叉树

void CrateBTree(BiTree& T); //前序创建二叉树 数据域为char

void CopyBTree(BiTree T,BiTree &newT); //复制二叉树

int GetHeight(BiTree T); //递归计算二叉树深度

int GetTotalNodes(BiTree T);//统计结点总个数