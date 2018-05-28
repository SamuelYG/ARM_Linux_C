#include "stdio.h"
int main()
{
	int a[4];
	int b[3][4];
	int (*p)[4];
	p = a;
	p = &a;
	p = b;
	p = &b[0];
	p = b[0];
	p = &b[2];
	p = b[3];
	return 0;
}
