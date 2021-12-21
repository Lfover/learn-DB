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
void HeapDelete(MinHeap *php);//删除只能删除堆顶

void HeapShow(MinHeap *php);
void HeapShiftUp(MinHeap *php, int start);
void HeapShiftDown(MinHeap *php, int start,int n);
////////////////////////////////////////////
//交换
void Swap(HeapElemType *t1, HeapElemType *t2){
	HeapElemType temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

//初始化
void HeapInit(MinHeap *php,int sz)
{
	assert(php);
	php->capacity = sz > HEAP_SIZE ? sz : HEAP_SIZE;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType)*php->capacity);
	memset(php->base, 0, sizeof(HeapElemType)*php->capacity);
	php->size = 0;
}
//创建
void HeapCreate(MinHeap *php, HeapElemType arr[], int n)
{
	//1.分配空间
	php->capacity = n;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType)*php->capacity);
	//2.判断分配是否成功
	if (php->base == NULL){
		return;
	}
	//3.成功，堆空间先把字符串存下来
	for (int i = 0; i<n; i++){
		php->base[i]=arr[i];
	}
	php->size = n;
	//4.堆调整
	//找到最后一个分支是因为向下调整，最后一个分支会依次往回遍历，每个结点的大小都会碰到
	int currentpos = n / 2 - 1;//找到最后一个分支
	while (currentpos >= 0){
		HeapShiftDown(php, currentpos, n);
		currentpos--;
	}
}
//插入
void HeapInsert(MinHeap *php, HeapElemType x)
{
	if (php->size > php->capacity){
		printf("堆空间已满");
		return;
	}
	php->base[php->size] = x;
	HeapShiftUp(php,php->size);
	php->size++;
}
//删除
void HeapDelete(MinHeap *php)
{
	if (php == NULL)
		return;
	if (php->size == 0){
		printf("堆空间已空");
		return;
	}
	php->size--;
	php->base[0] = php->base[php->size];
	HeapShiftDown(php, 0, php->size);
}
//显示
void HeapShow(MinHeap *php)
{
	assert(php);
	for (int i = 0; i < php->size; i++){
		printf("%d ", php->base[i]);
	}
	printf("\n");
}
//能不能不用每次都交换
//向上调整
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
//向下调整
void HeapShiftDown(MinHeap *php, int start,int n)
{
	int i = start;
	int j = (i * 2) + 1;
	        //1.循环结束条件j>=n
		while (j<n){
			//2.如果右子树存在且比左子树小
			if (j + 1 < n && php->base[j] > php->base[j + 1]){
				j++;//j变到右子树上去
			}
			//3.如果父节点大于子结点，交换父子，改变i,j
			if (php->base[i]>php->base[j])
				{
					Swap(&php->base[i], &php->base[j]);
					i = j;
					j = 2 * i + 1;
				}
			//4.如果父节点小于子结点，满足小根堆，跳出循环
			else{
				break;
			}
		}
}
#endif//_HEAP_H_