#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "Common.h"

#define SEQLIST_DEFAULT_SIZE 8;
//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;
////////////////////////////////////////////////////////////////////////////////////
//函数声明
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
//函数实现
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
//表扩容
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
//表的初始化
void SeqListInit(SeqList *plist){
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base=(ElemType *)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}
////////////////////////////////////////////////////////////////////////////////
//销毁表
void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;

}
//////////////////////////////////////////////////////////////////////
//尾插法
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)&&!_Inc(plist,plist->capacity*2)){
		printf("顺序表已经满了，不能尾部插入");
		return;
	}
	plist->base[plist->size++] = x;
}
//////////////////////////////////////////////////////////////////////////////
//头插法
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("顺序表已满，不能头部插入");
		return;
	}
	for (int i = plist->size; i > 0; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;

}
/////////////////////////////////////////////////////////////////////////////////
//显示表
void SeqListShow(SeqList *plist){
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++){
		printf("%d ", plist->base[i]);	
	}
	printf("\n");
}
//////////////////////////////////////////////////////////////////////////////
//打印表长
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
//////////////////////////////////////////////////////////////////////////////
//尾部删除
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("顺序表已空，不能尾部删除\n");
		return;
	}
	plist->size--;
}
//////////////////////////////////////////////////////////////////////////////
//头部删除
void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已经为空，不能插入\n");
		return;
	}
	for (size_t i = 0; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
////////////////////////////////////////////////////////////////////////////
//清除
void SeqLIistClear(SeqList *plist){
	assert(plist != NULL);
	plist->size = 0;
}
/////////////////////////////////////////////////////////////////////////////
//按位置插入
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("表已经满了，不能再插入\n");
		return false;
	}
	if (pos<0 || pos>plist->size){
		printf("插入位置不合法\n");
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
//按值插入
bool SeqListInsertbyval(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)){
		printf("表已经满了，不能再插入\n");
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
//排序
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
//容量
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
////////////////////////////////////////////////////////////////////////////////
//按位置删除
void SeqListEarsebypos(SeqList *plist, size_t pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已经为空，不能按位置删除\n");
		return;
	}
	if (pos < 0 || pos >= plist->size)
	{
		printf("删除的位置不合法\n");
		return;
	}
	for (int i = pos; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
///////////////////////////////////////////////////////////////////////////////
//查找
int SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已经为空，查找不到\n");
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
//按值删除
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
//转置表
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