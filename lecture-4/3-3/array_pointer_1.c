#include "stdio.h"
int main()
{
	typedef  int  A[5];
	int b[4][5];
	int (*p)[5];
	A  (*q)[4];
	p = b;
	q = &b;
	return 0;
}
