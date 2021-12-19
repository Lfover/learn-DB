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
void HeapInsert(MinHeap *php, HeapElemType x);
void HeapDelete(MinHeap *php);//删除只能删除堆顶

void HeapShow(MinHeap *php);
void HeapShiftUp(MinHeap *php, int start);
void HeapShiftDown(MinHeap *php, int start);
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
void HeapDelete(MinHeap *php, HeapElemType key)
{
	if (php->size == 0){
		printf("堆空间已空");
		return;
	}
	php->base[0] = php->base[php->size];
	HeapShiftDown(php, php->size);
	php->size--;

}
//显示
void HeapShow(MinHeap *php)
{
	assert(php);
	for (int i = 0; i < php->size; i++){
		printf("%d", php->base[i]);
	}
}
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
void HeapShiftDown(MinHeap *php, int start)
{
	int i = start;
	int j = (i * 2) + 1;
		while (i <= php->size){
			if (php->base[j] < php->base[i]){
				Swap(&php->base[j], &php->base[i]);
			else
				break;
		}
}
#endif//_HEAP_H_