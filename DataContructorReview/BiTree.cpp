#include"BiTree.h"

void InOrderRecursionTraverse(BiTree T) {
	//递归中序遍历 先左 后输出 再右
	if (!T) return;
	InOrderRecursionTraverse(T->l);
	cout << T->data << " ";
	InOrderRecursionTraverse(T->r);
}

void InOrderTraverse(BiTree T) {
	//非递归中序遍历树 需要使用存储树结点的栈 只给代码
	//StackCreate(S);
	//BiTNode* p = T; //当前结点
	//BiTNode* q = NULL; //用于接收出栈的元素
	//while (p || !EmptyStack(S)) {
	//	if (p) {
	//		//非空 入栈 左移
	//		Push(S, p);
	//		p = p->l;
	//	}
	//	else {
	//		//为空 输出 右移
	//		Pop(S, q);
	//		cout << q->data;
	//		p = q->r;
	//	}
	//}
}

void CrateBTree(BiTree& T) {
	char ch;
	cin >> ch;
	//输入# 说明为null
	if (ch == '#') T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CrateBTree(T->l);
		CrateBTree(T->r);
	}
}

void CopyBTree(BiTree T, BiTree& newT) {
	if (T == NULL) {
		newT = NULL;
	}
	else {
		newT = new BiTNode;
		newT->data = T->data;
		CopyBTree(T->l, newT->l);
		CopyBTree(T->r, newT->r);
	}
}

int GetHeight(BiTree T) {
	if (!T) return 0;
	else return max(GetHeight(T->l), GetHeight(T->r))+1;
}


int GetTotalNodes(BiTree T) {
	if (!T) return 0;
	else return 1 + GetTotalNodes(T->l) + GetTotalNodes(T->r);
}

BiTree createBiSortedTree(int n) {
	BiTree T = NULL;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		insertToBiSortedTree(T, val);
	}
	return T;
}

void insertToBiSortedTree(BiTree &T, int val) {
	//向二叉排序树中插入数据
	if (!T) {
		BiTNode* p = new BiTNode;
		p->data = val;
		p->l = p->r = NULL;
		T = p;
		return;
	}
	if (T->data < val) insertToBiSortedTree(T->r, val);
	else insertToBiSortedTree(T->l, val);
}

BiTree searchInBiSortedTree(BiTree T, int val) {
	if (!T || T->data == val) return T;
	return T->data > val ? 
		searchInBiSortedTree(T->l, val) : searchInBiSortedTree(T->r, val);
}

void deleteNode(BiTree& T, int val) {
	//删除值为val的结点 用中序前驱替代 
	BiTNode* father = T;
	BiTNode* toBeDeleted = T;
	while (toBeDeleted && toBeDeleted->data != val) {
		father = toBeDeleted;
		if (toBeDeleted->data > val) toBeDeleted = toBeDeleted->l;
		else toBeDeleted = toBeDeleted->r;
	}
	if (!toBeDeleted) {
		cout << "值为" << val << "的结点不存在";
		return;
	}
	//如果是叶子结点 直接删除即可
	if (toBeDeleted->l == NULL && toBeDeleted->r == NULL) {
		if (toBeDeleted == father->l) father->l = NULL;
		else father->r = NULL;
		return;
	}
	//如果要删除的结点只有一个孩子 直接令其替代要删除的结点
	if (toBeDeleted->l == NULL) {
		if (toBeDeleted == father->l) father->l = toBeDeleted->r;
		else father->r = toBeDeleted->r;
		return;
	}
	else if(toBeDeleted->r == NULL){ 
		if (toBeDeleted == father->l) father->l = toBeDeleted->l;
		else father->r = toBeDeleted->l;
		return;
	}
	//如果被删除的结点 有两个孩子 用其前驱结点代替 注释的为后继替代
	BiTNode* preOfInOrder = toBeDeleted->l;
	BiTNode* preFather = toBeDeleted;
	while (preOfInOrder->r) {  //preOfInOrder->l
		preFather = preOfInOrder;
		preOfInOrder = preOfInOrder->r; //preOfInOrder =preOfInOrder->l
	}
	//1如果preFather==toBeDelete 说明要删除结点的左结点没有右结点 即其左节点就是直接前驱
	//其直接前驱一定是没有右节点的 要把preFather的左或右设置为preOfInorder的左节点
	//左或右取决于preOfInOrder是否就是toBeDelete的左结点 
	//2 如果是使用中序后继 则其直接后继一定没有左子结点 操作类似
	toBeDeleted->data = preOfInOrder->data;
	if (preFather == toBeDeleted) {
		preFather->l = preOfInOrder->l;  //preFather->r = preOfInOrder->r;
	}else{
		preFather->r = preOfInOrder->l;  //preFather->l = preOfInOrder->r;
	}
	delete preOfInOrder;
}