#include <stdio.h>
#include <Windows.h>
#include <assert.h>


typedef struct ListNode
{
	int data;//������
	ListNode *next;//ָ����

}ListNode;

typedef ListNode *List;

void ListInit(List *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
////////////////////////////////////////////////////////////////
//β�巨1
void ListCreate_Tial1(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode *)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;
	ListNode *p = *phead;
	for (int i = 2; i <= 10; i++){
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
///////////////////////////////////////////////////////////////////
//β�巨2
void ListCreate_Tial2(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode *)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;
	ListNode *p = *phead;
	for (int i = 2; i <= 10; i++){
		p=p->next = (ListNode*)malloc(sizeof(ListNode));
		p->data = i;
		p->next = NULL;
	}
}

///////////////////////////////////////////////////////////////////
//ͷ�巨
void ListCreate_Head(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode *)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for (int i = 2; i <= 10; i++){
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = *phead;
		*phead = s;
	}
}

/////////////////////////////////////////////////////////////////////////
//��ʾ
void ListShow(List head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

int main()
{
	List mylist;
	ListInit(&mylist);
	ListCreate_Tial2(&mylist);
	ListCreate_Head(&mylist);
	ListShow(mylist);
	system("pause");
	return 0;
}