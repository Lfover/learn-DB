#include <iostream>
#include <Windows.h>
using namespace std;
typedef struct int_8{
	int value��8;
}int_8;
int main()
{
	int_8 x;
	int_8 y;
	int_8 z;
	int_8 q;
	x.value��8= 54;
	y.value��8 = 84;
	z.value��8 = x.value��8 - 2 * y.value��8;
	q.value��8 = -2 * y.value��8;
	cout << z.value��8<< endl;
	cout << q.value��8 << endl;
	system("pause");
	return 0;
}