#include "stdio.h"
#include "stdlib.h"
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
	while(1)
	{
		reading_ebook();
		listening_music();
	}
	return 0;
}
