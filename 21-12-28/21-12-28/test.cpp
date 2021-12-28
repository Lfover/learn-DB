#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include <memory.h>

typedef struct {
	int top;
	int min_top;
	int *stack;
	int *min_stack;
} MinStack;


MinStack* minStackCreate() {
	MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
	obj->stack = (int *)malloc(sizeof(int) * 10000);
	obj->min_stack = (int *)malloc(sizeof(int) * 10000);
	obj->top = 0;
	obj->min_top = 0;
	return obj;

}

void minStackPush(MinStack* obj, int val) {
	obj->stack[obj->top++] = val;
	if (obj->min_top == 0){
		obj->min_stack[obj->min_top++] = val;
	}
	else{
		if (obj->min_stack[obj->min_top] >= val){
			obj->min_stack[obj->min_top++] = val;
		}
	}
}
void minStackPop(MinStack* obj) {
	if (obj->stack[obj->top] == obj->min_stack[obj->min_top]){
		obj->top--;
		obj->min_top--;
	}
	else{
		obj->top--;
	}
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min_stack[obj->min_top];
}

void minStackFree(MinStack* obj) {
	free(obj->stack);
	free(obj->min_stack);
	free(obj);
	obj = NULL;
}
int main()
{
	MinStack bj;
	minStackCreate();
	minStackPush(&bj, 1);
	system("pause");
	return 0;
}

















#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BinTree{
	char val;
	struct BinTree *left;
	struct BinTree *right;
}BinTree;
typedef struct BinTree *BTree;
BTree BinTreeCreate(const char *a, int *i)
{
	if (a[*i] == '#' || a[*i] == '\0')
		return NULL;
	else{
		BinTree *t = (BinTree*)malloc(sizeof(BinTree));
		assert(t);
		t->val = a[*i];
		(*i)++;
		t->left = BinTreeCreate(a, i);
		(*i)++;
		t->right = BinTreeCreate(a, i);
		return t;
	}
}
void BinTreeLVR(BTree t)
{
	if (t != NULL){
		BinTreeLVR(t->left);
		printf("%c ", t->val);
		BinTreeLVR(t->right);
	}
}
int main()
{
	BTree bt;
	char a[100] = { 0 };
	scanf("%s", a);
	int i = 0;
	bt = BinTreeCreate(a, &i);
	BinTreeLVR(bt);
	return 0;
}
















#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BinTree{
	char data;
	struct BinTree *left;
	struct BinTree *right;
}BinTree;
typedef struct BinTree *BTree;
BTree CreateTree(const char *s, int *i)
{
	if (s[*i] == '#' || s[*i] == '\0')
		return NULL;
	else{
		BinTree *t = (BinTree *)malloc(sizeof(BinTree));
		assert(t);
		t->data = s[*i];
		(*i)++;
		t->left = CreateTree(s, i);
		(*i)++;
		t->right = CreateTree(s, i);
		return t;
	}

}
void BTreeLVR(BTree bt)
{
	if (bt != NULL){
		BTreeLVR(bt->left);
		printf("%c", bt->data);
		BTreeLVR(bt->right);
	}
}
int main()
{
	BTree bt;
	char s[100] = { 0 };
	scanf("%s", s);
	int i = 0;
	CreateTree(s, &i);
	BTreeLVR(bt);
	return 0;
}