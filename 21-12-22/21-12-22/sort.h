#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include <memory.h>

void printArray(int arr[], int left, int right)
{
	for (int i = left; i < right; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//直接插入排序
void InsertSort(int *arr, int left, int right)
{
	for (int i = left+1; i < right; i++){
		int end = i;
		while (end>left && arr[end] < arr[end - 1]){
			Swap(&arr[end], &arr[end - 1]);
			end--;
		}
	}
}
//插入2
void InsertSort_2(int *arr, int left, int right)
{
	for (int i = left+1; i < right; i++){
		int temp = arr[i];
		int end = i;
		while (end>left&&arr[end - 1]>temp){
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = temp;
	}
}
//哨兵位的直接插入排序
void InsertSort_3(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		arr[0] = arr[i];
		int end = i;
		while (arr[0] < arr[end - 1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = arr[0];
	}
}
//折半插入排序
void BinTnsertSort(int *arr, int left, int right)
{
	for (int i = 1; i < right; i++){
		int temp = arr[i];
	int start = left;
	int end = i-1;
	while (start <= end){
		int mid = start + (end - start) / 2;

		if (temp < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	for (int j = i - 1; j >= end + 1; j--)
		arr[j + 1] = arr[j];
		arr[end + 1] = temp;
	
	}
}
//二路插入排序
void TowWayInsertSort(int *arr,int left,int right)
{
	    int n = right - left;
		int i, j, first, last, mid;
		int *d = (int *)malloc(sizeof(int)*n);//d是和arr大小相同的数组
		d[0] = arr[left];//将arr的第一个元素放进数组d
		first = last = 0;       // first和last分别指示 d 中排好序的记录的第一个和最后一个位置

		for (i = left+1; i < right; i++){

			if (first > last){
				j = n;        // j 是调整系数
			}
			else{
				j = 0;
			}
			mid = ((first + last + j) / 2) % n;  // d 的中间记录的位置
			if (arr[i] < d[mid]){                    // -- 待插记录应插在 d 的前半部分
				j = first;                           // j 指向 d 的第一个记录
				first = (first - 1 + n) % n;     // first 前移，取余是为了实现循环数组效果
				while (arr[i] > d[j]){               // 待插记录大于 j 所指记录
					d[(j - 1 + n) % n] = d[j];   // j 所指记录前移，取余是为了实现循环数组效果
					j = (j + 1) % n;               // j 指向下一个记录
				}
				d[(j - 1 + n) % n] = arr[i];    // 移动结束，待插记录插在[j]前
			}
			else{                                   // -- 待插记录应插在 d 的后半部分
				j = last;                            // j 指向当前的最后一个记录
				last++;                              // last后移， 指向插入后的最后一个记录
				while (arr[i] < d[j]){               // 待插记录小于 j 所指记录
					d[(j + 1) % n] = d[j];        // j 所指记录后移
					j = (j - 1 + n) % n;         // j 指向上一个记录
				}
				d[(j + 1) % n] = arr[i];          // 待插记录不小于 j 所指记录，插在 j 后
			}// end else
		}// end for
		for (i = 0; i < n; i++){                    // 把在 d 中排好序的记录依次赋给nums
			arr[i] = d[(first + i) % n];
		}
	

}
//希尔排序1
void ShellInsert(int *arr, int left, int right, int dk)
{
	for (int i = left + dk; i < right; i++){
		if (arr[i] < arr[i - dk]){
			int temp = arr[i];
			int end = i - dk;
			while (end >= left&&temp < arr[end])
			{
				arr[end + dk] = arr[end];
				end -= dk;
			}
			arr[end + dk] = temp;
		}
	}
}
int dlta[] = { 5, 3, 2, 1 };
void ShellSort(int *arr, int left, int right)
{
	int t = sizeof(dlta) / sizeof(dlta[0]);
	for (int k = 0; k < t; k++)
		ShellInsert(arr, left, right, dlta[k]);
}
//希尔排序2
void ShellInsert(int *arr, int left, int right)
{
	int dk = right - left;
	while (dk > 1){
		dk=dk / 3 + 1;
		for (int i = left + dk; i < right; i++){
			if (arr[i] < arr[i - dk]){
				int temp = arr[i];
				int end = i - dk;
				while (end >= left && temp < arr[end])
				{
					arr[end + dk] = arr[end];
					end -= dk;
				}
				arr[end + dk] = temp;
			}
		}
	}
}
//直接插入排序
void SelectSort(int *arr, int left, int right)
{
	for (int i = left; i < right; i++){
		int min = arr[i];
		int pos = i;
		for (int j = i + 1; j < right; j++){
			if (arr[i] < min){
				min = arr[i];
				pos = j;
			}
		}
		if (pos != i){
			Swap(&arr[i], &arr[pos]);
		}
	}
}
//堆排序
void ShiftDown(int *arr, int left,int right, int curpos)
{
	int i = curpos;//i是父节点
	int j = 2 * i + 1+left;//j是子结点
	int n = right - left;
	while (j<n){
		if (j + 1 < n&&arr[j] < arr[j + 1])
			j++;
		if (arr[i] < arr[j]){
			Swap(&arr[i], &arr[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void ShiftDown_1(int *arr, int left, int right, int curpos)
{
	int i = curpos;//i是父节点
	int j = 2 * i + 1 + left;//j是子结点
	int n = right - left;
	int temp = arr[i];
	while (j<n){
		if (j + 1 < n&&arr[j] < arr[j + 1])
			j++;
		if (temp < arr[j]){
			arr[i]= arr[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void HeapSort(int *arr, int left, int right)
{
	//1.创建大堆
	int n = right - left;
		int cur = n / 2 - 1 + left;
	while (cur >= 0){
		ShiftDown(arr, left,right, cur);
		cur--;
	}
	//2.排序
	int end = right - 1;
	while (end > left){
		Swap(&arr[left], &arr[end]);
		end--;
		ShiftDown(arr, left, end, left);
	}
}
//冒泡排序
void BubbleSort(int *arr, int left, int right)
{
	int n = right - left;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (arr[j] < arr[j - 1]){
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//冒泡排序优化
void BubbleSort_1(int *arr, int left, int right)
{
	int n = right - left;
	bool q = false;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] < arr[j - 1]){
				Swap(&arr[j], &arr[j + 1]);
				q = true;
			}
		}
		if (!q)
			break;
		else{
			q = false;
		}
	}
}
//快速排序
//hoare版本
int _Partition_1(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right){
		while (left<right&&arr[right]>key)
			right--;
		Swap(&arr[left], &arr[right]);
		while (left < right&&arr[left] < key)
			left++;
		Swap(&arr[left], &arr[right]);		
	}
	return left;
}
//挖坑法
int _Partition_2(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left<right&&arr[right]>key)
			right--;
		arr[left] = arr[right];
		while (left < right&&arr[left] < key)
			left--;
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}
//前后指针法
int _Partition_3(int *arr, int left, int right)
{
	int key = arr[left];
	int pos = left;
	for (int i = left + 1; i <= right; i++){
		if (arr[i] < key)
		{
			pos++;
			//pos和i的位置不同，代表有比key大的值，找到了交换目前的I和pos
			if (pos != i)
				Swap(&arr[pos], &arr[i]);
		}
	}
	Swap(&arr[left], &arr[pos]);
	return pos;

}
void QuickSort(int *arr, int left, int right)
{
	if (left >= right - 1)
		return;
	int pos = _Partition_1(arr, left, right - 1);//分割数组
	QuickSort(arr, left, pos - 1);
	QuickSort(arr, pos + 1, right);
}
//测试插入排序
void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//BinTnsertSort(arr, left, right);
	TowWayInsertSort(arr, left, right);
}

#endif