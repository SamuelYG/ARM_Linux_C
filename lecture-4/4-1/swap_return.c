#include "stdio.h"
int * fun(int m,int n)
{
	int temp;
	static int ret[2] = {0};
	temp = m;
	m = n;
	n = temp;
	ret[0] = m;
	ret[1] = n;
	return ret;
}
int main()
{
	int a;
	int b;
	int *p;
	a = 10;
	b = 11;
	p = fun(a,b);
	a = *p;
	p++;
	b  = *p;
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
