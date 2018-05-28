#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
	printf("fork before\n");
	fork();
	printf("fork after\n");
	while(1);
	return 0;
}
