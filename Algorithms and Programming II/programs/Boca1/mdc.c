#include<stdio.h>
// Programa: mdc.c
// Programador: Diego Cintra
// Data: 09/11/2012
// O dialogo: Esse programa ira calcular o mdc de dois numeros usando a recursividade.
int calculomdc(int n1, int n2)
{
	
	 
	if(n2 == 0)
	{
		return n1;
	}
	else
	{
		return calculomdc(n2, n1 % n2);
	}
	
}
int main(void)
{
	int i, n, n1, n2;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &n1, &n2);
		calculomdc(n1, n2);
		printf("%d\n", calculomdc(n1, n2));
	}
	return 0;
}
