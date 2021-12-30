#include "myqueue.h"

int main()
{
	LQueue lq;
	LinkQueueInit(&lq);
	LinkQueueAdd(&lq, 1);
	LinkQueueAdd(&lq, 2);
	LinkQueueAdd(&lq, 4);
	LinkQueueAdd(&lq, 5);
	LinkQueueAdd(&lq, 6);
	ListQueueShow(lq);

	system("pause");
	return 0;
}


//#include "mystack.h"
//
//int main()
//{
//	LStack ls;
//	LinkStackInit(&ls);
//	LinkStackAdd(&ls, 1);
//	LinkStackAdd(&ls, 2);
//	LinkStackAdd(&ls, 3);
//	LinkStackShow(ls);
//	LinkStackDel(&ls);
//	LinkStackShow(ls);
//	LinkStackDel(&ls);
//	LinkStackShow(ls);
//	LinkStackDel(&ls);
//	LinkStackShow(ls);
//	LinkStackChange(&ls, 1, 8);
//	LinkStackShow(ls);
//	LinkStackFind(&ls, 2);
//
//	system("pause");
//	return 0;
//}