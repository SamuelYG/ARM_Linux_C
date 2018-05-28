#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
int main()
{
	int fd,rw_file;
	int ret;
	char buf[128] = {0};
	struct sockaddr_in  myaddr;
	fd = socket(PF_INET,SOCK_STREAM,0);
	if(fd < 0)
	{
		printf("socket error\n");
		return -1;
	}
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons( 8888);
	myaddr.sin_addr.s_addr = inet_addr("192.168.1.123");
	ret = connect(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));
	if(ret == -1)
	{
		printf("connect error\n");
		return -2;
	}
	while(1)
	{
		write(fd,"hello linux",12);
		sleep(5);
	}
	return 0;
}
