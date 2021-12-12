#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <stdbool.h>
typedef struct Dlist{
	int data;//������Ϊ����
	struct Dlist *next;//ָ����
}Dlist;
//��ʼ��
void InitDlist(Dlist *head){
	assert(head);
	head = NULL;
}
//��̬������
Dlist *BuyNode(int x){
	Dlist* s = (Dlist *)malloc(sizeof(Dlist));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//��ӡ
void DlistPrint(Dlist *head){
	assert(head);
	Dlist *p = head;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
}
//β��
void PushbackDlist(Dlist **head,int x){
	//assert(head);
	Dlist *s = BuyNode(x);
	assert(s != NULL);//�жϽ���Ƿ�����ɹ�
	Dlist *p = *head;
	//�����ʱ�����ǿյģ�s��������ĵ�һ�����
	if (p==NULL){
		*head = s;
	}
	//����Ϊ�գ���Ҫ��������������ȥ�ҵ����һ����㣬�ѽ��s���ں���
	else{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
		
	}
}

//ͷ��
void PushFrontDlist(Dlist **head, int x){
	assert(*head);//�����ָ��
	Dlist *s = BuyNode(x);
	assert(s != NULL);//�жϽ���Ƿ�����ɹ�
	Dlist *p = *head;
	//�����ʱ�����ǿյģ���Ҫ�ı�ͷָ��
	if (*head == NULL){
		(*head) = s;
	}
	else{
		s->next = p;
		(*head) = s;

	}
}
//������βɾ
void PopBackDlist(Dlist **head){
	assert(*head);
	Dlist *prev = *head;
	Dlist *p = *head;
	Dlist *tail = p->next;
	if (*head == NULL){
		printf("�ձ�");
	}//ֻ��һ�����ʱ��ɾ����Ҫ�ı�ͷָ�룬ָ��NULL
	else{
		if (p->next == NULL){
			free(*head);//free��Ψһһ�����
			*head = NULL;
		}
		else{//��Ҫ�ҵ����һ��Ԫ�ص�ǰһ����㣬�ſ���ɾ��
			while (tail->next != NULL){
				prev = tail;
			}
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;//���һ������ǰһ�����ָ���
	}

}
//ͷɾ
void PopTopDlist(Dlist **head){
	assert(*head);
	if (*head == NULL){
		return;
	}
	else{
		Dlist *cur= (*head)->next;//����һ������ָ���׽���
		free(*head);
		*head = cur;//�ı��׽���λ��
	}
}

//��ָ��λ�ú����
void InsertAfterDlist(Dlist *pos, int x){
	assert(pos);
	Dlist *s = BuyNode(x);
	assert(s);
	s->next = pos->next;
	pos->next = s;//posָ���½ڵ�
}

//��ָ��λ��ǰ����
void InsertBeforeDlist(Dlist *pos, int x){
	assert(pos);
	Dlist *s = BuyNode(x);
	assert(s);
	//��posλ�ú���β�壬Ȼ�󽻻��½ڵ��pos��dataֵ
	s->next = pos->next;
	pos->next = s;
	int temp = pos->data;
	pos->data =s->data;
	s->data = temp;
}
//��ָ��λ�ú�ɾ
void EraseAfterDlist(Dlist *pos)
{
	assert(pos);
	//���Ҫɾ����λ�ú����ǿյģ������û�ж���ɾ��
	if (pos->next == NULL){
		return;
	}
	//����ɾ���������Ժ�posҲָ�����
	if (pos->next->next == NULL){
		pos->next = NULL;
		return;
	}
	Dlist *p = pos->next;
	pos->next = p->next;
	free(p);
	p = NULL;
}

//��ָ��λ��ͷɾ
void EraseBeforeDlist(Dlist **head, Dlist* pos){
	//��������������ˣ��������Խ�����Ҿ�������ܽ����˺ðɺðɣ����һ�Ҫд˫�����ѭ�������ѭ��Ҫд ����Ŀ�����Ĵ�������Լɪ�򻷣�˫����дһ��Ҳ����
	//�дһ��˫ѭ������ɣ���˵ Ҳ��˫�������ٷ����Ҽ����٣��ã�����ջ����д�ˣ�����ȥдһ�����У�˳��������ʵ�֣�
	//ջ����ô ����Ŀ����Ҫ��
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
////�˶�Ա�ṹ
//typedef struct athlete {
//	int no;
//	char name[30];
//	char country[30];
//	float score[5];
//	float total;
//}Athlete;
//
////���뺯��
//void input(Athlete athletes[]) {
//	int i = 0;
//	for (i = 0; i < N; i++){
//		//��ȡ˳�򣬹��ң�����
//		scanf("%d %s %s", &athletes[i].no, athletes[i].country, athletes[i].name);
//
//		//��ʼ������˳��ɼ����ܳɼ�
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
////ѡ������
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
////��ȡÿһ��ÿ�˵ĳɼ�
//void getScore(Athlete athletes[12], int n) {
//	int i = 0;
//	for (i = 0; i < 12; i++) {
//		scanf("%d", &athletes[i].score[n]);
//		athletes[i].total += athletes[i].score[n];
//	}
//}
//
////չʾ
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
//	printf("�밴�ճ���˳������ÿλѡ�ֵĹ��Һ�����:");
//	input(athletes);
//	list(athletes);
//
//	int i = 0;
//	for (; i < 5; i++) {
//		printf("�������%d��ÿλѡ�ֳɼ������ճ���˳��:", i + 1);
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
