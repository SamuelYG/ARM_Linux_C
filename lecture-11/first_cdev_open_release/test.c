#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int fd;
	fd = open("/dev/myhello",O_RDWR,0777);
	if(fd < 0)
	{
		printf("open myhello error\n");
		_exit(-1);
	}
	sleep(30);
	close(fd);
	return 0;
}
