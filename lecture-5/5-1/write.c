#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
#include "string.h"
int main()
{
	int ret;
	int len;
	char qq[128] = {0};
	char path[128] = "./save.txt";
	ret = open(path,O_CREAT | O_RDWR,0777);
	if(ret == -1)
	{
		printf("open %s error\n",path);
		return -1;
	}
	printf("open %s success\n",path);
    printf("please input a qq code\n");
	scanf("%s",qq);
	len = write(ret,qq,strlen(qq));
	printf("write:%d\n",len);
	close(ret);
	return 0;
}
