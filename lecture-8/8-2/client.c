#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "string.h"
int main()
{
	int fd;
	int ret;
	char buf[32] = {0};
	struct sockaddr_in  myaddr;
	fd =socket(PF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("socke error\n");
		return -1;
	}
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons(6789);
	myaddr.sin_addr.s_addr = inet_addr("192.168.110.112");
	ret = connect(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));
	if(ret == -1)
	{
		printf("connect error\n");
		return -2;
	}
	while(1)
	{
		printf("please input send data\n");
		scanf("%s",buf);
		write(fd,buf,strlen(buf));
		if(strcmp(buf,"quit") == 0)
		{
			break;
		}
		memset(buf,0,32);
	}
	close(fd);
	return 0;

}
