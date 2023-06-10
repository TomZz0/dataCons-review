#include"BiThrTree.h"

BiThrNode* pre;
void InOrderRecursionTraverse(BiThrTree T) {
	//递归中序遍历 先左 后输出 再右
	if (!T) return;
	InOrderRecursionTraverse(T->l);
	cout << T->data << " ";
	InOrderRecursionTraverse(T->r);
}


void CreateBTree(BiThrTree& T) {
	char ch;
	cin >> ch;
	if (ch == '#') T = NULL;
	else {
		T = new BiThrNode;
		T->data = ch;
		CreateBTree(T->l);
		CreateBTree(T->r);
	}
}
void InThreading(BiThrTree& T) {
	if (!T) return;
	InThreading(T->l);
	if (!T->l) {
		T->LTag = 1;
		T->l = pre;
	}
	else T->LTag = 0;

	if (!pre->r) {
		pre->RTag = 1;
		pre->r = T;
	}
	else pre->RTag = 0;

	pre = T;
	InThreading(T->r);
}

void InOrderThreading(BiThrTree& Thrt, BiThrTree T) {
	Thrt = new BiThrNode;
	Thrt->LTag = 0;   //头节点的左子结点为树的根节点
	Thrt->RTag = 1;  //右子结点为中序遍历的最后一个结点
	Thrt->r = Thrt; // 初始时指向自身
	if (!T)Thrt->l = Thrt;
	else {
		Thrt->l = T;
		pre = Thrt;
		InThreading(T);
		//线索化完毕后pre为最右边的结点
		pre->r = Thrt;
		pre->RTag = 1;
		Thrt->r = pre;
	}
} 

void InOrderTraverse(BiThrTree T) {
	BiThrNode* p = T->l;
	while (p != T) {
		//找到中序遍历的起始结点
		while (p->LTag==0)p = p->l;
		//访问
		cout << p->data << "";
		//当右子节点为后继时 循环访问
		while (p->RTag == 1 && p->r != T) {
			p = p->r;
			cout << p->data << "";
		}
		//不满足时 右移 若还有就循环遍历 否则说明p已经是头节点了 遍历完毕
		p = p->r;

	}
}


void AllPath(BiThrNode* b, char path[], int pathlen)
{
	int i;
	if (b != NULL)
	{
		if (b->l== NULL && b->r == NULL) //*b为叶子结点
		{
			cout << " " << b->data << "到根结点路径:" << b->data;
			for (i = pathlen - 1; i >= 0; i--)
				cout << path[i]<<endl;
		}
		else
		{
			path[pathlen] = b->data;           //将当前结点放入路径中
			pathlen++;                     //路径长度增1
			AllPath(b->l, path, pathlen);   //递归扫描左子树
			AllPath(b->r, path, pathlen);   //递归扫描右子树
			                    //恢复环境
		}
	}// if (b!=NULL)
}//算法结束