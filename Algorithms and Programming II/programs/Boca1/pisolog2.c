#include<stdio.h>
// Programa: pisolog2.c
// Programador: Diego Cintra
// Data: 09/11/2012
// O dialogo: Esse programa ira calcular o piso de log2 na base n.
int piso(int num, int counter)
{
	if(num < 2)
	return counter;
	else
	return piso(num/2, counter + 1);
}
int main(void)
{
	int i, n, num, counter = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		piso(num, counter);
		printf("%d\n", piso(num, counter));
	}
	return 0;
}
