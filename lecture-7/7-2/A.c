#include "unistd.h"
#include "signal.h"
#include "stdio.h"
void myfun(int sig)
{
	printf("recv signal:%d from A\n",sig);
	return ;
}
int main()
{
	signal(10,myfun);
	while(1)
	{

	}
	return 0;
}
