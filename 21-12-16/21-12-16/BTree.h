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
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k <= 0)
		return 0;
	if (root != NULL&&k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL || root->data == x)
		return root;
	BTNode *p = BinaryTreeFind(root->left, x);
	if (p != NULL)
		return p;
	return BinaryTreeFind(root->right, x);
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		printf("%c", root->data);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		BinaryTreeInOrder(root->left);
		printf("%c", root->data);
		BinaryTreeInOrder(root->right);
	}
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		BinaryTreeInOrder(root->left);
		BinaryTreeInOrder(root->right);
		printf("%c", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);



BinTree BinTreeCreate_4(const char *lrv, const char *lvr, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lrv[n-1] != lvr[k])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];
	t->leftChild = BinTreeCreate_4(lrv,lvr,k);
	t->rightChild = BinTreeCreate_4(lrv+k,lvr+1+k,n-k-1);
	return t;
}
#endif//二叉树


int main()
{
	Node* head, *tail;
	// 初始化无结点时
	head = tail = nullptr;
	// 加入一个结点
	Node* node = new Node();
	head = tail = node;
	// 在加入一个结点
	Node* node1 = new Node();
	tail->next = node1;
	tail = tail->next;	// tail = node1;
	assert(p != null);
	if (p == 0)
	{
		cout <<
			return;
	}*p, x;
	// p = null(0) -》 应该去终止程序
	// p == null -> true
	// p -> false
	// p != null -> false
	assert(p != null);
	asser(p);
	if (p == NULL){	//判断空指针 

	}
}

void initLinkList(Node *head)
{

}

void insertNode(Node* head, int x)
{
	// 当链表为空的时候
	if (head == nullptr)
	{
		head = new Node();
		return;
	}
	// 链表有结点
	// 1. 找到链表的尾部
	Node* tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	// 2. 向链表尾部插入一个节点
	Node* node = new Node(x);
	tmp->next = node;
	
}
