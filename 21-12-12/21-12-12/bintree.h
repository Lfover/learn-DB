#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define ElemType char
///////////////////////////////////////////////////////////////////
//��ջ
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
bool LinkStackEmpty(LinkStack *pst);
//////////////////////////////////////////////////////////////////////////////////
//��ʼ��
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
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
	assert(pst != NULL&&*pst != NULL);
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
bool LinkStackEmpty(LinkStack *pst)
{
	assert(pst);
	return *pst == NULL;
}

//////////////////////////////////////////////////////////////////

#define BTElemType char
typedef struct Queue{
	char data;
	struct Queue *next;
}Queue;
////////////////////////////////////////////////////////////////////////

typedef struct BinTreeNode
{
	BTElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;
typedef BinTreeNode *BinTree;
//����������
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);//��Ϊ����Ҫ�ı�������ĸ��ڵ㣬���Դ��ݵ�ַ
BinTree BinTreeCreate_1();
BinTree BinTreeCreate_2(const char *s,int *i);
BinTree BinTreeCreate_3(const char *vlr, const char *lvr,int n);
BinTree BinTreeCreate_4(const char *vlr, const char *lrv, int n);
//�������ı���
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t); 
void BinTreeLRV(BinTree t);
void BinTreelevel(BinTree t);

//�������ķǵݹ����
void BinTreeVLR_Nor(BinTree t);
void BinTreeLVR_Nor(BinTree t);
void BinTreeLRV_Nor(BinTree t);
void BinTreelevel_Nor(BinTree t);

//���������㷨
int Size(BinTree t);
int Height(BinTree t);
BinTreeNode *Left(BinTreeNode *p);
BinTreeNode *Right(BinTreeNode *p);
BinTreeNode *BinTreeFind(BinTree t, BTElemType key);
BinTreeNode *BinTreeParent(BinTree t, BinTreeNode *p);
BinTreeNode *BinTreeClone(BinTree t);
bool Equal(BinTree t1, BinTree t2);
//////////////////////////////////////////////////////////////
//��ʼ��
void BinTreeInit(BinTree *t)//BinTreeNode **t;
{
	*t = NULL;
}
//����
void BinTreeCreate(BinTree *t)
{
	assert(t);
	BTElemType item;
	scanf("%c", &item);
	if (item == '#'){
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate(&(*t)->leftChild);
		BinTreeCreate(&(*t)->rightChild);
	}
}
//����_1
BinTree BinTreeCreate_1()
{
	BTElemType item;
	scanf("%c", &item);
	if (item == '#'){
		return NULL;
	}
	else
	{
         BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		 assert(t != NULL);
		 t->data = item;
		 t->leftChild = BinTreeCreate_1();
		 t->rightChild = BinTreeCreate_1();
		 return t;
	}	
}
//����2
BinTree BinTreeCreate_2(const char *s, int *i)
{
	assert(s);
	if (s[(*i)] == '\0' || s[(*i)] == '#'){
		return NULL;
	}
	else{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = s[*i];
		(*i)++;
		t->leftChild = BinTreeCreate_2(s, i);
		(*i)++;
		t->rightChild = BinTreeCreate_2(s, i);
		return t;
	}
}
//����3
BinTree BinTreeCreate_3(const char *vlr, const char *lvr, int n)
{
	if (n == 0){
		return NULL;
	}
	int k = 0;
	while (vlr[0] != lvr[k]){
		k++;
	}
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];
	t->leftChild = BinTreeCreate_3(vlr + 1, lvr, k);
	t->rightChild = BinTreeCreate_3(vlr + k + 1, lvr + k + 1, n - k - 1);
	return t;
}
//����4
BinTree BinTreeCreate_4(const char *vlr, const char *lrv, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (vlr[0] != lrv[k])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lrv[k];
	t->leftChild = BinTreeCreate_4(vlr+1,);
	t->rightChild = BinTreeCreate_4();
}
//�������������
/*
	��ȱ�����DFS �ݹ� �� ջʵ��
	��ȱ�����BFS �ݹ� �� ����ʵ��
	��������� ����ʵ��
*/
int Size(BinTree t)
{
	assert(t);
	if (t == NULL){
		return 0;
	}
	else{
		// int le = Size(t->leftChild);
		// int ri = Size(t->rightChild);
		// return le + ri + 1;
		// return t == NULL ? 0 : Size(t->leftChild) + Size(t->rightChild) + 1;
		return Size(t->leftChild) + Size(t->rightChild) + 1;
	}
}
//�������
void BinTreeVLR(BinTree t)
{
	assert(t);
	if (t != NULL){
		printf("%c", t->data);
		BinTreeVLR(t->leftChild);
		BinTreeVLR(t->rightChild);
	}
}
//�������
void BinTreeLVR(BinTree t)
{
	assert(t);
	if (t != NULL){	
		BinTreeLVR(t->leftChild);
        printf("%c", t->data);
		BinTreeLVR(t->rightChild);
	}
}
//�������
void BinTreeLRV(BinTree t)
{
	if (t != NULL){
		BinTreeLRV(t->leftChild);
		BinTreeLRV(t->rightChild);
		printf("%c", t->data);
	}
}
//��α���
void BinTreelevel(BinTree t)
{
	assert(t);
	//�������
	//���г�ʼ��
	//�����ڵ����
	//�ж϶����Ƿ�Ϊ��
	//ȡ��ͷԪ��
	//����
	//����һ����εĽ�����
}
//�߶�
int Height(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) : Height(t->rightChild);
}
//������
BinTreeNode *Left(BinTreeNode *p)
{
	assert(p);
	return p->leftChild;
}
//������
BinTreeNode *Right(BinTreeNode *p)
{
	assert(p);
	return p->rightChild;
}
//���� 
BinTreeNode *BinTreeFind(BinTree t, BTElemType key)
{
	if (t == NULL || t->data == key)
		return t;
	BinTreeNode *p = BinTreeFind(t->leftChild,key);
	if (p != NULL)
		return p;
	return BinTreeFind(t->rightChild, key);
}
//���Ҹ��ڵ�
BinTreeNode *BinTreeParent(BinTree t, BinTreeNode *p)
{
	if (t == NULL || p==NULL || t->data==p->data)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	BinTreeNode *pt = BinTreeParent(t->leftChild, p);
	if (pt != NULL)
		return pt;
	return BinTreeParent(t->rightChild, p);

}
//��¡������
BinTreeNode *BinTreeClone(BinTree t)
{
	if (t == NULL)
		return NULL;
	else
	{// sizeof(m)  sizeof m
		BinTreeNode *bt = (BinTreeNode*)malloc(sizeof BinTreeNode);
		assert(bt != NULL);
		bt->data = t->data;
		bt->leftChild = BinTreeClone(t->leftChild);
		bt->rightChild = BinTreeClone(t->rightChild);
		return bt;
	}
}
//�ж������������Ƿ����
bool Equal(BinTree t1, BinTree t2)
{
	if (t1 == NULL && t2 == NULL){
		return true;
	}
	if ((t1 == NULL || t2 == NULL)){
		return false;
	}
	return (t1->data == t2->data) && Equal(t1->leftChild, t2->leftChild) && Equal(t1->rightChild, t2->rightChild);
}

//����
void BinTreeVLR_Nor(BinTree t)
{
	if (t != NULL){
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		while (!LinkStackEmpty(&st))
		{
			BinTreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c", p->data);
			if (p->rightChild != NULL)
				LinkStackPush(&st, p->rightChild);
			if (p->leftChild != NULL)
				LinkStackPush(&st, p->leftChild);
		}
		LinkStackDestroy(&st);
	}
}
//����
void BinTreeLVR_Nor(BinTree t)
{
	if (t != NULL){
		LinkStack st;
		LinkStackInit(&st);

		do
		{
			while (t != NULL){
				LinkStackPush(&st, t);
				t = t->leftChild;
			}
			BinTreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c", p->data);		
			if (p->rightChild != NULL)
			{
				t= p->rightChild;
			}
		}while (!LinkStackEmpty(&st) || t != NULL);
	}
}
//����
void BinTreeLRV_Nor(BinTree t)
{
	if (t != NULL){
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode *pre = NULL;
		do{
			if (t != NULL){
				LinkStackPush(&st, t);
				t = t->leftChild;
			}
			BinTreeNode *p = LinkStackTop(&st);
			
			if (p->rightChild == NULL||p->rightChild==pre)
			{
			 	LinkStackPop(&st);
			    printf("%c", p->data);
			    pre = p;
			}else
                t = p->rightChild;
		} while (!LinkStackEmpty(st));
}
void BinTreelevel_Nor(BinTree t)
{

}
#endif //_BINTREE_H_