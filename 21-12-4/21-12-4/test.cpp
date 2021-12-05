//ListNode* deleteDuplication(ListNode* pHead)
//{
//	if (pHead == NULL) return pHead;
//	ListNode *pre = NULL; //指向前面最晚访问过的不重复结点
//	ListNode *p = pHead; //指向当前处理的结点
//	ListNode *q = NULL; //指向当前处理结点后面结点
//	while (p != NULL)
//	{
//		//当前结点p，（其实是p指向当前结点），与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
//		if (p->next != NULL && p->next->val == p->val)
//		{
//			q = p->next;
//
//			//找到q，它指向最后一个与p val相同的结点，那p 到 q （包含） 都是要删除的
//			while (q != NULL && q->next != NULL && q->next->val == p->val)
//			{
//				q = q->next;
//			}
//			//如果p指向链表中第一个元素，p -> ... -> q ->... , 要删除p到q, 将指向链表第一个元素的指针pHead指向q->next。
//			if (p == pHead)
//			{
//				pHead = q->next;
//			}
//			else//如果p不指向链表中第一个元素，pre -> p ->...->q ->... ，要删除p到q，即pre->next = q->next
//			{
//				pre->next = q->next;
//			}
//			//当前处理的p要向链表尾部移动
//			p = q->next;
//		}
//		else
//		{
//			pre = p;
//			p = p->next;
//		}
//	}
//	return pHead;
//}







//#include <stdio.h>
//#include <Windows.h>
//#include <vector>
//
//int reverse(int begin, int end)
//{
//
//}
//int main()
//{
//	vector<int>res;
//	int a[] = { 1, 2, 3, 4 };
//	int k = 200;
//
//	for (int i = 4; i >= 0; --i) {
//		int sum = a[i] + k % 10;
//		k /= 10;
//		if (sum >= 10) {
//			k++;
//			sum -= 10;
//		}
//		res.push_back(sum);
//	}
//	for (; k > 0; k /= 10) {
//		res.push_back(k % 10);
//	}
//	reverse(res.begin(), res.end());
//	return res;
//	system("pause");
//	return 0;
//}




//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	int res = 1;
//	int era = 1;
//	cin >> n;
//	int m = n / 2;
//
//	for (m; m>0; m--){
//		res *= n;
//		n--;
//	}
//	for (m; m>0; m--){
//		era *= m;
//	}
//	cout << res / era << endl;
//	system("pause");
//	return 0;
//}