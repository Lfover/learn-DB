#include <stdio.h>
#include <Windows.h>

void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	int i = 1;
	i <<= (position - 1);
	if (flag){
		*p_data |= i;
	}
	else{
		*p_data &= (~i);
	}
	
}
void main()
{
	unsigned char data = 123;
	bit_set(&data, 3, true);
	printf("%c",data);
	system("pause");
}