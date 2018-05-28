#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
int main()
{
	int ret;
	int len;
	char buf[128] = {0};
	char path[128] = "./save.txt";
	ret = open(path,O_CREAT | O_RDWR,0777);
	if(ret == -1)
	{
		printf("open %s error\n",path);
		return -1;
	}
	printf("open %s success\n",path);
    len = read(ret,buf,128);
	printf("read: %d,%s\n",len,buf);
	close(ret);
	return 0;
}
