#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
void reading_ebook()
{
    int i;
	for(i = 0 ; i < 10 ;i ++)
	{
		printf("reading ebook i = %d\n",i);
		usleep(200000);
	}
}
void listening_music()
{
	int j;
	for(j = 0 ; j < 10 ; j ++)
	{
		printf("listening music j = %d\n",j);
		usleep(200000);
	}
}
int main()
{
	int ret;
	ret = fork();
	if(ret > 0) 
	{
        // parent process run
		while(1)
		{
            reading_ebook();
		}
	}
	else if(ret == 0)
	{
        // child process run
		while(1)
		{
			listening_music();
		}
	}
	else
	{
		printf("fork error\n");
	}
	return 0;
}
