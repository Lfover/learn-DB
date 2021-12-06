#ifndef _DCLIST_H_
#define _DCLIST_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* pHead);
// ˫�������ӡ
void ListPrint(ListNode* pHead);
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
////////////////////////////////////////////////////////////////////////////////////////////////
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *p = (pHead)->next;
	while (p != pHead){
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = pHead->next;
	}
	free(pHead);
	pHead = NULL;
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *p = pHead->next;
	while (p != pHead){
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = pHead->prev;
	s->next = pHead;
	pHead->prev->next = s;
	pHead->prev = s;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *head = pHead;
	if (head->next == pHead){//�ձ�
		return;
	}
	ListNode *p = pHead->prev;
	p->prev->next = pHead;
	pHead->prev = p->prev;
	free(p);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	s->prev = pHead;
	s->next = pHead->next;
	pHead->next->prev = s;
	pHead->next = s;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *head = pHead;
	if (head->next = pHead){
		return;
	}
	ListNode *p = head->next;
		p->next->prev  = p->prev;
		p->prev->next  = p->next;
		free(p);
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode *p = pHead;
	while (p->next != pHead&&p->data !=x){
		p = p->next;
	}
	if (p->next == pHead){
		return NULL;
	}
	return p;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos != NULL);
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = x;
	s->next = pos;
	s->prev = pos->prev;
	pos->prev->next = s;
	pos->prev = s;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos != NULL);
	ListNode *p = pos->prev;
	ListNode *pp = pos->next;
	p->next = pp;
	pp->prev = p;
	free(pos);
}
#endif