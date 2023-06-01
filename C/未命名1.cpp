#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *pa = &a[0];
	printf("%d\n",*pa);
	printf("%p\n",pa);
	printf("%d\n",(*pa)++);
	printf("%d\n",*pa);
	printf("%p\n",pa);
	return 0;
}
