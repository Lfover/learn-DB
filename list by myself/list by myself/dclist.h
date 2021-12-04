#ifndef _DCLIST_H_
#define _DCLIST_H_
#include "Common.h"

//定义结点
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;

}DCListNode;
typedef DCListNode *DCList;


void DCListInit(DCList *phead);
DCListNode *_Buynode(ElemType v = ElemType());
void DCListNodePushBack(DCList *phead, ElemType x);
void DCListShow(DCList phead);
void DCListPushFront(DCList *phead, ElemType x);
void DCListPopBack(DCList *phead);
void DCListPopFront(DCList *phead);
size_t DCListLength(DCList *phead);
ElemType DCListFront(DCList phead);
ElemType DCListBack(DCList phead);
void DCListClear(DCList *phead);
void DCListDestroy(DCList *phead);
DCListNode *DCListFind(DCList phead, ElemType key);
void DCListErasebyval(DCList phead,ElemType key);
void DCListSort(DCList phead);

void DCListReverse(DCList phead);
void DCListEarse(DCList phead);
//////////////////////////////////////////////////////////////////////////
//创建空间
DCListNode *_Buynode(ElemType v = ElemType())
{
	DCListNode *_S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(_S != NULL);
	_S->data = v;
	_S->next = _S->prev = _S;
	return _S;
}
//初始化
void DCListInit(DCList *phead)
{
	 *phead = _Buynode();
}
//尾插
void DCListNodePushBack(DCList *phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);
	DCListNode *head = *phead;

	s->prev = head->prev;
	s->next = head;
	head->prev->next = s;
	head->prev = s;
}
//显示
void DCListShow(DCList phead)
{
	DCListNode *p = phead->next;
	while (p!=phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
//头插
void DCListPushFront(DCList *phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);
	DCListNode *head = *phead;

	s->prev = head;
	s->next = head->next;
	head->next->prev = s;
	head->next = s;

}
//尾删
void DCListPopBack(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->next == head){//注意判断链表是否为空
		return;
	}
	DCListNode *p = head->prev;
	p->prev->next = head;
	head->prev = p->prev;
	free(p);
}
//头删
void DCListPopFront(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->next == head)//判空
		return;
	DCListNode *p = head->next;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}
//长度
size_t DCListLength(DCList phead)
{
	assert(phead != NULL);
	DCListNode *p = (phead)->next;

	size_t size = 0;
	while (p != phead)
	{
		size++;
		p = p->next;
	}
	return size;
}
//表头
ElemType DCListFront(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->next->data;
}
//表尾
ElemType DCListBack(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->prev->data;
}
//清除
void DCListClear(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;//更新p
	}
}
void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;//预防野指针
}
//查找
DCListNode *DCListFind(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead&&p->data != key){
		p = p->next;
	}
			if (p == phead){
				return NULL;
			}
			return p;
	
}
//按值删除
void DCListErasebyval(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead&&p->data != key){
		p = p->next;
	}
	if (p == phead){
		return;
	}
	else{
		//DCListPopBack(p);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}
//排序
void DCListSort(DCList phead)
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1){
		return;
	}
	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	p->next = phead;
	phead->prev = p;
	while (q != phead)
	{
		p = q;
		q = q->next;
		DCListNode *tmp = phead->next;
		while (tmp != phead&&p->data > tmp->data)
			tmp = tmp->next;
		
		p->next = tmp;
		p->prev = tmp->prev;
		p->next->prev = p;
		p->prev->next = p;
	}
}
void DCListInsertbyval(DCList phead, ElemType x)
{
	assert(phead);
	DCListNode *p = phead->next;
	while (p != phead&&x > p->data){
		p = p->next;
	}
	DCListNode *s = _Buynode(x);

	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
}
#endif