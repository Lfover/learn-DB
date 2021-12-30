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
//初始化
void LinkQueueInit(LQueue *lq);
//增
void LinkQueueAdd(LQueue *lq, ElemType x);
//删
void LinkQueueDel(LQueue *lq);
//改
void LinkQueueChange(LQueue *lq, ElemType x, ElemType y);
//查
ListQueue *LinkQueueFind(LQueue *lq, ElemType x);
//显示
void ListQueueShow(LQueue lq);
//////////////////////////////////////////////
void LinQueueInit(LQueue *lq)
{
	assert(lq);
	*lq = NULL;
}
//增（头）
void LinkQueueAdd(LQueue *lq, ElemType x)
{
	assert(lq);
	//申请空间
	ListQueue *t = (ListQueue *)malloc(sizeof(ListQueue));
	assert(t);
	t->data = x;
	t->next = *lq;
	//改变头指针位置
	*lq = t;
}
//删（尾删）
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
//改
void LinkQueueChange(LQueue *lq, ElemType x, ElemType y)
{
	assert(lq);
	ListQueue *p = *lq;
	while (p != NULL)
	{
		if (p->data == x)
		{
			p->data = y;
			printf("修改成功\n");
			return;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("没有要修改的目标值\n");
		return;
	}
}
//查
ListQueue *LinkQueueFind(LQueue *lq, ElemType x)
{
	assert(lq);
	ListQueue *p = *lq;
	while (p != NULL)
	{
		if (p->data == x)
		{
			printf("找到了\n");
			return p;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("没有目标值\n");
		return;
	}

}
//显示
void ListQueueShow(LQueue lq)
{
	if (lq == NULL)
	{
		printf("队列为空\n");
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