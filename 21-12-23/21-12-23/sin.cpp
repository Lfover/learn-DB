#include <stdio.h>
#include <Windows.h>

void displayA(int k,int n)
{
	if (k > n)
		return;
	if (k != 1){
		if (k % 2 == 1){
			printf("+");
		}
		else {
			printf("-");
		}
	}
	printf("sin(");
	printf("%d",k);
	displayA(k + 1, n);
    printf(")");
}

void displayS(int k, int n)
{
	if (k < 1){
		return;
	}

	printf("(");
	displayS(k - 1, n);
	displayA(1, k);
	printf(")+" + (n - k + 1));
}
int main()
{
	displayS(2, 2);
	system("pause");
	return 0;
}