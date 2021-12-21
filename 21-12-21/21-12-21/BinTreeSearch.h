#ifndef _BINTREESEARCH_H_
#define _BINTREESEARCH_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include <memory.h>
typedef int BstElemType;

typedef struct BinTreeSearch{
	BstElemType data;
	struct BinTreeSearch *leftChild;
	struct BinTreeSearch *rightChild;
}BinTreeSearch;

typedef BinTreeSearch* BSTree;

void BstInit(BSTree *bst);
bool BstInsert(BSTree *t, BstElemType x);
BstElemType BstMin(BSTree bst);
BstElemType BstMax(BSTree bst);
void BstSortPrint(BSTree bst);
BinTreeSearch *BstFind(BSTree bst, BstElemType key);
bool BstDelete(BSTree *bst, BinTreeSearch *P);

//初始化
void BstInit(BSTree *bst){
	*bst = NULL;
}
//插入
bool BstInsert(BSTree *t, BstElemType x)
{
	if (*t == NULL){
		*t = (BinTreeSearch*)malloc(sizeof(BinTreeSearch));
		if (*t == NULL)
			return false;
		(*t)->data = x;
		(*t)->leftChild = (*t)->rightChild = NULL;
		return true;
	}
	if (x < (*t)->data)
		return BstInsert(&(*t)->leftChild, x);
	else if (x>(*t)->data)
		return BstInsert(&(*t)->rightChild, x);
	else
		return false;
}
//求最小值
BstElemType BstMin(BSTree bst)
{
	//1.自己写的
	//if (bst == NULL)
	//	return NULL;
	//BstElemType n;
	//while (bst->leftChild != NULL){
	//	bst = bst->leftChild;
	//}
	//n = bst->data;
	//return n;
	//2.不递归的方法
	assert(bst != NULL);
	while (bst->leftChild != NULL){
		bst = bst->leftChild;
	}
	return bst->data;

	//3.递归的方法
	assert(bst != NULL);
	if (bst->leftChild == NULL)
		return bst->data;
	else
		return BstMin(bst->leftChild);
}
//求最大值
BstElemType BstMax(BSTree bst)
{
	if (bst == NULL)
		return NULL;
	BstElemType n;
	while (bst != NULL){
		bst = bst->rightChild;
	}
	n = bst->data;
	return n;
}
//堆的排序
void BstSortPrint(BSTree bst)
{
	if (bst == NULL)
		return;
	else
	{//中序遍历
		BstSortPrint(bst->leftChild);
		printf("%d", bst->data);
		BstSortPrint(bst->rightChild);
	}
}
//查找堆中目标值
BinTreeSearch *BstFind(BSTree bst, BstElemType key)
{
	if (bst == NULL){
		return NULL;
	}
	if (bst->data == key)
		return bst;
	else if (bst->data > key)
		BstFind(bst->leftChild,key);
	else
		return BstFind(bst->rightChild,key);
}
//删除
bool BstDelete(BSTree *bst, BinTreeSearch *p)
{
	//1.首先bst不为空
	if (bst != NULL){
		//2.想删除的值比根节点小，在左子树里递归找
		if (p->data < (*bst)->data)
			BstDelete(&(*bst)->leftChild, p);
		//3.想删除的值比根节点大，在右子树里递归找
		if (p->data>(*bst)->data)
			BstDelete(&(*bst)->rightChild, p);
	}
	//删除
	else{
		//1.删除结点是叶子节点
		//2.删除结点有左子树，没有右子树
		//3.删除结点没有右子树，有左子树
		//4.删除结点有左子树，有右子树
		if (p->leftChild == NULL&&p->rightChild == NULL){
			free(*bst);
			*bst = NULL;
		}
		else if (p->leftChild != NULL&&p->rightChild == NULL){
			*bst = p->leftChild;
			free(p);
		}
		else if (p->leftChild == NULL&&p->rightChild != NULL){
			*bst = p->rightChild;
			free(p);
		}
		else{
			BinTreeSearch *s = p->leftChild;
			while (p->rightChild != NULL)
				s = s->rightChild;
			p->data = s->data;
			BstDelete(&(p->leftChild), s);
		}
		return true;
	}
	return false;
}

#endif