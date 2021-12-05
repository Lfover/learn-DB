// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
{
	SLTistNode S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(S != NULL);
	S->data = x;
	S->next = NULL;
	return S;
}

// 单链表打印
void SListPrint(SListNode* plist);
{
	assert(plist);
	SListNode *p = plist;

	while (p!= NULL){
		printf("%d->", p->data);
		p = p->next;
		printf("Over\n");
}
// 单链表尾插
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
// 单链表的头插
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
// 单链表的尾删
	void SListPopBack(SListNode** pplist);
	{
		assert(pplist != NULL);
		SListNode *prev = *pplist;
		SListNode *p = *pplist;
		if (p == NULL){
			printf("空表\n");
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
// 单链表头删
void SListPopFront(SListNode** pplist);

{
	assert(pplist != NULL);
	SListNode *p = *pplist;
	if (p == NULL){
		printf("空表\n");
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
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
{
	SListNode *p = plist;
	while (p != NULL&&p->data != x){
		p = p->next;
	}
	return p;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
{
	assert(pos != NULL);
	SListNode *s = BuySListNode(x);
	SListNode *next = pos->next;
	pos->next = s;
	s->next = next;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
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
// 单链表的销毁
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