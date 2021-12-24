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
//ֱ�Ӳ�������
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
//����2
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
//�ڱ�λ��ֱ�Ӳ�������
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
//�۰��������
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
//��·��������
void TowWayInsertSort(int *arr,int left,int right)
{
	    int n = right - left;
		int i, j, first, last, mid;
		int *d = (int *)malloc(sizeof(int)*n);//d�Ǻ�arr��С��ͬ������
		d[0] = arr[left];//��arr�ĵ�һ��Ԫ�طŽ�����d
		first = last = 0;       // first��last�ֱ�ָʾ d ���ź���ļ�¼�ĵ�һ�������һ��λ��

		for (i = left+1; i < right; i++){

			if (first > last){
				j = n;        // j �ǵ���ϵ��
			}
			else{
				j = 0;
			}
			mid = ((first + last + j) / 2) % n;  // d ���м��¼��λ��
			if (arr[i] < d[mid]){                    // -- �����¼Ӧ���� d ��ǰ�벿��
				j = first;                           // j ָ�� d �ĵ�һ����¼
				first = (first - 1 + n) % n;     // first ǰ�ƣ�ȡ����Ϊ��ʵ��ѭ������Ч��
				while (arr[i] > d[j]){               // �����¼���� j ��ָ��¼
					d[(j - 1 + n) % n] = d[j];   // j ��ָ��¼ǰ�ƣ�ȡ����Ϊ��ʵ��ѭ������Ч��
					j = (j + 1) % n;               // j ָ����һ����¼
				}
				d[(j - 1 + n) % n] = arr[i];    // �ƶ������������¼����[j]ǰ
			}
			else{                                   // -- �����¼Ӧ���� d �ĺ�벿��
				j = last;                            // j ָ��ǰ�����һ����¼
				last++;                              // last���ƣ� ָ����������һ����¼
				while (arr[i] < d[j]){               // �����¼С�� j ��ָ��¼
					d[(j + 1) % n] = d[j];        // j ��ָ��¼����
					j = (j - 1 + n) % n;         // j ָ����һ����¼
				}
				d[(j + 1) % n] = arr[i];          // �����¼��С�� j ��ָ��¼������ j ��
			}// end else
		}// end for
		for (i = 0; i < n; i++){                    // ���� d ���ź���ļ�¼���θ���nums
			arr[i] = d[(first + i) % n];
		}
	

}
//ϣ������1
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
//ϣ������2
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
//ֱ�Ӳ�������
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
//������
void ShiftDown(int *arr, int left,int right, int curpos)
{
	int i = curpos;//i�Ǹ��ڵ�
	int j = 2 * i + 1+left;//j���ӽ��
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
	int i = curpos;//i�Ǹ��ڵ�
	int j = 2 * i + 1 + left;//j���ӽ��
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
	//1.�������
	int n = right - left;
		int cur = n / 2 - 1 + left;
	while (cur >= 0){
		ShiftDown(arr, left,right, cur);
		cur--;
	}
	//2.����
	int end = right - 1;
	while (end > left){
		Swap(&arr[left], &arr[end]);
		end--;
		ShiftDown(arr, left, end, left);
	}
}
//ð������
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
//ð�������Ż�
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
//��������
int GetIndexMidVal(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] > arr[mid] && arr[left] < arr[right])
		return left;
	if (arr[mid]>arr[left] && arr[mid] < arr[right])
		return mid;
	return right;
}
//hoare�汾
int _Partition_1(int *arr, int left, int right)
{
	//������ȡ�м�ֵ
	int index = GetIndexMidVal(arr, left, right);
	if (index != left)
		Swap(&arr[index], &arr[left]);
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
//�ڿӷ�
int _Partition_2(int *arr, int left, int right)
{
	//������ȡ�м�ֵ
	int index = GetIndexMidVal(arr, left, right);
	if (index != left)
		Swap(&arr[index], &arr[left]);
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
//ǰ��ָ�뷨
int _Partition_3(int *arr, int left, int right)
{
	//����ȡ��
	int index = GetIndexMidVal(arr, left, right);
	if (index != left)
		Swap(&arr[index], &arr[left]);
	int key = arr[left];
	int pos = left;
	for (int i = left + 1; i <= right; i++){
		if (arr[i] < key)
		{
			pos++;
			//pos��i��λ�ò�ͬ�������б�key���ֵ���ҵ��˽���Ŀǰ��I��pos
			if (pos != i)
				Swap(&arr[pos], &arr[i]);
		}
	}
	Swap(&arr[left], &arr[pos]);
	return pos;

}
//�ĸ������ĸ�
//�������С��M����ֱ�Ӳ��������������M���ÿ�������
#define M 25
void QuickSort(int *arr, int left, int right)
{
	if (left >= right - 1)
		return;
	if (right - left <= M)
		InsertSort_2(arr, left, right);
	else
	{
		int pos = _Partition_1(arr, left, right - 1);//�ָ�����
		QuickSort(arr, left, pos - 1);
		QuickSort(arr, pos + 1, right);
	}
}
//�鲢����
void _MergeSort(int *arr, int left, int right, int *temp)
{
	//1.�ȷֽ�
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, temp);
	_MergeSort(arr, mid + 1, right, temp);
	//2.��鲢
	int begin1, end1, begin2, end2, i;
	begin1 = left; end1 = mid;
	begin2 = mid + 1; end2 = right;
	
	i = 0;
	while (begin1 <= end1&&begin2 <= end2){
		if (arr[begin1] < arr[begin2])
			temp[i++] = arr[begin1++];
		else
			temp[i++] = arr[begin2++];
	}
	while (begin1 < end1)
		temp[i++] = arr[begin1++];
	while (begin2 < end2)
		temp[i++] = arr[begin2++];

	memcpy(arr + left, temp, sizeof(int)*(right - left + 1));
}
//�鲢����
void MergeSort(int *arr, int left, int right)
{
	int n = right - left;
	int *temp = (int *)malloc(sizeof(int)*n);
	assert(temp!=NULL);

	//�鲢�������
	_MergeSort(arr, left, right, temp);

	free(temp);
	temp = NULL;
}
#define RADIX 10
#define K 10
//ȡ��λ���ϵ�ÿ����
int GetKey(int value, int k)
{
	int key;
	while (k >= 0)
	{
		key = value % 10;
		value / 10;
		k--;
	}
	return key;
}
//�ַ�
void Distribute(int *arr, int left, int right, int k)
{
	for (int i = left; i < right; i++)
	{
		int key = GetKey(arr[i], k);
		SListPushBack(&list[key], arr[i]);//������arr[i]��ֵ�ŵ������У�β��
	}
}
//�ϲ�
void Collect(int *arr)
{
	int k = 0; 
	for (int i = 0; i < RADIX; i++){
		while (!SListEmpty(&list[i]))
		{
			//ֻҪ�����ڴ�λ���ϲ�Ϊ�գ��ͻ�������
			arr[k++] = SListFront(list[i]);
			SListPopFront(&list[i]);
		}
	
	}
}
//��������
void RadixSort(int *arr, int left, int right)
{
	for (int i = 0; i < RADIX; i++)
		SlListInit(&list[i]);//��ʼ������
	for (int i = 0; i < k; i++){
		//1.�ַ�
		Distribute(arr, left, right - 1, i);
		//2.�ռ�
		Collect(arr);
	}
}
//���Բ�������
void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//BinTnsertSort(arr, left, right);
	TowWayInsertSort(arr, left, right);
}

#endif