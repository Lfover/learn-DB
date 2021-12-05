#ifndef _STACK_H_
#define _STACK_H_
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <Windows.h>
#define ElemType int
#define STACK_DEFAULT_SIZE 8
//˳��ջ
typedef struct SeqStack
{
	ElemType *base;
	size_t capacity;
	int top;
}SeqStack;

void SeqStackInit(SeqStack *pst, int sz);
void SeqStackPush(SeqStack *pst, ElemType x);
void SeqStackPop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst);//ȡջ��Ԫ��,�з���ֵ
void SeqStackTop(SeqStack *pst,ElemType *top_val);//�޷���ֵ
void SeqStackShow(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);
int SeqStackSize(SeqStack *pst);
//////////////////////////////////////////////////////////////////////////
bool Full(SeqStack *pst){
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool Empty(SeqStack *pst){
	assert(pst != NULL);
	return pst->top == 0;
}
void SeqStackInit(SeqStack *pst,int sz)
{
	assert(pst != NULL);
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType)*pst->capacity);
	pst->top = 0;
}
//��ջ
void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (Full(pst)){
		printf("ջ���������ܲ���\n");
		return;
	}
	pst->base[pst->top++] = x;
}
//��ջ
void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (Empty(pst)){
		printf("ջ�ѿգ����ܳ�ջ\n");
		return;
	}
	pst->top--;
}
//ȡջ��Ԫ��
ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	assert(!(Empty(pst)));
	//if (Empty(pst)){
	//	printf("ջ�ѿգ����ܳ�ջ\n");
	//	return;
	//}
	return pst->base[pst->top - 1];
}
//ջ��Ԫ��
void SeqStackTop(SeqStack *pst, ElemType *top_val)
{
	assert(pst != NULL);
	if (Empty(pst)){
		printf("ջ�ѿգ����ܳ�ջ\n");
		return;
	}
	*top_val = pst->base[pst->top - 1];
}
//��ʾջ
void SeqStackShow(SeqStack *pst)
{
	assert(pst != NULL);
	if (Empty(pst)){
		return;
	}
	for (int i = pst->top-1; i >= 0; i--){
		printf("| %d |\n", pst->base[i]);
	}
}
//����
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->top = pst->capacity = 0;
}
//ջ��С
int SeqStackSize(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top;
}



typedef struct LinkStackNode{
	ElemType data;
	struct LinkStackNode *link;

}LinkStackNode;
typedef LinkStackNode *LinkStack;

void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackShow(LinkStack *pst);
int LinkStackSize(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);
//////////////////////////////////////////////////////////////////////////////////
//��ʼ��

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst=NULL;
}
//��ջ
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = *pst;
	*pst = node;
}
//��ջ
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst != NULL){
		LinkStackNode *p = *pst;
		*pst = p->link;
		free(p);
	}
}
//��ջջ��Ԫ��
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL&&*pst!=NULL);
	return (*pst)->data;
}
//��ջ��ʾ
void LinkStackShow(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while (p != NULL){
		printf("| %d |\n", p->data);
		p = p->link;
	}
}
//��ջ�Ĵ�С
int LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = *pst;
	while (p != NULL){
		size++;
		p = p->link;
	}
	return size;
}
void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while (p != NULL){
		*pst = p->link;
		free(p);
		p = *pst;
	}
}










#endif