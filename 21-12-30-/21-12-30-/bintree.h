#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <assert.h>
typedef char ElemType;
typedef struct BinTree{
	ElemType data;
	struct BinTree *left;
	struct BinTree *right;
}BinTree;
typedef BinTree *BTree;
//����
BinTree *BinTreeCreate(char *str1, int n, char *str2, int m);
//����-�ݹ�
void BinTreeVLR(BTree bt);
//����-����
void BinTreeVLR_N(BTree bt);
//����-�ݹ�
void BinTreeLVR(BTree bt);
//����-����
void BinTreeLVR_N(BTree bt);
//����-�ݹ�
void BinTreeLRV(BTree bt);
//����-����
void BinTreeLRV_N(BTree bt);
//���ĸ߶�
int BinTreeHight(BTree bt);
//�Ƿ�Ϊ����
bool BinTreeSame(BTree bt, BTree bt1);
bool BinTreeSon(BTree bt, BTree bt1);
/////////////////////////////////////////////////////////////
//����
BinTree *BinTreeCreate(char *str1, int n, char *str2, int m)
{
	if (n == 0 || m == 0)
		return NULL;
	int k = 0;
	//�������������Ҹ��ڵ�
	while (str2[k] != str1[0])
		k++;
	BinTree *t = (BinTree *)malloc(sizeof(BinTree));
	assert(t);
	t->data = str2[k];
	t->left = BinTreeCreate(str1 + 1, k, str2, k);
	t->right = BinTreeCreate(str1 + k + 1, n - k - 1, str2 + k + 1, n - k - 1);
	return t;
}
//����
//1.�ݹ�
void BinTreeVLR(BTree bt)
{
	if (bt == NULL)
	{
		return;
	}
	if (bt != NULL)
	{
		printf("%c ", bt->data);//�����
		BinTreeVLR(bt->left);
		BinTreeVLR(bt->right);
	}
}
//2.����
void BinTreeVLR_N(BTree bt)
{
	if (bt == NULL)
		return;
	BTree *stk = (BTree *)malloc(sizeof(BTree) * 100);
	assert(stk);
	BinTree *node = bt;
	int top = 0;
	while (top > 0 || node != NULL)
	{
		while (node != NULL)
		{
			printf("%c ", node->data);
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		node = node->right;
	}
}
//����
//1.�ݹ�
void BinTreeLVR(BTree bt)
{
	if (bt == NULL)
	{
		return;
	}
	if (bt != NULL)
	{
		BinTreeLVR(bt->left);
		printf("%c ", bt->data);//���������������
		BinTreeLVR(bt->right);
	}
}
//2.����
void BinTreeLVR_N(BTree bt)
{
	if (bt == NULL)
		return;
	BTree *stk = (BTree *)malloc(sizeof(BTree) * 100);
	assert(stk);
	BinTree *node = bt;
	int top = 0;
	while (top > 0 || node != NULL)
	{
		while (node != NULL)
		{
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		printf("%c ", node->data);
		node = node->right;
	}
}
//����
//1.�ݹ�
void BinTreeLRV(BTree bt)
{
	if (bt == NULL)
	{
		return;
	}
	if (bt != NULL)
	{
		BinTreeLRV(bt->left);
		BinTreeLRV(bt->right);
		printf("%c ", bt->data);//�����������������
	}
}
//2.����
void BinTreeLRV_N(BTree bt)
{
	if (bt == NULL)
		return;
	BTree *stk = (BTree *)malloc(sizeof(BTree) * 100);
	assert(stk);
	BinTree *node = bt;
	BinTree *prev = NULL;//ǰ�����
	int top = 0;
	while (top > 0 || node != NULL)
	{
		//�ݹ鵽��������
		while (node != NULL)
		{
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		//������Ϊ�ջ��������Ѿ������ʹ���
		if (node->right == NULL || node->right == prev)
		{
			printf("%c ", node->data);
			prev = node;//ָ��node���ʹ���ǰһ�����
			node = NULL;
		}
		else
			//��������Ϊ����û�����ʹ�
		{
			stk[++top] = node;
			node = node->right;
		}
	}
}
//���ĸ߶�
int BinTreeHight(BTree bt)
{
	if (bt == NULL)
		return 0;
	int L = BinTreeHight(bt->left);
	int R = BinTreeHight(bt->right);
	return (L > R ? L : R) + 1;//max(�������߶ȣ��������߶�)+1
}
//�ж��������Ƿ���ͬ
bool BinTreeSame(BTree bt, BTree bt1)
{
	if (bt == NULL && bt1 == NULL)
		return true;
	if (bt == NULL || bt1 == NULL)
		return false;
	//���ֵ��ͬ��������������ȫ��ͬ
	return bt->data==bt1->data && BinTreeSame(bt->left, bt1->left) && BinTreeSame(bt->right, bt1->right);
}
//�ж�һ�����Ƿ�Ϊ����
bool BinTreeSon(BTree bt, BTree bt1)
{
	if (bt1 == NULL)
		return true;
	if (bt == NULL)
		return false;
	//�Ӹ��ڵ㿪ʼ�Ƚϣ���ͬ�������棬��ͬ����bt���������������Ƿ���bt1
	if (BinTreeSame(bt, bt1))
		return true;
	return BinTreeSon(bt->left, bt1) || BinTreeSon(bt->right, bt1);
}
#endif