// SeqList.h
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define CAPACITY 8
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
//��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->capacity = CAPACITY;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)*ps->capacity);
	ps->size = 0;
}
//����
void SeqListDestory(SeqList* ps)
{
	assert(ps != NULL);
	free(ps->a);
	ps->a=NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (int i =0 ; i < ps->size; i++){
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}