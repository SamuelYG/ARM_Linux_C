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
	ret = bind(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));
	if(ret == -1)
	{
		printf("bind error\n");
		return -2;
	}
	printf("bind success\n");
	listen(fd,10);
	printf("accept before\n");
	rw_file = accept(fd,NULL,NULL);

	printf("accept after\n");
	while(1)
	{
		read(rw_file,buf,128);
		printf("recv from cliet:%s\n",buf);
	}
	return 0;
}
