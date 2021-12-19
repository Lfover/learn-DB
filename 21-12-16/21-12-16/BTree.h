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
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k <= 0)
		return 0;
	if (root != NULL&&k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL || root->data == x)
		return root;
	BTNode *p = BinaryTreeFind(root->left, x);
	if (p != NULL)
		return p;
	return BinaryTreeFind(root->right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		printf("%c", root->data);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		BinaryTreeInOrder(root->left);
		printf("%c", root->data);
		BinaryTreeInOrder(root->right);
	}
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	assert(root);
	if (root != NULL){
		BinaryTreeInOrder(root->left);
		BinaryTreeInOrder(root->right);
		printf("%c", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
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
#endif//������


int main()
{
	Node* head, *tail;
	// ��ʼ���޽��ʱ
	head = tail = nullptr;
	// ����һ�����
	Node* node = new Node();
	head = tail = node;
	// �ڼ���һ�����
	Node* node1 = new Node();
	tail->next = node1;
	tail = tail->next;	// tail = node1;
	assert(p != null);
	if (p == 0)
	{
		cout <<
			return;
	}*p, x;
	// p = null(0) -�� Ӧ��ȥ��ֹ����
	// p == null -> true
	// p -> false
	// p != null -> false
	assert(p != null);
	asser(p);
	if (p == NULL){	//�жϿ�ָ�� 

	}
}

void initLinkList(Node *head)
{

}

void insertNode(Node* head, int x)
{
	// ������Ϊ�յ�ʱ��
	if (head == nullptr)
	{
		head = new Node();
		return;
	}
	// �����н��
	// 1. �ҵ������β��
	Node* tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	// 2. ������β������һ���ڵ�
	Node* node = new Node(x);
	tmp->next = node;
	
}
