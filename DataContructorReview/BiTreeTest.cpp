#include"BiThrTree.h"
#include"BiTree.h"
void main_bitree() {
	BiTree T = createBiSortedTree(13);
	InOrderRecursionTraverse(T);
	cout << "\n";
	deleteNode(T, 73);
	InOrderRecursionTraverse(T);

	/*BiThrTree T,Thrt;
	CrateBTree(T);
	InOrderRecursionTraverse(T);
	InOrderThreading(Thrt, T);
	InOrderTraverse(Thrt);*/
}