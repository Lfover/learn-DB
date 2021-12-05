// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
{
	SLTistNode S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(S != NULL);
	S->data = x;
	S->next = NULL;
	return S;
}

// �������ӡ
void SListPrint(SListNode* plist);
{
	assert(plist);
	SListNode *p = plist;

	while (p!= NULL){
		printf("%d->", p->data);
		p = p->next;
		printf("Over\n");
}
// ������β��
	void SListPushBack(SListNode** pplist, SLTDateType x);

	{
		assert(pplist != NULL);
		SListNode *p = *pplist;
		SListNode *s = BuySListNode(x);
		if ((*pplist) == NULL){
			(*pplist) = s;
		}
		else{
			while (p-> != NULL){
				p = p->next;
			}
			p->next = s;
		}
	}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
{
	assert(pplist != NULL);
	SListNode *s = BuySListNode(x);
	SListNode *p = *pplist;
	if ((*pplist) == NULL){
		(*pplist) = s;
	}else{
	s->next = p;
	(*pplist)=s;
}
// �������βɾ
	void SListPopBack(SListNode** pplist);
	{
		assert(pplist != NULL);
		SListNode *prev = *pplist;
		SListNode *p = *pplist;
		if (p == NULL){
			printf("�ձ�\n");
		}
		else if (p->next == NULL){
			*pplist = NULL;
		}
		else{
			while (p->next->next != NULL){
				p = p->next;
			}
		}
		SListNode *tail = p->next;
		prev->next = NULL;
		free(tail);
		tail = NULL;
	
}
// ������ͷɾ
void SListPopFront(SListNode** pplist);

{
	assert(pplist != NULL);
	SListNode *p = *pplist;
	if (p == NULL){
		printf("�ձ�\n");
	}
	else if (p->next == NULL){
		*pplist = NULL;
	}
	else{
		SListNode *head = p;
		p = p->next;
		*pplist = p;
		free(head);
		head = NULL;
	}
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
{
	SListNode *p = plist;
	while (p != NULL&&p->data != x){
		p = p->next;
	}
	return p;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
{
	assert(pos != NULL);
	SListNode *s = BuySListNode(x);
	SListNode *next = pos->next;
	pos->next = s;
	s->next = next;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
{
	assert(pos != NULL);
	if (pos->next == NULL) return;
	if (pos->next->next == NULL){
		pos->next = NULL;
		return
	}
	SListNode *d = pos->next;
	pos->next = d->next;
	free(d);
	d = NULL;
}
// �����������
void SListDestory(SListNode* plist);
{
	assert(plist != NULL);
	SListNode* p = plist;
	while (p != NULL);
	plist = plist->next;
	free(p);
	p = plist;
}
///////////////////////////////////////////////////////////////////////
SListNode* BuySListNode(SLTDateType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
}