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

//��ʼ��
void BstInit(BSTree *bst){
	*bst = NULL;
}
//����
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
//����Сֵ
BstElemType BstMin(BSTree bst)
{
	//1.�Լ�д��
	//if (bst == NULL)
	//	return NULL;
	//BstElemType n;
	//while (bst->leftChild != NULL){
	//	bst = bst->leftChild;
	//}
	//n = bst->data;
	//return n;
	//2.���ݹ�ķ���
	assert(bst != NULL);
	while (bst->leftChild != NULL){
		bst = bst->leftChild;
	}
	return bst->data;

	//3.�ݹ�ķ���
	assert(bst != NULL);
	if (bst->leftChild == NULL)
		return bst->data;
	else
		return BstMin(bst->leftChild);
}
//�����ֵ
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
//�ѵ�����
void BstSortPrint(BSTree bst)
{
	if (bst == NULL)
		return;
	else
	{//�������
		BstSortPrint(bst->leftChild);
		printf("%d", bst->data);
		BstSortPrint(bst->rightChild);
	}
}
//���Ҷ���Ŀ��ֵ
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
//ɾ��
bool BstDelete(BSTree *bst, BinTreeSearch *p)
{
	//1.����bst��Ϊ��
	if (bst != NULL){
		//2.��ɾ����ֵ�ȸ��ڵ�С������������ݹ���
		if (p->data < (*bst)->data)
			BstDelete(&(*bst)->leftChild, p);
		//3.��ɾ����ֵ�ȸ��ڵ������������ݹ���
		if (p->data>(*bst)->data)
			BstDelete(&(*bst)->rightChild, p);
	}
	//ɾ��
	else{
		//1.ɾ�������Ҷ�ӽڵ�
		//2.ɾ���������������û��������
		//3.ɾ�����û������������������
		//4.ɾ�����������������������
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