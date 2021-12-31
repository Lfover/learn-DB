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
//t是二叉搜索树
//p是想要改变的结点
//初始化
void BinSearchTreeInit(BSTree *t);
//增
bool BinSearchTreeInsert(BSTree *t, ElemType x);
//删
bool BinSearchTreeDel(BSTree *t, BinSearchTree *p);
//改
//修改后调整
void BinSearchTreeAdjust(BSTree *t, BinSearchTree *p);
bool BinSearchTreeChange(BSTree *t, BinSearchTree *p, int x);
//查
BinSearchTree *BinSearchTreeFind(BSTree t, ElemType x);
////////////////////////////////////////////////////////////////////////////////////
//初始化
void BinSearchTreeInit(BSTree *t)
{
	(*t) = NULL;
}
//增
bool BinSearchTreeInsert(BSTree *t, ElemType x)
{
	//树为空的时候执行下面这一行if，插入了搜索树的第一个结点
	//在主函数里循环调用这个函数
	if (*t == NULL)
	{
		//t是新增的插入结点
		*t = (BinSearchTree *)malloc(sizeof(BinSearchTree));
		(*t)->data = x;
		(*t)->left = NULL;
		(*t)->right = NULL;
		return true;
	}
	//在根节点已经存在了，判断想插入的值比根节点小，还是比根节点大，小的话在左树插入，大的在右树插入
	if (x < (*t)->data)
	{
		//左树为例，在根节点的左子树插入，递归调用，此时只有一个根节点，所以根节点的左树为空，满足上面的if条件，执行插入
		return BinSearchTreeInsert(&(*t)->left, x);
	}
	else if (x > (*t)->data)
	{
		return BinSearchTreeInsert(&(*t)->right, x);
	}
	else
		//插入的结点既不大于根节点，又不小于根节点，搜索二叉树不存在相同的结点
		return false;
}

//删
bool BinSearchTreeDel(BSTree *t, BinSearchTree *p)
{
	//遍历到树为空都没找到删除的结点
	if ((*t) == NULL)
		return false;
	//想删除的结点小于根节点，在根节点的左子树中找删除结点
	if (p->data < (*t)->data)
		BinSearchTreeDel(&(*t)->left, p);
	//想删除的节点大于根节点，在根节点的右子树中找删除结点
	else if (p->data > (*t)->data)
		BinSearchTreeDel(&(*t)->right, p);
	//不小也不大，就是找到了想删除的结点
	else
	{//删除结点
		//左右子树都不为空
		if (p->left != NULL && p->right != NULL)
		{
			BinSearchTree *s = p->left;//s是待删除结点的左子树中的最大值
			while (s->right != NULL)
				s = s->right;
			p->data = s->data;//p的值改为s的值，在p的左树中把s删掉即可
			BinSearchTreeDel(&p->left, s);
		}
		//左子树为空，或右子树为空，或左右子树都为空
		else
		{
			//*t是此时p的上一个结点
			if (p->left != NULL)
				(*t) = p->left;
			else
				(*t) = p->right;
		}
	}
}
//调整
void BinSearchTreeAdjust(BSTree *t, BinSearchTree *p)
{

}
//改变
bool BinSearchTreeChange(BSTree *t, BinSearchTree *p, int x)
{
	if ((*t) == NULL)
		return false;
	p->data = x;
	BinSearchTreeAdjust(t, p);
}
//查
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