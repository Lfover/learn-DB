#include "BinSearchTree.h"

int main()
{
	BSTree bst;
	BinSearchTreeInit(&bst);
	ElemType a[] = { 5, 10, 15, 20, 25, 30, 35 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		BinSearchTreeInsert(&bst, a[i]);
	}
	BinSearchTreeInsert(&bst, 50);
	BinSearchTree *p = BinSearchTreeFind(bst, 30);
	//BinSearchTreeDel(&bst, p);
	BinSearchTreeChange(&bst, p, 11);
	system("pause");
	return 0;
}