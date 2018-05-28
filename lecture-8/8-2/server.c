#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "string.h"
int main()
{
	int fd,rw_fd ;
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
	ret = bind(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));
	if(ret == -1)
	{
		printf("bind error\n");
		return -2;
	}
	listen(fd,20);
loop:
	printf("accept before\n");
	rw_fd = accept(fd,NULL,NULL);
	printf("accept after\n");
	// child process
	ret = fork();
	if(ret > 0)
	{
		close(rw_fd);
		goto loop;
	}
	if(ret == 0)
	{
		while(1)
		{
			read(rw_fd,buf,32);
			if(strcmp(buf,"quit") == 0)
			{
				break;
			}

			printf("recv:%s\n",buf);
			memset(buf,0,32);
		}
		close(rw_fd);
	}
	
	return 0;

}
