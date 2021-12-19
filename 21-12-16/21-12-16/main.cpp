//#include "BTree.h"
//
//void main()
//{
//	BTree bt;
//	BTDataType *s = "ABD##E#H##CF##G##";
//	int pi = 0;
//	bt = BinaryTreeCreate(s, 8, &pi);
//	int count = BinaryTreeSize(bt);
//	system("pause");
//}

#include <stdio.h>;

void main()
{
	int i, a[10];
	int max, min;

	printf("请输入10个成绩:\n");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	max = a[0];

	if (max < a[i])
	{
		max = a[i];
		printf("位置是%d\n", i + 1);
		printf("max is %d\n", a[i]);
	}

	min = a[0];

	if (min > a[i])
	{
		min = a[i];
		printf("位置是%d\n", i + 1);
		printf("min is %d\n", a[i]);
	}
}
