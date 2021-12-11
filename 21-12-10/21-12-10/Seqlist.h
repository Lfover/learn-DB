#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//定义顺序表结构
typedef struct Seqlist{
	int *base;//整形为例
	size_t capacity;//样例给8
	size_t size;
}Seqlist;


//函数声明
void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);
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
int SeqListFind(SeqList *plist, ElemType x);
void SeqListErasebyval(SeqList *plist, ElemType x);
void SeqListReverse(SeqList *plist);
bool _Inc(SeqList *plist, size_t new_capacity);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//判空
bool IsEmpty(Seqlist *plist){
	assert(plist);
	return plist->size == 0;
}
//判满
bool IsFill(Seqlist *plist){
	assert(plist);
	return plist->size == plist->capacity;
}
//动态分配内存
bool Inc(Seqlist *plist, size_t new_capacity)
{
	assert(plist&&new_capacity > plist->capacity);
	int *new_base = (int *)realloc(plist->base, sizeof(int)*new_capacity);
	if (new_base == NULL){
		return false;
	}
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}
//初始化
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = 8;//初始大小为8
	plist->base = (int *)malloc(sizeof(int) * 8);//分配8个整形内存
	plist->size = 0;
}
//销毁
void SeqListDestroy(SeqList *plist)
{
	assert(plist);//避免空指针
	free(plist->base);
	plist->base = NULL;//避免野指针
	plist->capacity = plist->size = 0;
}
//尾插
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist);
	//先判满
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("顺序表已满。不能插入");
		return;
	}
	plist->base[plist->size++] = x;
}
//头插
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist);
	//头插法需要将所有元素向后移动一格，把plist->base[0]的位置空出来，才能插入
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("顺序表已满。不能插入");
		return;
	}
	while (plist->size--){
		plist->base[plist->size] = plist->base[plist->size-1];//base下标从0开始的，因此这里是下标为size-1的赋值给size
	}
	plist->base[0] = x;
	plist->size++;
}
//显示
void SeqListShow(SeqList *plist)
{
	assert(plist);
	for (int i = 0; i < plist->size; i++){
		printf("%d ", plist->base[i]);
	}
}
//长度
size_t SeqListLength(SeqList *plist)
{
	assert(plist);
	return plist->size;
}
//尾删
void SeqListPopBack(SeqList *plist)
{
	assert(plist);
	//先判空
	if (IsEmpty(plist)){
		printf("顺序表已空，不能删除");
		return;
	}
	plist->size--;
}
//头删
void SeqListPopFront(SeqList *plist)
{
	assert(plist);
	//头删可以将除了第一个元素的其他元素全部向前移动一格，第一个元素会被覆盖掉，达到头删的目的
	if (IsEmpty(plist)){
		printf("顺序表已空，不能删除");
		return;
	}
	for (int i = 0; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
//清除
void SeqLIistClear(SeqList *plist);
{
	//直接令size=0就可以代表清空顺序表中的所有元素
	assert(plist);
	plist->size = 0;
}
//按位置插入
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x)
{
	assert(plist);
	//按位置插入不仅要判断顺序表是否已满，还要判断插入的位置是否合法
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("顺序表已满。不能插入");
		return false;
	}
	if (pos<0 || pos>plist->size){
		printf("插入位置不合法");
		return false;
	}//将pos位置及以后的元素都向后移动一格，把pos位置让出来
	for (int i = plist->size; i > pos; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	return true;

}
//按值插入
bool SeqListInsertbyval(SeqList *plist, ElemType x)
{
	assert(plist);
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("顺序表已满。不能插入");
		return false;
	}
	//想要实现按值插入，需要先将顺序表排好序
	SeqListSort(plist);
	for (size_t i = 0; i < plist->size; i++){
		if (plist->base[i] > x){//当plist->base[i]>x时，x需要插入的地方是base[i]前面的位置
			for (int j = plist->size; j > i; i--){
				plist->base[j] = plst->base[j - 1];//i及以后的数据向后移动，将i位置空出来
			}
			plist->base[i] = x;
			plist->size++;
			return true;
		}
	}
}
//排序
void SeqListSort(SeqList *plist)
{
	assert(plist);
	//排序方法用的冒泡排序
	int temp = 0;
	for (int i = 0; i < plist ->size-1; i++){
		for (int i = 0; i < plist->size-1; i++){
			if (plist->base[j] > plist->base[j + 1]){
				temp = plist->base[j];
				plist->base[j] = plist->base[j + 1];
				plist->base[j + 1] = temp;
			}
		}
	}
}
//按位置删除
void SeqListEarsebypos(SeqList *plist, size_t pos)
{
	assert(plist);
	//先判空
	if (IsEmpty(plist)){
		printf("顺序表已空，不能删除");
		return;
	}//判断插入位置是否合法
	if (pos<0 || pos>=plist->size){
		printf("删除位置不合法");
		return;
	}
	for (int i = pos; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];//向前覆盖
	}
	plist->size--;

}
//按值删除
void SeqListErasebyval(SeqList *plist, ElemType x)
{
	assert(plist);
	//先判空
	if (IsEmpty(plist)){
		printf("顺序表已空，不能删除");
		return;
	}
	//res存储SeqListFind函数的返回值，用来判断想要删除的值在顺序表里有没有
	int res=SeqListFind(plist, x);
	if (res==-1){
		printf("没有这个元素");
		return;
	}
	else{
		for (int i = res; i < plist->size; i++){
			plist->base[i] = plist->base[i + 1];
		}
	}
	plist->size--;
}

//查找
int SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist);
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("表已经为空，查找不到\n");
		return -1;
	}
	for (int i = 0; i < plist->size; i++){
		if (plist->base[i] == x){
			retrun i;
		}
	}
	return -1;
}
//反转
void SeqListReverse(SeqList *plist)
{
	assert(plist);
	if (plist->size == 1){
		return;
	}
	int temp = 0;
	int start = 0;
	int end = plist->size - 1;
	while (start < end){
		temp = plist->base[end];
		plist->base[end] = plist->base[start];
		plist->base[start] = temp;
		start++:
		end--;
	}
}

#endif