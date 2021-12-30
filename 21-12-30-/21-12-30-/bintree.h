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
//构造
BinTree *BinTreeCreate(char *str1, int n, char *str2, int m);
//先序-递归
void BinTreeVLR(BTree bt);
//先序-迭代
void BinTreeVLR_N(BTree bt);
//中序-递归
void BinTreeLVR(BTree bt);
//中序-迭代
void BinTreeLVR_N(BTree bt);
//后序-递归
void BinTreeLRV(BTree bt);
//后序-迭代
void BinTreeLRV_N(BTree bt);
//树的高度
int BinTreeHight(BTree bt);
//是否为子树
bool BinTreeSame(BTree bt, BTree bt1);
bool BinTreeSon(BTree bt, BTree bt1);
/////////////////////////////////////////////////////////////
//创建
BinTree *BinTreeCreate(char *str1, int n, char *str2, int m)
{
	if (n == 0 || m == 0)
		return NULL;
	int k = 0;
	//在中序序列里找根节点
	while (str2[k] != str1[0])
		k++;
	BinTree *t = (BinTree *)malloc(sizeof(BinTree));
	assert(t);
	t->data = str2[k];
	t->left = BinTreeCreate(str1 + 1, k, str2, k);
	t->right = BinTreeCreate(str1 + k + 1, n - k - 1, str2 + k + 1, n - k - 1);
	return t;
}
//先序
//1.递归
void BinTreeVLR(BTree bt)
{
	if (bt == NULL)
	{
		return;
	}
	if (bt != NULL)
	{
		printf("%c ", bt->data);//先输出
		BinTreeVLR(bt->left);
		BinTreeVLR(bt->right);
	}
}
//2.迭代
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
//中序
//1.递归
void BinTreeLVR(BTree bt)
{
	if (bt == NULL)
	{
		return;
	}
	if (bt != NULL)
	{
		BinTreeLVR(bt->left);
		printf("%c ", bt->data);//遍历完左子树输出
		BinTreeLVR(bt->right);
	}
}
//2.迭代
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
//后序
//1.递归
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
		printf("%c ", bt->data);//遍历完左右子树输出
	}
}
//2.迭代
void BinTreeLRV_N(BTree bt)
{
	if (bt == NULL)
		return;
	BTree *stk = (BTree *)malloc(sizeof(BTree) * 100);
	assert(stk);
	BinTree *node = bt;
	BinTree *prev = NULL;//前驱结点
	int top = 0;
	while (top > 0 || node != NULL)
	{
		//递归到最左子树
		while (node != NULL)
		{
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		//右子树为空或右子树已经被访问过了
		if (node->right == NULL || node->right == prev)
		{
			printf("%c ", node->data);
			prev = node;//指到node访问过的前一个结点
			node = NULL;
		}
		else
			//右子树不为空且没被访问过
		{
			stk[++top] = node;
			node = node->right;
		}
	}
}
//树的高度
int BinTreeHight(BTree bt)
{
	if (bt == NULL)
		return 0;
	int L = BinTreeHight(bt->left);
	int R = BinTreeHight(bt->right);
	return (L > R ? L : R) + 1;//max(左子树高度，右子树高度)+1
}
//判断两棵树是否相同
bool BinTreeSame(BTree bt, BTree bt1)
{
	if (bt == NULL && bt1 == NULL)
		return true;
	if (bt == NULL || bt1 == NULL)
		return false;
	//结点值相同，且左右子树完全相同
	return bt->data==bt1->data && BinTreeSame(bt->left, bt1->left) && BinTreeSame(bt->right, bt1->right);
}
//判断一棵树是否为子树
bool BinTreeSon(BTree bt, BTree bt1)
{
	if (bt1 == NULL)
		return true;
	if (bt == NULL)
		return false;
	//从根节点开始比较，相同，返回真，不同，在bt的左右子树里找是否有bt1
	if (BinTreeSame(bt, bt1))
		return true;
	return BinTreeSon(bt->left, bt1) || BinTreeSon(bt->right, bt1);
}
#endif