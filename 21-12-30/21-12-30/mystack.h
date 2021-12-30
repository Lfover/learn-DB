//#ifndef _MYSTACK_H_
//#define _MYSTACK_H_
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <Windows.h>
//#include <assert.h>
//#define ElemType int
////��ջ
//typedef struct LinkStackNode{
//	ElemType data;
//	struct LinkStackNode *next;
//}LinkStack;
//typedef LinkStack *LStack;
//
////��ʼ��
//void LinkStackInit(LStack *ls);
////��
//void LinkStackAdd(LStack *ls, ElemType x);
////ɾ
//void LinkStackDel(LStack *ls);
////��
//void LinkStackChange(LStack *ls, ElemType x,ElemType y);
////��
//LinkStack *LinkStackFind(LStack *ls, ElemType x);
////��ʾ
//void LinkStackShow(LStack ls);
///////////////////////////////////////////////
////��ʼ��
//void LinkStackInit(LStack *ls)
//{
//	assert(ls);
//	*ls = NULL;
//}
////��(ͷ)
//void LinkStackAdd(LStack *ls, ElemType x)
//{
//	assert(ls);
//	LinkStack *t = (LinkStack *)malloc(sizeof(LinkStack));
//	assert(t);
//	t->data = x;
//	t->next = *ls;
//	*ls = t;
//}
////ɾ
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
//		printf("ջΪ�գ�����ɾ��\n");
//		return;
//	}
//}
////��
//void LinkStackChange(LStack *ls, ElemType x, ElemType y)
//{
//	assert(ls);
//	LinkStack *p = *ls;
//	while (p != NULL)
//	{
//		if (p->data == x)
//		{
//			p->data = y;
//			printf("�޸ĳɹ�\n");
//			return;
//		}
//		p = p->next;
//	}
//	if (p == NULL)
//	{
//		printf("��Ҫɾ����Ŀ��ֵ������\n");
//	}
//}
//
////��
//LinkStack *LinkStackFind(LStack *ls, ElemType x)
//{
//	assert(ls);
//	LinkStack *p = *ls;
//	while (p != NULL)
//	{
//		if (p->data == x)
//		{
//			printf("�ҵ���\n");
//			return p;
//		}
//		p = p->next;
//	}
//	if (p == NULL)
//	{
//		printf("û�����ֵ\n");
//		return NULL;
//	}
//}
//
////��ʾ
//void LinkStackShow(LStack ls)
//{
//	//assert(ls);
//	if (ls == NULL)
//	{
//		printf("ջΪ��\n");
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