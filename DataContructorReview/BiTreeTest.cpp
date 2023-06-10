#include"BiThrTree.h"
#include"BiTree.h"
void main() {
	BiThrTree T{};
	CreateBTree(T);
	InOrderRecursionTraverse(T);
	char *path = new char[1024];
	AllPath(T, path, 0);

	/*BiThrTree T,Thrt;
	CrateBTree(T);
	InOrderRecursionTraverse(T);
	InOrderThreading(Thrt, T);
	InOrderTraverse(Thrt);*/
}