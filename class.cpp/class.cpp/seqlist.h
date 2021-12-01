#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "Common.h"

#define SEQLIST_DEFAULT_SIZE 8;
//����˳���Ľṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;
void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist,ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);
size_t SeqListLength(SeqList *plist);
void SeqListPopBack(SeqList *plist);
void SeqLIistClear(SeqList *plist);
bool SeqListInsertbypos(SeqList *plist, int pos, ElemType x);
void SeqListSort(SeqList *plist);



void SeqListPopFront(SeqList *plist);
/////////////////////////////////////////////////////////////////////////////////
bool IsFull(SeqList *plist)
{
	assert(plist!=NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)
{
	assert(plist!=NULL);
	return plist->size == 0;
}
//////////////////////////////////////////////////////////////////////////////////
//��ĳ�ʼ��
void SeqListInit(SeqList *plist){
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base=(ElemType *)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}
////////////////////////////////////////////////////////////////////////////////
//���ٱ�
void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;

}
//////////////////////////////////////////////////////////////////////
//β�巨
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("˳����Ѿ����ˣ�%d����β������");
		return;
	}
	plist->base[plist->size++] = x;
}
/////////////////////////////////////////////////////////////////////
//ͷ�巨
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("˳���������%d����ͷ������");
		return;
	}
	for (int i = plist->size; i > 0; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;

}
/////////////////////////////////////////////////////////////////////////////////
//��ʾ��
void SeqListShow(SeqList *plist){
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++){
		printf("%d ", plist->base[i]);	
	}
	printf("\n");
}
////////////////////////////////////////////////////////////////
//��ӡ��
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
/////////////////////////////////////////////////////////////////////////
//β��ɾ��
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����β��ɾ��\n");
		return;
	}
	plist->size--;
}
/////////////////////////////////////////////////////////////////////////
//���
void SeqLIistClear(SeqList *plist){
	assert(plist != NULL);
	plist->size == 0;
}
//////////////////////////////////////////////////////////////////////////
//��λ�ò���
bool SeqListInsertbypos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("���Ѿ�Ϊ�գ������ٲ���\n");
	}
}
/////////////////////////////////////////////////////////////
//����
void SeqListSort(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size - 1; ++i)
	{
		for (size_t j = 0; j < plist->size - i - 1; ++j){
			if(plist->base[j] > plist->base[j + 1]){
				Swap(&plist->base[j], &plist->base[j + 1]);
			}
		}
	}
}
#endif