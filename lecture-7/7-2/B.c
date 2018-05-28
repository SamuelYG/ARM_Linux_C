#include "unistd.h"
#include "signal.h"
#include "stdio.h"
int main()
{
	while(1)
	{
		kill(27532,10);
		sleep(5);
	}
	return 0;
}
