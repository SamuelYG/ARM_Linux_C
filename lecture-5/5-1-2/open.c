#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
int main()
{
	int ret;
	char path[128] = "./save.txt";
	ret = open(path,O_RDWR | O_CREAT,0777);
	if(ret == -1)
	{
		printf("open error\n");
		return -1;
	}
	printf("open success\n");
	return 0;
}
