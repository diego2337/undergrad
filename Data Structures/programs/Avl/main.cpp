#ifndef __avl_h
#include "Avl.h"
#endif
int main()
{
	AvlTree A;
	int n;
	scanf("%d", &n);
	while(n > 0)
	{
		A.add(n);
		printf("\nArvore");
		A.preOrdTree(A.retRoot());
		scanf("%d", &n);
	}
	return 0;
}