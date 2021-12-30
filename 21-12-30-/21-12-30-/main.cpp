#include "bintree.h"

int main()
{
	BTree bt;
	BTree bt1;
	char *str1 = "ABDECFG";
	char *str2 = "DBEAFCG";
	char *str3 = "CFGH";
	char *str4 = "FCGH";
	int n = strlen(str1);
	int m = strlen(str2);
	int i = strlen(str3);
	int j = strlen(str4);
	bt = BinTreeCreate(str1, n, str2, m);
	bt1 = BinTreeCreate(str3, i, str4, j);
	//BinTreeVLR(bt);
	//BinTreeVLR_N(bt);
	//BinTreeLVR_N(bt);
	BinTreeLRV_N(bt);
	printf("\n");
	printf("%d\n",BinTreeHight(bt));
	if (BinTreeSon(bt, bt1))
		printf("ÊÇ\n");
	else
		printf("·ñ\n");
	system("pause");
	return 0;
}