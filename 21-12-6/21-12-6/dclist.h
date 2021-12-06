#ifndef _DCLIST_H_
#define _DCLIST_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* pHead);
// 双向链表打印
void ListPrint(ListNode* pHead);
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* pHead);
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
////////////////////////////////////////////////////////////////////////////////////////////////
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
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
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *head = pHead;
	if (head->next == pHead){//空表
		return;
	}
	ListNode *p = pHead->prev;
	p->prev->next = pHead;
	pHead->prev = p->prev;
	free(p);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	s->prev = pHead;
	s->next = pHead->next;
	pHead->next->prev = s;
	pHead->next = s;
}
// 双向链表头删
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
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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