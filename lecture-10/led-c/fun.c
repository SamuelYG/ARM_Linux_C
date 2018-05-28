#include "global.h"
int mymain(int n)
{
	  int *p;
	  //int i = 1;
	  int count ;
	  p = (int *)GPFCON;//0x56000050
	  *p = 0x400;  // GPF5----out
	  p = (int *)GPFDAT;
	  while(1)
		{	
				*p = 0;
				count = 100000;
				while(count > 0)
				{
					 count --;
				}
				*p = 0x20;
				
				count = 100000;
				while(count > 0)
				{
					 count --;
				}
	  }
	  return 1;
}
