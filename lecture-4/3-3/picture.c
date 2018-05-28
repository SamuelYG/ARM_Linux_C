#include "stdio.h"
void fun(int MAX,char ch)
{
//	int MAX;
//	char ch;
	int i;
	int line;
	i = 0;
	line = 1;
abc:
	for(i = 1; i <= line; i ++)
	{
		printf("%c",ch);
	}
	printf("\n");
	line ++;
	if(line <= MAX)
	{
		goto abc;
	}
	return ;
}
int main()
{
	fun(10,'A');
	fun(5,'%');
	fun(8,'k');
	return 0;
}
