#include <iostream>
#include <Windows.h>
using namespace std;
typedef struct int_8{
	int value£º8;
}int_8;
int main()
{
	int_8 x;
	int_8 y;
	int_8 z;
	int_8 q;
	x.value£º8= 54;
	y.value£º8 = 84;
	z.value£º8 = x.value£º8 - 2 * y.value£º8;
	q.value£º8 = -2 * y.value£º8;
	cout << z.value£º8<< endl;
	cout << q.value£º8 << endl;
	system("pause");
	return 0;
}