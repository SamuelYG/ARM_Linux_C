#include "stdio.h"
typedef struct A   ABC;
struct A
{
	int i;
	int j;
	char ch;
};
ABC  fun(int m,int n)
{
	int temp;
    ABC var;
	temp = m;
	m = n;
	n = temp;
	var.i= m;
	var.j= n;
	var.ch = 'y';
	return var;
}
int main()
{
	int a;
	int b;
	ABC v;
	a = 10;
	b = 11;
	v = fun(a,b);
	a = v.i;
	b  =v.j;
	printf("a = %d,b = %d,%c,%d\n",a,b,v.ch,sizeof(v));
	return 0;
}
