//#include <stdio.h>
//#include <Windows.h>
//
//
//int* singleNumbers(int* nums, int numsSize, int* returnSize){
//	int ret = 0;
//	int x=0;
//	int y = 0;
//	for (int i = 0; i<numsSize; i++){
//		ret ^= nums[i];
//	}
//	int pos = 1;
//	while (1){
//		if (ret&pos){
//			break;
//		}
//		pos <<= 1;
//	}
//	for (int i = 0; i<numsSize; i++){
//		if (nums[i] & pos){
//			x ^= nums[i];
//		}
//		else{
//			y ^= nums[i];
//		}
//	}
//	int *arr = (int *)malloc(sizeof(int) * 2);
//	arr[0] = x;
//	arr[1] = y;
//	*returnSize = 2;
//	return arr;
//
//}
//int main()
//{
//	int a[10] = { 1, 2, 3, 3, 1, 4, 5, 5, 6, 6 };
//	int b[2];
//	singleNumbers(a, 10, b);
//	system("pause");
//	return 0;
//}