#ifndef _DCLIST_H_
#define _DCLIST_H_
#include "Common.h"

//������
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
//�����ռ�
DCListNode *_Buynode(ElemType v = ElemType())
{
	DCListNode *_S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(_S != NULL);
	_S->data = v;
	_S->next = _S->prev = _S;
	return _S;
}
//��ʼ��
void DCListInit(DCList *phead)
{
	 *phead = _Buynode();
}
//β��
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
//��ʾ
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
//ͷ��
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
//βɾ
void DCListPopBack(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->next == head){//ע���ж������Ƿ�Ϊ��
		return;
	}
	DCListNode *p = head->prev;
	p->prev->next = head;
	head->prev = p->prev;
	free(p);
}
//ͷɾ
void DCListPopFront(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->next == head)//�п�
		return;
	DCListNode *p = head->next;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}
//����
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
//��ͷ
ElemType DCListFront(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->next->data;
}
//��β
ElemType DCListBack(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->prev->data;
}
//���
void DCListClear(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;//����p
	}
}
void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;//Ԥ��Ұָ��
}
//����
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
//��ֵɾ��
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
//����
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