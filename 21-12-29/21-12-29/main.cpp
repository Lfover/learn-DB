#include "linklist.h"

int main()
{
	Llist ll;
	LlistInit(&ll);
	LlistAdd(&ll, 1);
	LlistAdd(&ll, 2);
	LlistAdd(&ll, 3);
	LlistAdd(&ll, 4);
	LlistAdd(&ll, 5);
	Show(ll);
	LlistFind(&ll, 5);
	LlistDel(&ll, 1);
	Show(ll);
	LlistDel(&ll, 2);
	Show(ll);
	LlistDel(&ll, 3);
	Show(ll);
	LlistDel(&ll, 4);
	Show(ll);
	LlistDel(&ll, 5);
	Show(ll);
	LlistChange(&ll, 5, 8);
	Show(ll);

	system("pause");
	return 0;
}

//#include "sequentialtable.h"
//
//int main()
//{
//	SeqTable st;
//	SeqTableInit(&st);
//	SeqTableAdd(&st, 1);
//	SeqTableAdd(&st, 2);
//	SeqTableAdd(&st, 3);
//	SeqTableAdd(&st, 4);
//	SeqTableAdd(&st, 5);
//	SeqTableAdd(&st, 6);
//	SeqTableAdd(&st, 7);
//	SeqTableAdd(&st, 8);
//	SeqTableAdd(&st, 9);
//	SeqTableAdd(&st, 10);
//
//	SeqTableShow(&st);
//	SeqTableDel(&st, 3);
//	SeqTableShow(&st);
//	SeqTableChange(&st, 2, 5);
//	SeqTableShow(&st);
//
//	system("pause");
//	return 0;
//}