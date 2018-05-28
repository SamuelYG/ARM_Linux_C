#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
int main()
{
	int fd,rw_fd;
	int ret;
	struct sockaddr_in  myaddr;
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons( 8888);
	myaddr.sin_addr.s_addr = inet_addr("192.168.1.123");
	fd = socket(PF_INET,SOCK_STREAM,0);
	if(fd < 0)
	{
		printf("socket error\n");
		return -1;
	}
	ret = bind(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr_in));
	if(ret < 0)
	{
		printf("bind error\n");
		return -2;
	}
	printf("bind success\n");
	listen(fd,10);
	printf("accept before\n");
	rw_fd = accept(fd,NULL,NULL);
	printf("accept after\n");
	return 0;
}
