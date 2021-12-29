/*
#ifndef _SEQUENTIAL_H_
#define _SEQUENTIAL_H_
#include <stdio.h>

#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <stdbool.h>

#define ElemType int
typedef struct sequentialtable{
	ElemType *table;
	int size;
	int capacity;
}SeqTable;
//初始化
void SeqTableInit(SeqTable *Stable);
//增
void SeqTableAdd(SeqTable *Stable, ElemType x);
//删
void SeqTableDel(SeqTable *Stable, ElemType x);
//改
void SeqTableChange(SeqTable *Stable,ElemType x,ElemType y);
//查
int SeqTableFind(SeqTable *Stable, ElemType x);
//显示
void SeqTableShow(SeqTable *Stable);
///////////////////////////////////////////////////////////////////////////////////////////
//初始化
//不考虑扩容
void SeqTableInit(SeqTable *Stable)
{
	Stable->size = 0;
	Stable->capacity = 10;
	Stable->table = (ElemType *) malloc(sizeof(ElemType)*Stable->capacity);
}
//判空
bool IsEmpty(SeqTable *Stable)
{
	assert(Stable);
	return Stable->size == 0;
}
//判满
bool IsFull(SeqTable *Stable)
{
	assert(Stable);
	return Stable->size >= Stable->capacity;
}
//增
void SeqTableAdd(SeqTable *Stable, ElemType x)
{
	assert(Stable);
	if (IsFull(Stable))
	{
		printf("已满\n");
		return;
	}
	Stable->table[Stable->size++] = x;
}
//删
void SeqTableDel(SeqTable *Stable, ElemType x)
{
	assert(Stable);
	if (IsEmpty(Stable))
	{
		printf("已空\n");
		return;
	}
	if (SeqTableFind(Stable, x) == -1){
		printf("想要删除的数据不存在\n");
		return;
	}
	else{
		int n = SeqTableFind(Stable, x);
		for (int i = n; i < Stable->size - 1; i++)
		{
			Stable->table[i] = Stable->table[i + 1];
		}
		Stable->size--;
		printf("删除成功\n");
	}
}

//改
void SeqTableChange(SeqTable *Stable, ElemType x, ElemType y)
{
	assert(Stable);
	if (SeqTableFind(Stable, x) == -1)
		return;
	int n = SeqTableFind(Stable, x);
	Stable->table[n] = y;
	printf("修改成功\n");
}
//查
int SeqTableFind(SeqTable *Stable, ElemType x)
{
	assert(Stable);
	int i = 0;
	for (i = 0; i < Stable->size; i++)
	{
		if (Stable->table[i] == x)
			break;	
	}
	if (i < Stable->size)
		return i;
	else
	return -1;
}
//显示
void SeqTableShow(SeqTable *Stable)
{
	assert(Stable);
	for (int i = 0; i < Stable->size; i++)
	{
		printf("%d ", Stable->table[i]);
	}
	printf("\n");
}

#endif
*/