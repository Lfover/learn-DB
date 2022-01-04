#include <iostream>
using namespace std;
//进制转化模板
//int get(int n, string s)
//{
//	int res = 0;
//	for (auto c : s)
//		res = res * n + c - '0';
//	return res;
//}
//差分算法
const int N = 100010;
int m, n;
int a[N], b[N];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
	while (m--)
	{
		int left, right, c;
		cin >> left >> right >> c;
		b[left] += c;
		b[right + 1] += c;
	}
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i];
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}

//快速选择算法
int quick_select(vector<int>& v, int left, int right, int k)
{
	//寻找第k个数
	if (right == le)
		return v[left];
	int x = v[left], i = le - 1, j = ri + 1;
	while (i < j)
	{
		do i++; while (v[i] < x);
		do j++; while (v[j] > x);
		if (i < j)
			swap(v[i], v[j]);
	}
	int s1 = j - left + 1;
	if (k <= sl)
		return quick_select(v, left, j, k);
	return quick_select(v, j + 1, right, k - sl);
}