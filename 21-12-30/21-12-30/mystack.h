//#ifndef _MYSTACK_H_
//#define _MYSTACK_H_
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <Windows.h>
//#include <assert.h>
//#define ElemType int
////链栈
//typedef struct LinkStackNode{
//	ElemType data;
//	struct LinkStackNode *next;
//}LinkStack;
//typedef LinkStack *LStack;
//
////初始化
//void LinkStackInit(LStack *ls);
////增
//void LinkStackAdd(LStack *ls, ElemType x);
////删
//void LinkStackDel(LStack *ls);
////改
//void LinkStackChange(LStack *ls, ElemType x,ElemType y);
////查
//LinkStack *LinkStackFind(LStack *ls, ElemType x);
////显示
//void LinkStackShow(LStack ls);
///////////////////////////////////////////////
////初始化
//void LinkStackInit(LStack *ls)
//{
//	assert(ls);
//	*ls = NULL;
//}
////增(头)
//void LinkStackAdd(LStack *ls, ElemType x)
//{
//	assert(ls);
//	LinkStack *t = (LinkStack *)malloc(sizeof(LinkStack));
//	assert(t);
//	t->data = x;
//	t->next = *ls;
//	*ls = t;
//}
////删
//void LinkStackDel(LStack *ls)
//{
//	assert(ls);
//	if (*ls != NULL)
//	{
//		LinkStack *p = *ls;
//		*ls = p->next;
//		free(p);
//	}
//	else
//	{
//		printf("栈为空，不能删除\n");
//		return;
//	}
//}
////改
//void LinkStackChange(LStack *ls, ElemType x, ElemType y)
//{
//	assert(ls);
//	LinkStack *p = *ls;
//	while (p != NULL)
//	{
//		if (p->data == x)
//		{
//			p->data = y;
//			printf("修改成功\n");
//			return;
//		}
//		p = p->next;
//	}
//	if (p == NULL)
//	{
//		printf("想要删除的目标值不存在\n");
//	}
//}
//
////查
//LinkStack *LinkStackFind(LStack *ls, ElemType x)
//{
//	assert(ls);
//	LinkStack *p = *ls;
//	while (p != NULL)
//	{
//		if (p->data == x)
//		{
//			printf("找到了\n");
//			return p;
//		}
//		p = p->next;
//	}
//	if (p == NULL)
//	{
//		printf("没有这个值\n");
//		return NULL;
//	}
//}
//
////显示
//void LinkStackShow(LStack ls)
//{
//	//assert(ls);
//	if (ls == NULL)
//	{
//		printf("栈为空\n");
//		return;
//	}
//	LinkStack *p = ls;
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//#endif