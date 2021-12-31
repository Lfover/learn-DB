#ifndef _BINSEARCHTREE_H_
#define _BINSEARCHTREE_H_
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int ElemType;

typedef struct BinSearchTree{
	ElemType data;
	struct BinSearchTree *left;
	struct BinSearchTree *right;
}BinSearchTree;

typedef BinSearchTree *BSTree;
//t�Ƕ���������
//p����Ҫ�ı�Ľ��
//��ʼ��
void BinSearchTreeInit(BSTree *t);
//��
bool BinSearchTreeInsert(BSTree *t, ElemType x);
//ɾ
bool BinSearchTreeDel(BSTree *t, BinSearchTree *p);
//��
//�޸ĺ����
void BinSearchTreeAdjust(BSTree *t, BinSearchTree *p);
bool BinSearchTreeChange(BSTree *t, BinSearchTree *p, int x);
//��
BinSearchTree *BinSearchTreeFind(BSTree t, ElemType x);
////////////////////////////////////////////////////////////////////////////////////
//��ʼ��
void BinSearchTreeInit(BSTree *t)
{
	(*t) = NULL;
}
//��
bool BinSearchTreeInsert(BSTree *t, ElemType x)
{
	//��Ϊ�յ�ʱ��ִ��������һ��if���������������ĵ�һ�����
	//����������ѭ�������������
	if (*t == NULL)
	{
		//t�������Ĳ�����
		*t = (BinSearchTree *)malloc(sizeof(BinSearchTree));
		(*t)->data = x;
		(*t)->left = NULL;
		(*t)->right = NULL;
		return true;
	}
	//�ڸ��ڵ��Ѿ������ˣ��ж�������ֵ�ȸ��ڵ�С�����Ǳȸ��ڵ��С�Ļ����������룬�������������
	if (x < (*t)->data)
	{
		//����Ϊ�����ڸ��ڵ�����������룬�ݹ���ã���ʱֻ��һ�����ڵ㣬���Ը��ڵ������Ϊ�գ����������if������ִ�в���
		return BinSearchTreeInsert(&(*t)->left, x);
	}
	else if (x > (*t)->data)
	{
		return BinSearchTreeInsert(&(*t)->right, x);
	}
	else
		//����Ľ��Ȳ����ڸ��ڵ㣬�ֲ�С�ڸ��ڵ㣬������������������ͬ�Ľ��
		return false;
}

//ɾ
bool BinSearchTreeDel(BSTree *t, BinSearchTree *p)
{
	//��������Ϊ�ն�û�ҵ�ɾ���Ľ��
	if ((*t) == NULL)
		return false;
	//��ɾ���Ľ��С�ڸ��ڵ㣬�ڸ��ڵ������������ɾ�����
	if (p->data < (*t)->data)
		BinSearchTreeDel(&(*t)->left, p);
	//��ɾ���Ľڵ���ڸ��ڵ㣬�ڸ��ڵ������������ɾ�����
	else if (p->data > (*t)->data)
		BinSearchTreeDel(&(*t)->right, p);
	//��СҲ���󣬾����ҵ�����ɾ���Ľ��
	else
	{//ɾ�����
		//������������Ϊ��
		if (p->left != NULL && p->right != NULL)
		{
			BinSearchTree *s = p->left;//s�Ǵ�ɾ�������������е����ֵ
			while (s->right != NULL)
				s = s->right;
			p->data = s->data;//p��ֵ��Ϊs��ֵ����p�������а�sɾ������
			BinSearchTreeDel(&p->left, s);
		}
		//������Ϊ�գ���������Ϊ�գ�������������Ϊ��
		else
		{
			//*t�Ǵ�ʱp����һ�����
			if (p->left != NULL)
				(*t) = p->left;
			else
				(*t) = p->right;
		}
	}
}
//����
void BinSearchTreeAdjust(BSTree *t, BinSearchTree *p)
{

}
//�ı�
bool BinSearchTreeChange(BSTree *t, BinSearchTree *p, int x)
{
	if ((*t) == NULL)
		return false;
	p->data = x;
	BinSearchTreeAdjust(t, p);
}
//��
BinSearchTree *BinSearchTreeFind(BSTree t, ElemType x)
{
	if (t == NULL)
		return NULL;
	if (t->data == x)
		return t;
	if (x < t->data)
		return BinSearchTreeFind(t->left, x);
	else if (x>t->data)
		return BinSearchTreeFind(t->right, x);
}
#endif