#include "stdio.h"
void fun(int *m,int *n)
{
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
	return ;
}
int main()
{
	int a;
	int b;
	a = 10;
	b = 11;
	fun(&a,&b);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
