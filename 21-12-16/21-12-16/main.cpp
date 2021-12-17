#include "BTree.h"

void main()
{
	BTree bt;
	BTDataType *s = "ABD##E#H##CF##G##";
	int pi = 0;
	bt = BinaryTreeCreate(s, 8, &pi);
	int count = BinaryTreeSize(bt);
	system("pause");
}