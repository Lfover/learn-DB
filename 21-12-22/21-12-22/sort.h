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
	int start = 0;
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
//���Բ�������
void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//BinTnsertSort(arr, left, right);
	TowWayInsertSort(arr, left, right);
}

#endif