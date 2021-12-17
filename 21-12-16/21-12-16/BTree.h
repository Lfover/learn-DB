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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
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

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root){
		BinaryTreeDestory(&(*root)->left);
		BinaryTreeDestory(&(*root)->right);
		free(*root);
		(*root) = NULL;
	}
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root){
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
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
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
#endif//二叉树