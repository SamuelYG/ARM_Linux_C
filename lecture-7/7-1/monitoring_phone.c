#include "stdio.h"
#include "unistd.h"
#include "signal.h"
int flag = 0;
void monitoring_phone()
{
	int i;
	int j;
	for(i = 0 ;i < 100 ; i ++)
	{
        printf("monitoring phone..........i = %d\n",i);
		usleep(200000);
	}
	//
	kill(27826,10);
	for(j = 0 ; j < 50; j ++)
	{
		printf("processing phone ......   j= %d\n",j);
		usleep(300000);
	}
	kill(27826,12);
}
int main()
{
	while(1)
	{
		monitoring_phone();
	}
	return 0;
}
