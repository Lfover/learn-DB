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
//��ʼ��
void SeqTableInit(SeqTable *Stable);
//��
void SeqTableAdd(SeqTable *Stable, ElemType x);
//ɾ
void SeqTableDel(SeqTable *Stable, ElemType x);
//��
void SeqTableChange(SeqTable *Stable,ElemType x,ElemType y);
//��
int SeqTableFind(SeqTable *Stable, ElemType x);
//��ʾ
void SeqTableShow(SeqTable *Stable);
///////////////////////////////////////////////////////////////////////////////////////////
//��ʼ��
//����������
void SeqTableInit(SeqTable *Stable)
{
	Stable->size = 0;
	Stable->capacity = 10;
	Stable->table = (ElemType *) malloc(sizeof(ElemType)*Stable->capacity);
}
//�п�
bool IsEmpty(SeqTable *Stable)
{
	assert(Stable);
	return Stable->size == 0;
}
//����
bool IsFull(SeqTable *Stable)
{
	assert(Stable);
	return Stable->size >= Stable->capacity;
}
//��
void SeqTableAdd(SeqTable *Stable, ElemType x)
{
	assert(Stable);
	if (IsFull(Stable))
	{
		printf("����\n");
		return;
	}
	Stable->table[Stable->size++] = x;
}
//ɾ
void SeqTableDel(SeqTable *Stable, ElemType x)
{
	assert(Stable);
	if (IsEmpty(Stable))
	{
		printf("�ѿ�\n");
		return;
	}
	if (SeqTableFind(Stable, x) == -1){
		printf("��Ҫɾ�������ݲ�����\n");
		return;
	}
	else{
		int n = SeqTableFind(Stable, x);
		for (int i = n; i < Stable->size - 1; i++)
		{
			Stable->table[i] = Stable->table[i + 1];
		}
		Stable->size--;
		printf("ɾ���ɹ�\n");
	}
}

//��
void SeqTableChange(SeqTable *Stable, ElemType x, ElemType y)
{
	assert(Stable);
	if (SeqTableFind(Stable, x) == -1)
		return;
	int n = SeqTableFind(Stable, x);
	Stable->table[n] = y;
	printf("�޸ĳɹ�\n");
}
//��
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
//��ʾ
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