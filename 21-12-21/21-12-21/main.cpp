#include "BinTreeSearch.h"

void main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BSTree bst;
	BstInit(&bst);

	for (int i = 0; i < n; i++){
		BstInsert(&bst, arr[i]);
	}
	printf("%d", BstMin(bst));
	system("pause");
}