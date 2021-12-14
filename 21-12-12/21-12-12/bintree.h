#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#pragma warning(disable:4996)
//#include <vld>

#define ElemType int
#define BTElemType char
typedef struct Queue{
	char data;
	struct Queue *next;
}Queue;
typedef struct BinTreeNode
{
	BTElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef BinTreeNode *BinTree;

void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);//因为可能要改变二叉树的根节点，所以传递地址
BinTree BinTreeCreate_1();
BinTree BinTreeCreate_2(const char *s,int *i);
int Size(BinTree t);
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t); 
void BinTreeLRV(BinTree t);
void BinTreelevel(BinTree t);
int Height(BinTree t);
BinTreeNode *Left(BinTreeNode *p);
BinTreeNode *Right(BinTreeNode *p);
BinTreeNode *BinTreeFind(BinTree t, BTElemType key);
BinTreeNode *BinTreeParent(BinTree t, BinTreeNode *p);
BinTreeNode *BinTreeCopy(BinTree t);
bool Equal(BinTree t1, BinTree t2);
//////////////////////////////////////////////////////////////
//初始化
void BinTreeInit(BinTree *t)//BinTreeNode **t;
{
	*t = NULL;
}
//创建
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
//创建_1
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
//创建2
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
//求二叉树结点个数
int Size(BinTree t)
{
	assert(t);
	if (t == NULL){
		return 0;
	}
	else{
		return Size(t->leftChild) + Size(t->rightChild) + 1;
	}
}
//先序遍历
void BinTreeVLR(BinTree t)
{
	assert(t);
	if (t != NULL){
		printf("%c", t->data);
		BinTreeVLR(t->leftChild);
		BinTreeVLR(t->rightChild);
	}
}
//中序遍历
void BinTreeLVR(BinTree t)
{
	assert(t);
	if (t != NULL){		
		BinTreeLVR(t->leftChild);
        printf("%c", t->data);
		BinTreeLVR(t->rightChild);
	}
}
//后序遍历
void BinTreeLRV(BinTree t)
{
	assert(t);
	if (t != NULL){
		BinTreeLRV(t->leftChild);
		BinTreeLRV(t->rightChild);
		printf("%c", t->data);
	}
}
//层次遍历
void BinTreelevel(BinTree t)
{
	assert(t);
	//定义队列
	//队列初始化
	//将根节点入队
	//判断队列是否为空
	//取对头元素
	//出队
	//将第一个层次的结点输出
}
//高度
int Height(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) : Height(t->rightChild);
}
//左子树
BinTreeNode *Left(BinTreeNode *p)
{
	assert(p);
	return p->leftChild;
}
//右子树
BinTreeNode *Right(BinTreeNode *p)
{
	assert(p);
	return p->rightChild;
}
//查找
BinTreeNode *BinTreeFind(BinTree t, BTElemType key)
{
	if (t == NULL||t->data == key)
		return t;
	BinTreeNode *p = BinTreeFind(t->leftChild,key);
	if (p != NULL)
		return p;
	return BinTreeFind(t->rightChild,key);
}
//查找父节点
BinTreeNode *BinTreeParent(BinTree t, BinTreeNode *p)
{
	if (t == NULL || p==NULL||t->data==p->data)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	BinTreeNode *p = BinTreeParent(t->leftChild, p);
	if (p != NULL)
		return p;
	return BinTreeParent(t->rightChild, p);

}
BinTreeNode *BinTreeCopy(BinTree t);
bool Equal(BinTree t1, BinTree t2);
#endif //_BINTREE_H_