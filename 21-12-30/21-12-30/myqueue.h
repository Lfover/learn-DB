#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <assert.h>
#define ElemType int

typedef struct ListQueue{
	ElemType data;
	struct ListQueue *next;
}ListQueue;
typedef ListQueue *LQueue;
//��ʼ��
void LinkQueueInit(LQueue *lq);
//��
void LinkQueueAdd(LQueue *lq, ElemType x);
//ɾ
void LinkQueueDel(LQueue *lq);
//��
void LinkQueueChange(LQueue *lq, ElemType x, ElemType y);
//��
ListQueue *LinkQueueFind(LQueue *lq, ElemType x);
//��ʾ
void ListQueueShow(LQueue lq);
//////////////////////////////////////////////
void LinQueueInit(LQueue *lq)
{
	assert(lq);
	*lq = NULL;
}
//����ͷ��
void LinkQueueAdd(LQueue *lq, ElemType x)
{
	assert(lq);
	//����ռ�
	ListQueue *t = (ListQueue *)malloc(sizeof(ListQueue));
	assert(t);
	t->data = x;
	t->next = *lq;
	//�ı�ͷָ��λ��
	*lq = t;
}
//ɾ��βɾ��
void LinkQueueDel(LQueue *lq)
{
	assert(lq);
	
	if (*lq == NULL)
		return;
    ListQueue *p = *lq;
	if (p->next == NULL)
	{
		*lq = NULL;
		free(p);
	}
    
	ListQueue *prev = NULL;
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	free(p);
}
//��
void LinkQueueChange(LQueue *lq, ElemType x, ElemType y)
{
	assert(lq);
	ListQueue *p = *lq;
	while (p != NULL)
	{
		if (p->data == x)
		{
			p->data = y;
			printf("�޸ĳɹ�\n");
			return;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("û��Ҫ�޸ĵ�Ŀ��ֵ\n");
		return;
	}
}
//��
ListQueue *LinkQueueFind(LQueue *lq, ElemType x)
{
	assert(lq);
	ListQueue *p = *lq;
	while (p != NULL)
	{
		if (p->data == x)
		{
			printf("�ҵ���\n");
			return p;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("û��Ŀ��ֵ\n");
		return;
	}

}
//��ʾ
void ListQueueShow(LQueue lq)
{
	if (lq == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	ListQueue *p = lq;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
#endif