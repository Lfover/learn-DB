//ListNode* deleteDuplication(ListNode* pHead)
//{
//	if (pHead == NULL) return pHead;
//	ListNode *pre = NULL; //ָ��ǰ��������ʹ��Ĳ��ظ����
//	ListNode *p = pHead; //ָ��ǰ����Ľ��
//	ListNode *q = NULL; //ָ��ǰ�����������
//	while (p != NULL)
//	{
//		//��ǰ���p������ʵ��pָ��ǰ��㣩��������һ�����p->next��val��ͬ��˵��Ҫɾ�������val�����н��
//		if (p->next != NULL && p->next->val == p->val)
//		{
//			q = p->next;
//
//			//�ҵ�q����ָ�����һ����p val��ͬ�Ľ�㣬��p �� q �������� ����Ҫɾ����
//			while (q != NULL && q->next != NULL && q->next->val == p->val)
//			{
//				q = q->next;
//			}
//			//���pָ�������е�һ��Ԫ�أ�p -> ... -> q ->... , Ҫɾ��p��q, ��ָ�������һ��Ԫ�ص�ָ��pHeadָ��q->next��
//			if (p == pHead)
//			{
//				pHead = q->next;
//			}
//			else//���p��ָ�������е�һ��Ԫ�أ�pre -> p ->...->q ->... ��Ҫɾ��p��q����pre->next = q->next
//			{
//				pre->next = q->next;
//			}
//			//��ǰ�����pҪ������β���ƶ�
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