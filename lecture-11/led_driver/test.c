#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int fd;
	while(1)
	{
		fd = open("/dev/myuart",O_RDWR);
		if(fd < 0)
		{
			printf("open /dev/myuart error\n");
			exit(-1);
		}
		sleep(2);
		close(fd);
		sleep(2);
	}
	return 0;
}
