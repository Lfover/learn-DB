#include "sort.h"

void main()
{
	int arr[] = { 49, 38, 65, 97, 13, 27, 49 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, 0, n);
	TestSort(arr, 0, n);
	printArray(arr, 0, n);
	
	system("pause");
}
