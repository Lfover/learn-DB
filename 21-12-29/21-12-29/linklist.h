#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <assert.h>
#define ElemType int

typedef struct linklist{
	ElemType data;
	struct linklist *next;
}linklist;

typedef linklist *Llist;

//��ʼ��
void LlistInit(Llist *list);
//��
void LlistAdd(Llist *list,ElemType x);
//ɾ
void LlistDel(Llist *list, ElemType x);
//��
void LlistChange(Llist *list, ElemType x, ElemType y);
//��
linklist* LlistFind(Llist *list, ElemType x);
//��ʾ
void Show(Llist list);

/////////////////////////////////////////////////
//��ʼ��
void LlistInit(Llist *list)
{
	assert(list);
	*list = NULL;
}
//����β�壩
void LlistAdd(Llist *list,ElemType x)
{
	//����ռ�
	linklist *t = (linklist *)malloc(sizeof(linklist));
	assert(t);
	t->data = x;
	t->next = NULL;
	linklist *p = *list;
	//�������Ľ���ǵ�һ�����
	if (p == NULL)
		*list = t;
	else{
		//�ҵ����һ�����
		while (p->next != NULL)
			p = p->next;
		p->next = t;
	}
}
//ɾ
void LlistDel(Llist *list, ElemType x)
{
	assert(list);
	//�������Ϊ��
	if (list == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	linklist* p = *list;
	//�����һ�������ΪĿ��ֵ
	if (p->next == NULL && p->data == x)
	{
		list == NULL;
		return;
	}
	
	//���Ҫɾ����Ŀ��ֵ������
	

}
//��
void LlistChange(Llist *list, ElemType x, ElemType y)
{

}
//��
linklist *LlistFind(Llist *list, ElemType x)
{
	assert(list);
	linklist *p = *list;
	while (p->next != NULL)
	{
		if (p->data == x)
		{
			printf("�ҵ���\n");
			return p;
		}
		p = p->next;
	}
	if (p == NULL || p->next == NULL)
	{
		printf("û�ҵ�\n");
		return NULL;
	}
}
//��ʾ
void Show(Llist list)
{
	assert(list!=NULL);
	linklist *head = list;
	while (head->next != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


#endif