#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <assert.h>
#define ElemType int

typedef struct linklist{
	ElemType data;
	struct linklist *next;
}linklist;

typedef linklist *Llist;

//初始化
void LlistInit(Llist *list);
//增
void LlistAdd(Llist *list,ElemType x);
//删
void LlistDel(Llist *list, ElemType x);
//改
void LlistChange(Llist *list, ElemType x, ElemType y);
//查
linklist* LlistFind(Llist *list, ElemType x);
//显示
void Show(Llist list);

/////////////////////////////////////////////////
//初始化
void LlistInit(Llist *list)
{
	assert(list);
	*list = NULL;
}
//增（尾插）
void LlistAdd(Llist *list,ElemType x)
{
	//申请空间
	linklist *t = (linklist *)malloc(sizeof(linklist));
	assert(t);
	t->data = x;
	t->next = NULL;
	linklist *p = *list;
	//如果插入的结点是第一个结点
	if (p == NULL)
		*list = t;
	else{
		//找到最后一个结点
		while (p->next != NULL)
			p = p->next;
		p->next = t;
	}
}
//删
void LlistDel(Llist *list, ElemType x)
{
	assert(list);
	//如果链表为空
	if (list == NULL)
	{
		printf("链表为空\n");
		return;
	}
	linklist* p = *list;
	//如果第一个结点为目标值
	if (p->data == x)
	{
		*list = p->next;
		return;
	}
	//要删除结点的前驱
	linklist *prev = *list;
	p = p->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			prev->next = p->next;
			free(p);
			printf("删除成功\n");
			return;
		}
		prev = p;
		p = p->next;
	}
	printf("要删除的值不存在\n");
}
//改
void LlistChange(Llist *list, ElemType x, ElemType y)
{
	assert(list);
	linklist *p = *list;
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
	printf("没有该值可以修改\n");
}
//查
linklist *LlistFind(Llist *list, ElemType x)
{
	assert(list);
	linklist *p = *list;
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
		printf("没找到\n");
		return NULL;
	}
}
//显示
void Show(Llist list)
{
	assert(list != NULL);
	linklist *head = list;
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


#endif