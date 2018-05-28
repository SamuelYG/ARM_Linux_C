#include "stdio.h"
struct A
{
	int i;
	int j;
	char ch;
};
struct A fun(int m,int n)
{
	int temp;
	struct A  var;
	temp = m;
	m = n;
	n = temp;
    var.i = m;
	var.j = n;
	var.ch = 'y';
	return var;
}
int main()
{
	int a;
	int b;
	struct A ret;
	a = 10;
	b = 11;
	ret = fun(a,b);// ret = var
	a = ret.i;
	b = ret.j;
	printf("a = %d,b = %d,%c\n",a,b,ret.ch);
	return 0;
}
