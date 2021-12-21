#ifndef _HEAP_H_
#define _HEAP_H_


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include <memory.h>
#define HEAP_SIZE 20
typedef int HeapElemType;

typedef struct MinHeap
{
	HeapElemType *base;
	size_t capacity;
	size_t size;
}MinHeap;

void HeapInit(MinHeap *php,int sz=HEAP_SIZE);
void HeapCreate(MinHeap *php, HeapElemType arr[], int n);
void HeapInsert(MinHeap *php, HeapElemType x);
void HeapDelete(MinHeap *php);//ɾ��ֻ��ɾ���Ѷ�

void HeapShow(MinHeap *php);
void HeapShiftUp(MinHeap *php, int start);
void HeapShiftDown(MinHeap *php, int start,int n);
////////////////////////////////////////////
//����
void Swap(HeapElemType *t1, HeapElemType *t2){
	HeapElemType temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

//��ʼ��
void HeapInit(MinHeap *php,int sz)
{
	assert(php);
	php->capacity = sz > HEAP_SIZE ? sz : HEAP_SIZE;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType)*php->capacity);
	memset(php->base, 0, sizeof(HeapElemType)*php->capacity);
	php->size = 0;
}
//����
void HeapCreate(MinHeap *php, HeapElemType arr[], int n)
{
	//1.����ռ�
	php->capacity = n;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType)*php->capacity);
	//2.�жϷ����Ƿ�ɹ�
	if (php->base == NULL){
		return;
	}
	//3.�ɹ����ѿռ��Ȱ��ַ���������
	for (int i = 0; i<n; i++){
		php->base[i]=arr[i];
	}
	php->size = n;
	//4.�ѵ���
	//�ҵ����һ����֧����Ϊ���µ��������һ����֧���������ر�����ÿ�����Ĵ�С��������
	int currentpos = n / 2 - 1;//�ҵ����һ����֧
	while (currentpos >= 0){
		HeapShiftDown(php, currentpos, n);
		currentpos--;
	}
}
//����
void HeapInsert(MinHeap *php, HeapElemType x)
{
	if (php->size > php->capacity){
		printf("�ѿռ�����");
		return;
	}
	php->base[php->size] = x;
	HeapShiftUp(php,php->size);
	php->size++;
}
//ɾ��
void HeapDelete(MinHeap *php)
{
	if (php == NULL)
		return;
	if (php->size == 0){
		printf("�ѿռ��ѿ�");
		return;
	}
	php->size--;
	php->base[0] = php->base[php->size];
	HeapShiftDown(php, 0, php->size);
}
//��ʾ
void HeapShow(MinHeap *php)
{
	assert(php);
	for (int i = 0; i < php->size; i++){
		printf("%d ", php->base[i]);
	}
	printf("\n");
}
//�ܲ��ܲ���ÿ�ζ�����
//���ϵ���
void HeapShiftUp(MinHeap *php, int start)
{
	//i=parent,j=child
	int j = start;
	int i = (j - 1) / 2;
	while (j >= 0){
		if (php->base[j] < php->base[i]){
			Swap(&php->base[j], &php->base[i]);
		}
		else{
			break;
		}
	}
}
//���µ���
void HeapShiftDown(MinHeap *php, int start,int n)
{
	int i = start;
	int j = (i * 2) + 1;
	        //1.ѭ����������j>=n
		while (j<n){
			//2.��������������ұ�������С
			if (j + 1 < n && php->base[j] > php->base[j + 1]){
				j++;//j�䵽��������ȥ
			}
			//3.������ڵ�����ӽ�㣬�������ӣ��ı�i,j
			if (php->base[i]>php->base[j])
				{
					Swap(&php->base[i], &php->base[j]);
					i = j;
					j = 2 * i + 1;
				}
			//4.������ڵ�С���ӽ�㣬����С���ѣ�����ѭ��
			else{
				break;
			}
		}
}
#endif//_HEAP_H_