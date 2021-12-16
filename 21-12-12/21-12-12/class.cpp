
#include "bintree.h"

int main()
{
	const char *vlr = "ABCDEFGH";
	const char *lvr = "CBEDFAGH";
	const char *lrv = "CEFDBHGA";
	BinTree bt;
	BinTreeInit(&bt);
	bt=BinTreeCreate_3(vlr, lvr, strlen(vlr));
	//const char *str = "ABC##DE##F##G#H##";
	//BinTree bt;
	//BinTreeInit(&bt);
	////BinTreeCreate(&bt);
	//int index = 0;
	//bt=BinTreeCreate_2(str, &index);//这里为什么要传地址，是为了在函数里改变，也会影响主函数
	//BinTree bt1 = BinTreeClone(bt);
	////先序
	//printf("VLR:");
	//BinTreeVLR(bt);
	//printf("\n");
	////中序
	//printf("LVR:");
	//BinTreeLVR(bt);
	//printf("\n");
	////后序
	//printf("LRV:");
	//BinTreeLRV(bt);
	//printf("\n");
	//Height(bt);
	//char key = 'D';
	//BinTreeNode *p = BinTreeFind(bt, key);
	//BinTreeNode *pr = BinTreeParent(bt, p);
	system("pause");
	return 0;
}

//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <map>
//#include <deque>
//
//#include <assert.h>
//using namespace std;
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//void RightLoopMove(char *pStr, unsigned short steps){
//	assert(pStr != NULL);
//	int len = strlen(pStr);
//	steps %= steps;
//	for (int i = 0; i < steps; i++){
//		char temp = pStr[len - 1];//保留最后一个要循环移动的字符
//		for (int j = len - 1; i > 0; j--){
//			pStr[j] = pStr[j - 1];
//		}
//		pStr[0] = temp;
//	}
//	
//}
//
//int main()
//{
//	char str[] = "abcdefghi";
//	cout << str << endl;
//	RightLoopMove(str, 2);
//	cout << str << endl;
//	system("pause");
//	return 0;
//}