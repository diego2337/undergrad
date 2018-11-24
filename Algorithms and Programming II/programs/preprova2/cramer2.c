#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int **m, *v, **maux;
	int i, j, k, rep;
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		m = (int**)malloc (3*sizeof(int*));
		for(j = 0; j < 3; j++)
		m = (int*)malloc (3*sizeof(int));
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			scanf("%d", &(*(*(m+j)+k)));
		}
		v = (int*)malloc (3*sizeof(int*));
		for(j = 0; j < 3; j++)
		scanf("%d", *(v+j);
		maux = determinante(m);
		pos = 0;
		troca(m, v, pos);
		x = determinante(m)/maux;
		troca(m, v, pos);
		pos = 1;
		troca(m, v, pos);
		y = determinante(m)/maux;
		troca(m, v, pos);
		pos = 2;
		troca(m, v, pos);
		z = determinante(m)/maux;
		troca(m, v, pos);
		if(determinante(m) == 0)
		printf("singular\n");
		else
		printf("%d %d %d\n", x, y, z);
		
	}
}
