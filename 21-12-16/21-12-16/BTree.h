#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>
typedef char BTDataType;
typedef struct BTreeNode{
	BTDataType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}BTNode;

typedef BTreeNode *BTree;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

////////////////////////////////////////////////////

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(a);
	if (a[*pi] == '\0' || a[*pi] == '#')
		return NULL;
	BTNode *T = (BTNode*)malloc(sizeof(BTNode));
	assert(T);
	T->data = a[*pi];
	(*pi)++;
	T->left = BinaryTreeCreate(a, n, pi);
	(*pi)++;
	T->right = BinaryTreeCreate(a, n, pi);
	return T;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root){
		BinaryTreeDestory(&(*root)->left);
		BinaryTreeDestory(&(*root)->right);
		free(*root);
		(*root) = NULL;
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root){
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root != NULL&&root->left == NULL&&root->right == NULL){
		return 1;
	}
	else{
		if (root == NULL)
			return 0;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
#endif//������