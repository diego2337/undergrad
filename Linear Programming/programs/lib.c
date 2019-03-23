#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *a;
	a = (int*)malloc(4*sizeof(int));
	a[10] = 2;
	printf("%d", a[11]);
	return 0;
}