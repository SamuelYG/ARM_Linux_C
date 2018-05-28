#include "stdio.h"
int main()
{
	int a;
	int *p;
	a = 100;
	p = &a;
	printf("%d,%d,%d\n",*&a,**&p,*(&(*(p - 1)) + 1));
	return 0;
}
