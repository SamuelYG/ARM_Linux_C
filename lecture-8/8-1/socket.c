#include "stdio.h"
#include "sys/socket.h"
int main()
{
	int fd;
	fd = socket(PF_INET,SOCK_STREAM,0);
	if(fd < 0)
	{
		printf("socket error\n");
		return -1;
	}
	return 0;
}
