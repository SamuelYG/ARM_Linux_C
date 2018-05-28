#include "stdio.h"
#include "fcntl.h"
#include "string.h"
int main()
{
	char passwd[128] = {0};
	char number[128] = {0};
	char path[128] = "./save.txt";
	int f_id;
    
	f_id = open(path,O_RDWR,0777);
	if(f_id < 0)
	{
       printf("please input qq code\n");
	   scanf("%s",number);
	}
	else
	{
		read(f_id,number,128);
		printf("qq_number: %s",number);
		close(f_id);
	}
	printf("please input passwd\n");
	scanf("%s",passwd);
	printf("start login.........\n");
	f_id = open(path,O_RDWR | O_CREAT,0777);
	if(f_id < 0)
	{
		printf("open %s error\n",path);
		return -1;
	}
	write(f_id,number,strlen(number));
	close(f_id);
	while(1);
	return 0;
}
