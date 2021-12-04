#ifndef _SLIST_H_
#define _SLIST_H_
#include "Common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;
//����ͷ���ĵ�����
typedef SListNode*SList;

void SListInit(SList *phead);
void SListPushBack(SList *phead, ElemType x);
void SListPushFront(SList *phead,ElemType x);
void SListPopBack(SList *phead);
void SListPopFront(SList *phead);
void SListShow(SList *phead);
size_t SListLength(SList *phead);

SListNode * SListFind(SList phead, ElemType key);
void SListErasebyval(SList *phead, ElemType key);
void SListInsertbyval(SList *phead, ElemType key);
void SListSort(SList *phead);

ElemType SListFront(SList phead);
ElemType SListBack(SList phead);
void SListEraseAll(SList *phead, ElemType key);
void SListClear(SList *phead);
void SListDestory(SList *phead);
void SListReverse(SList *phead);

//////////////////////////////////////////////////////////////////////////////////////
//��ʼ��
void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
//////////////////////////////////////////////////////////////////////////////////
//β��
void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;


	SListNode *p = *phead;

}
//////////////////////////////////////////////////////////////////
//ͷɾ
void SListPopFront(SList *phead);
void SListShow(SList phead)
{
	assert(phead != NULL);
		SListNode *p = phead;
	while (p->next != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}

}
///////////////////////////////////////////////////////////////////////////////
//����
void SListSort(SList *phead)
{
	assert(phead != NULL);
	if (SListLength(phead) <= 1){
		return;
	}
	SListNode *tmp = *phead, *prev = NULL;
	SListNode *p = *phead;
	SListNode *q = p->next;
	p->next = NULL;
	while (q != NULL){
		p = q;
		q = q->next;
		while (tmp != NULL&&p->data > tmp->data){
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL){
			p->next = *phead;
			*phead = p;
		}
		else{
			p->next = prev->next;
			prev->next = p;
		}
		tmp = *phead;
		prev = NULL;
	}
}
/////////////////////////////////////////////////////////////////////////
//������
size_t SListLength(SList *phead)
{
	size_t size = 0;
	SListNode *p = *phead;
	while (p != NULL){
		size++;
		p = p->next;
	}
	return size;
}


/////////////////////////////////////////////////////////////////
//��ȡ��ͷԪ��
ElemType SListFront(SList phead)
{
	assert(phead != NULL);
	return phead->data;
}
/////////////////////////////////////////////////////////////////
//��ȡ��βԪ��
ElemType SListBack(SList phead)
{
	assert(phead != NULL);
	SListNode *p = phead;
	while (p != NULL){
		p = p->next;
	}
	return p->data;
}


////////////////////////////////////////////////////////////////////////////
//���
void SListClear(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = NULL;
	while (*phead != NULL)
	{
		p = *phead;
		*phead = p->next;
		free(p);
	}
}
//////////////////////////////////////////////////////////////////////////////
//����
void SListDestory(SList *phead)
{
	SListClear(phead);
}
//////////////////////////////////////////////////////////////////////////////
//��ת
void SListReverse(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	p->next = NULL;
	SListNode *q = p->next;
	while(q != NULL){
		p = q;
		q = q->next;
		p->next=*phead;
		*phead = p;
	}

}

#endif