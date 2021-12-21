#include "heap.h"

void main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MinHeap mhp;
	HeapInit(&mhp);
	for (int i = 0; i < n; i++){
		HeapInsert(&mhp, arr[i]);
	}
	HeapShow(&mhp);
	HeapInsert(&mhp, 17);
	HeapShow(&mhp);
	HeapDelete(&mhp);
	HeapShow(&mhp);
	system("pause");
}