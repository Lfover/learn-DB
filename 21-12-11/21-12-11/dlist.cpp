#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <stdbool.h>
typedef struct Dlist{
	int data;//以整形为例子
	struct Dlist *next;//指针域
}Dlist;
//初始化
void InitDlist(Dlist *head){
	assert(head);
	head = NULL;
}
//动态申请结点
Dlist *BuyNode(int x){
	Dlist* s = (Dlist *)malloc(sizeof(Dlist));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//打印
void DlistPrint(Dlist *head){
	assert(head);
	Dlist *p = head;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
}
//尾插
void PushbackDlist(Dlist **head,int x){
	//assert(head);
	Dlist *s = BuyNode(x);
	assert(s != NULL);//判断结点是否申请成功
	Dlist *p = *head;
	//如果此时链表是空的，s就是链表的第一个结点
	if (p==NULL){
		*head = s;
	}
	//链表不为空，需要遍历整个单链表去找到最后一个结点，把结点s插在后面
	else{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
		
	}
}

//头插
void PushFrontDlist(Dlist **head, int x){
	assert(*head);//避免空指针
	Dlist *s = BuyNode(x);
	assert(s != NULL);//判断结点是否申请成功
	Dlist *p = *head;
	//如果此时链表是空的，需要改变头指针
	if (*head == NULL){
		(*head) = s;
	}
	else{
		s->next = p;
		(*head) = s;

	}
}
//单链表尾删
void PopBackDlist(Dlist **head){
	assert(*head);
	Dlist *prev = *head;
	Dlist *p = *head;
	Dlist *tail = p->next;
	if (*head == NULL){
		printf("空表");
	}//只有一个结点时，删除后要改变头指针，指向NULL
	else{
		if (p->next == NULL){
			free(*head);//free掉唯一一个结点
			*head = NULL;
		}
		else{//需要找到最后一个元素的前一个结点，才可以删除
			while (tail->next != NULL){
				prev = tail;
			}
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;//最后一个结点的前一个结点指向空
	}

}
//头删
void PopTopDlist(Dlist **head){
	assert(*head);
	if (*head == NULL){
		return;
	}
	else{
		Dlist *cur= (*head)->next;//定义一个变量指向首结点的
		free(*head);
		*head = cur;//改变首结点的位置
	}
}

//按指定位置后插入
void InsertAfterDlist(Dlist *pos, int x){
	assert(pos);
	Dlist *s = BuyNode(x);
	assert(s);
	s->next = pos->next;
	pos->next = s;//pos指向新节点
}

//按指定位置前插入
void InsertBeforeDlist(Dlist *pos, int x){
	assert(pos);
	Dlist *s = BuyNode(x);
	assert(s);
	//在pos位置后面尾插，然后交换新节点和pos的data值
	s->next = pos->next;
	pos->next = s;
	int temp = pos->data;
	pos->data =s->data;
	s->data = temp;
}
//按指定位置后删
void EraseAfterDlist(Dlist *pos)
{
	assert(pos);
	//如果要删除的位置后面是空的，则代表没有东西删除
	if (pos->next == NULL){
		return;
	}
	//代表删除这个结点以后，pos也指向空了
	if (pos->next->next == NULL){
		pos->next = NULL;
		return;
	}
	Dlist *p = pos->next;
	pos->next = p->next;
	free(p);
	p = NULL;
}

//按指定位置头删
void EraseBeforeDlist(Dlist **head, Dlist* pos){
	//这样单链表结束了？还不可以结束嘛？我觉得早就能结束了好吧好吧，那我还要写双链表和循环链表嘛？循环要写 有题目（击鼓传花问题约瑟夫环）双链表写一下也可以
	//嗷写一个双循环链表吧，你说 也行双向链表少反正我见得少，好，还有栈（不写了），再去写一个队列（顺序表和链表实现）
	//栈会用么 有题目可能要用
	assert(pos);
	assert(*head);
	if (*head == pos){
		return;
	}
	if ((*head)->next == pos){
		*head = pos;
		return;
	}
	Dlist *prev = *head;
	Dlist *cur = prev->next;
	while (prev->next->next != pos){
		prev = prev->next;
	}
	prev->next = pos;
	free(cur);
	pos = NULL;
}

int main(){
	Dlist *head=NULL;
	PushbackDlist(&head, 1);
	PushbackDlist(&head, 2);
	PushbackDlist(&head, 3);
	EraseBeforeDlist(&head,head->next->next);
	DlistPrint(head);
	system("pause");
	return 0;
}

//
//#define N 12
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
////运动员结构
//typedef struct athlete {
//	int no;
//	char name[30];
//	char country[30];
//	float score[5];
//	float total;
//}Athlete;
//
////输入函数
//void input(Athlete athletes[]) {
//	int i = 0;
//	for (i = 0; i < N; i++){
//		//读取顺序，国家，姓名
//		scanf("%d %s %s", &athletes[i].no, athletes[i].country, athletes[i].name);
//
//		//初始化出场顺序成绩和总成绩
//		athletes[i].no = i + 1;
//
//		int j = 0;
//		for (; j < 5; j++) {
//			athletes[i].score[j] = 0.0;
//
//		}
//
//		athletes[i].total = 0.0;
//
//	}
//
//}
//
////选择排序
//void selectSort(Athlete athletes[12], Athlete rank[12]) {
//	int i = 0;
//	for (; i <= 11; i++) {
//		int k = i, j = i + 1;
//		for (; j <= 11; i++){
//			if (athletes[j].total < athletes[k].total){
//				k = j;
//			}
//
//		}
//
//		rank[i] = athletes[k];
//	}
//
//}
//
////获取每一轮每人的成绩
//void getScore(Athlete athletes[12], int n) {
//	int i = 0;
//	for (i = 0; i < 12; i++) {
//		scanf("%d", &athletes[i].score[n]);
//		athletes[i].total += athletes[i].score[n];
//	}
//}
//
////展示
//void list(Athlete rank[12]) {
//	int i = 0;
//	for (; i < 11; i++) {
//		printf("%d\t%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f",
//			rank[i].no, rank[i].country, rank[i].name,
//			rank[i].score[0], rank[i].score[1], rank[i].score[2],
//			rank[i].score[5], rank[i].score[4]);
//	}
//}
//
//
//int main() {
//	Athlete athletes[12];
//	Athlete rank[12];
//
//	printf("请按照出场顺序输入每位选手的国家和姓名:");
//	input(athletes);
//	list(athletes);
//
//	int i = 0;
//	for (; i < 5; i++) {
//		printf("请输入第%d轮每位选手成绩（按照出场顺序）:", i + 1);
//		getScore(athletes, i);
//		selectSort(athletes, rank);
//		list(rank);
//	}
//
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct linkedlist {
//	int data;
//	struct linkedlist* next;
//}LinkedList;
//
//LinkedList* creat(int n) {
//	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
//	head->next = NULL;
//	scanf("%d", &head->data);
//	LinkedList* cur = head;
//	int i;
//	for (i = 1; i < n; i++){
//		LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
//		scanf("%d", &node->data);
//		cur->next = node;
//		node->next = NULL;
//		cur = cur->next;
//	}
//
//	return head;
//}
//
//void add(LinkedList* head, int val) {
//	LinkedList* cur = head;
//	while (cur->next != NULL) {
//		cur = cur->next;
//	}
//
//	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
//	node->data = val;
//	cur->next = node;
//	node->next = NULL;
//}
//
//void list(LinkedList* head) {
//	LinkedList* cur = head;
//	while (cur != NULL) {
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	LinkedList *head = creat(n);
//
//	add(head, 2);
//	list(head);
//	return 0;
//}
