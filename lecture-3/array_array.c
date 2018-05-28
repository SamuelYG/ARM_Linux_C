#include "stdio.h"
int main()
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("%p,%p,%p\n",&a[0][1],a[0],&a[2][1]);
	printf("%p,%p,%p\n",a,a+1,&a+1);
	printf("%d,%d,%d,%d\n",a[1][1],*(a[1] + 1),*(a[0] + 5),*( *(a + 1) + 1));
	return 0;
}
