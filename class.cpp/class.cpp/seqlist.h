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
	if (IsFull(plist)){
		printf("顺序表已经满了，%d不能尾部插入");
		return;
	}
	plist->base[plist->size++] = x;
}
/////////////////////////////////////////////////////////////////////
//头插法
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("顺序表已满，%d不能头部插入");
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
////////////////////////////////////////////////////////////////
//打印表长
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
/////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////
//清除
void SeqLIistClear(SeqList *plist){
	assert(plist != NULL);
	plist->size == 0;
}
//////////////////////////////////////////////////////////////////////////
//按位置插入
bool SeqListInsertbypos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("表已经为空，不能再插入\n");
	}
}
/////////////////////////////////////////////////////////////
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
#endif