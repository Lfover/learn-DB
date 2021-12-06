#include "dclist.h"

int main()
{
	ListNode C;
	ListNode *pos=NULL;
	ListCreate();
	ListPushBack(&C, 1);
	ListPushBack(&C, 2);
	ListPushBack(&C, 3);
	ListPushBack(&C, 4);
	ListPrint(&C);
	ListInsert(pos, 6);
	system("pause");
	return 0;
}