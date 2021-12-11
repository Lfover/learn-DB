#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//����˳���ṹ
typedef struct Seqlist{
	int *base;//����Ϊ��
	size_t capacity;//������8
	size_t size;
}Seqlist;


//��������
void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);
size_t SeqListLength(SeqList *plist);
void SeqListPopBack(SeqList *plist);
void SeqLIistClear(SeqList *plist);
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x);
void SeqListSort(SeqList *plist);
bool SeqListInsertbyval(SeqList *plist, ElemType x);
size_t SeqListCapacity(SeqList *plist);
void SeqListEarsebypos(SeqList *plist, size_t pos);
void SeqListPopFront(SeqList *plist);
int SeqListFind(SeqList *plist, ElemType x);
void SeqListErasebyval(SeqList *plist, ElemType x);
void SeqListReverse(SeqList *plist);
bool _Inc(SeqList *plist, size_t new_capacity);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�п�
bool IsEmpty(Seqlist *plist){
	assert(plist);
	return plist->size == 0;
}
//����
bool IsFill(Seqlist *plist){
	assert(plist);
	return plist->size == plist->capacity;
}
//��̬�����ڴ�
bool Inc(Seqlist *plist, size_t new_capacity)
{
	assert(plist&&new_capacity > plist->capacity);
	int *new_base = (int *)realloc(plist->base, sizeof(int)*new_capacity);
	if (new_base == NULL){
		return false;
	}
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}
//��ʼ��
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = 8;//��ʼ��СΪ8
	plist->base = (int *)malloc(sizeof(int) * 8);//����8�������ڴ�
	plist->size = 0;
}
//����
void SeqListDestroy(SeqList *plist)
{
	assert(plist);//�����ָ��
	free(plist->base);
	plist->base = NULL;//����Ұָ��
	plist->capacity = plist->size = 0;
}
//β��
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist);
	//������
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("˳������������ܲ���");
		return;
	}
	plist->base[plist->size++] = x;
}
//ͷ��
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist);
	//ͷ�巨��Ҫ������Ԫ������ƶ�һ�񣬰�plist->base[0]��λ�ÿճ��������ܲ���
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("˳������������ܲ���");
		return;
	}
	while (plist->size--){
		plist->base[plist->size] = plist->base[plist->size-1];//base�±��0��ʼ�ģ�����������±�Ϊsize-1�ĸ�ֵ��size
	}
	plist->base[0] = x;
	plist->size++;
}
//��ʾ
void SeqListShow(SeqList *plist)
{
	assert(plist);
	for (int i = 0; i < plist->size; i++){
		printf("%d ", plist->base[i]);
	}
}
//����
size_t SeqListLength(SeqList *plist)
{
	assert(plist);
	return plist->size;
}
//βɾ
void SeqListPopBack(SeqList *plist)
{
	assert(plist);
	//���п�
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����ɾ��");
		return;
	}
	plist->size--;
}
//ͷɾ
void SeqListPopFront(SeqList *plist)
{
	assert(plist);
	//ͷɾ���Խ����˵�һ��Ԫ�ص�����Ԫ��ȫ����ǰ�ƶ�һ�񣬵�һ��Ԫ�ػᱻ���ǵ����ﵽͷɾ��Ŀ��
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����ɾ��");
		return;
	}
	for (int i = 0; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
//���
void SeqLIistClear(SeqList *plist);
{
	//ֱ����size=0�Ϳ��Դ������˳����е�����Ԫ��
	assert(plist);
	plist->size = 0;
}
//��λ�ò���
bool SeqListInsertbypos(SeqList *plist, size_t pos, ElemType x)
{
	assert(plist);
	//��λ�ò��벻��Ҫ�ж�˳����Ƿ���������Ҫ�жϲ����λ���Ƿ�Ϸ�
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("˳������������ܲ���");
		return false;
	}
	if (pos<0 || pos>plist->size){
		printf("����λ�ò��Ϸ�");
		return false;
	}//��posλ�ü��Ժ��Ԫ�ض�����ƶ�һ�񣬰�posλ���ó���
	for (int i = plist->size; i > pos; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	return true;

}
//��ֵ����
bool SeqListInsertbyval(SeqList *plist, ElemType x)
{
	assert(plist);
	if (IsFull(plist) || Inc(plist, plist->capacity * 2)){
		printf("˳������������ܲ���");
		return false;
	}
	//��Ҫʵ�ְ�ֵ���룬��Ҫ�Ƚ�˳����ź���
	SeqListSort(plist);
	for (size_t i = 0; i < plist->size; i++){
		if (plist->base[i] > x){//��plist->base[i]>xʱ��x��Ҫ����ĵط���base[i]ǰ���λ��
			for (int j = plist->size; j > i; i--){
				plist->base[j] = plst->base[j - 1];//i���Ժ����������ƶ�����iλ�ÿճ���
			}
			plist->base[i] = x;
			plist->size++;
			return true;
		}
	}
}
//����
void SeqListSort(SeqList *plist)
{
	assert(plist);
	//���򷽷��õ�ð������
	int temp = 0;
	for (int i = 0; i < plist ->size-1; i++){
		for (int i = 0; i < plist->size-1; i++){
			if (plist->base[j] > plist->base[j + 1]){
				temp = plist->base[j];
				plist->base[j] = plist->base[j + 1];
				plist->base[j + 1] = temp;
			}
		}
	}
}
//��λ��ɾ��
void SeqListEarsebypos(SeqList *plist, size_t pos)
{
	assert(plist);
	//���п�
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����ɾ��");
		return;
	}//�жϲ���λ���Ƿ�Ϸ�
	if (pos<0 || pos>=plist->size){
		printf("ɾ��λ�ò��Ϸ�");
		return;
	}
	for (int i = pos; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];//��ǰ����
	}
	plist->size--;

}
//��ֵɾ��
void SeqListErasebyval(SeqList *plist, ElemType x)
{
	assert(plist);
	//���п�
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����ɾ��");
		return;
	}
	//res�洢SeqListFind�����ķ���ֵ�������ж���Ҫɾ����ֵ��˳�������û��
	int res=SeqListFind(plist, x);
	if (res==-1){
		printf("û�����Ԫ��");
		return;
	}
	else{
		for (int i = res; i < plist->size; i++){
			plist->base[i] = plist->base[i + 1];
		}
	}
	plist->size--;
}

//����
int SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist);
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("���Ѿ�Ϊ�գ����Ҳ���\n");
		return -1;
	}
	for (int i = 0; i < plist->size; i++){
		if (plist->base[i] == x){
			retrun i;
		}
	}
	return -1;
}
//��ת
void SeqListReverse(SeqList *plist)
{
	assert(plist);
	if (plist->size == 1){
		return;
	}
	int temp = 0;
	int start = 0;
	int end = plist->size - 1;
	while (start < end){
		temp = plist->base[end];
		plist->base[end] = plist->base[start];
		plist->base[start] = temp;
		start++:
		end--;
	}
}

#endif