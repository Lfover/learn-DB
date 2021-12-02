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
////////////////////////////////////////////////////////////////////////////////////
//��������
void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist,ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);
size_t SeqListLength(SeqList *plist);
void SeqListPopBack(SeqList *plist);
void SeqLIistClear(SeqList *plist);
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x);
void SeqListSort(SeqList *plist);
bool SeqListInsertbyval(SeqList *plist, ElemType x);
size_t SeqListCapacity(SeqList *plist);
void SeqListEarsebypos(SeqList *plist, size_t pos);
void SeqListPopFront(SeqList *plist);
int SeqListFind(SeqList *plist,ElemType x);
void SeqListErasebyval(SeqList *plist,ElemType x);
void SeqListReverse(SeqList *plist);
bool _Inc(SeqList *plist, size_t new_capacity);
/////////////////////////////////////////////////////////////////////////////////
//����ʵ��
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
///////////////////////////////////////////////////////////////////////////////////
//������
bool _Inc(SeqList *plist, size_t new_capacity)
{
	assert(plist != NULL&&new_capacity > plist->capacity);
	ElemType *new_base = (ElemType *)realloc(plist->base, sizeof(ElemType)*new_capacity);
	if (new_base == NULL){
		return false;
	}
	plist->base =new_base;
	plist->capacity =new_capacity;
	return true;
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
	if (IsFull(plist)&&!_Inc(plist,plist->capacity*2)){
		printf("˳����Ѿ����ˣ�����β������");
		return;
	}
	plist->base[plist->size++] = x;
}
//////////////////////////////////////////////////////////////////////////////
//ͷ�巨
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("˳�������������ͷ������");
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
//////////////////////////////////////////////////////////////////////////////
//��ӡ��
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
//ͷ��ɾ��
void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���Ѿ�Ϊ�գ����ܲ���\n");
		return;
	}
	for (size_t i = 0; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
////////////////////////////////////////////////////////////////////////////
//���
void SeqLIistClear(SeqList *plist){
	assert(plist != NULL);
	plist->size = 0;
}
/////////////////////////////////////////////////////////////////////////////
//��λ�ò���
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("���Ѿ����ˣ������ٲ���\n");
		return false;
	}
	if (pos<0 || pos>plist->size){
		printf("����λ�ò��Ϸ�\n");
		return false;
	}
	for (int i = plist->size; i > pos; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	return true;
}
///////////////////////////////////////////////////////////////////////////
//��ֵ����
bool SeqListInsertbyval(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("���Ѿ����ˣ������ٲ���\n");
		return false;
	}
	for (size_t i = 0; i < plist->size; i++){
		if (plist->base[i] > x){
			for (int j = plist->size; j > i; j--){
				plist->base[j] = plist->base[j - 1];
			}
			plist->base[i] = x;
			plist->size++;
			return true;
		}
	}
#if 0
	size_t end = plist->size - 1;
	while (end>=0&&x < plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end+1] = x;
	plist->size++;
}
#endif
}
/////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////
//����
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
////////////////////////////////////////////////////////////////////////////////
//��λ��ɾ��
void SeqListEarsebypos(SeqList *plist, size_t pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���Ѿ�Ϊ�գ����ܰ�λ��ɾ��\n");
		return;
	}
	if (pos < 0 || pos >= plist->size)
	{
		printf("ɾ����λ�ò��Ϸ�\n");
		return;
	}
	for (int i = pos; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
///////////////////////////////////////////////////////////////////////////////
//����
int SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���Ѿ�Ϊ�գ����Ҳ���\n");
		return -1;
	}
	for(int i = 0; i < plist->size; i++){
		if (plist->base[i] == x){
			return i;
		}
	}
	return -1;
}
/////////////////////////////////////////////////////////////////////////////
//��ֵɾ��
void SeqListErasebyval(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	int pos = SeqListFind(plist, x);
	if (pos == -1){
		return;
	}
	SeqListEarsebypos(plist,pos);
}
////////////////////////////////////////////////////////////////////////////
//ת�ñ�
void SeqListReverse(SeqList *plist)
{
	assert("plist!=NULL");
	if (plist->size == 1)
	{
		return;
	}
	int start = 0, end = plist->size - 1;
	while (start<end)
	{
		Swap(&plist->base[start], &plist->base[end]);
		start++;
		end--;
	}
}

#endif