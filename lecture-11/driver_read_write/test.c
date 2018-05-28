#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int fd;
	int ret;
	char rd_buf[128] = {0};
	char buf[] = "dddddd user hello\n";
	fd = open("/dev/myuart",O_RDWR);//open can not creat device file
	if(fd < 0)
	{
		printf("open /dev/myuart error\n");
		exit(-1);
	}
	ret = write(fd,(void *)buf,sizeof(buf));
	printf("ret = %d\n",ret);
	sleep(20);
	ret = read(fd,(void *)rd_buf,128);
	printf("read from kernel len= %d\n",ret);
	close(fd);
	return 0;
}
