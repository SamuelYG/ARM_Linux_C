#include "stdio.h"
#include "unistd.h"
#include "signal.h"
int flag = 0;
void myfun(int sig)
{
	if(sig == 10)
	{
       flag = 1;
	}
	else if(sig == 12)
	{
       flag = 0;
	}
	return ;
}
void listening_music()
{
	int i;
	for(i = 0 ;i < 50 ; i ++)
	{
		while(1)// while(flag != 0);
		{
			if(flag == 0)
			{
				break;
			}
		}
        printf("listening_music..........i = %d\n",i);
		usleep(300000);
	}
}
int main()
{
	signal(10,myfun);
	signal(12,myfun);
	while(1)
	{
		listening_music();
	}
	return 0;
}
