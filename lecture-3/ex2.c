#include "stdio.h"
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8};
	printf("%p,%p,%p,%p\n",&a[0],&a[1],&a[3],a);
	printf("%d,%d,%d,%d\n",a[5],*(&a[0]+5),*(a + 5),*(&a[7] - 2));//&a + 1)
  printf("%d\n",*(((int *)(&a + 1)) - 5));
	return 0;

}
