// Programa: somadigitos.c
// Programador: Diego Cintra
// Data: 09/11/2012
// O dialogo: Esse programa ira pegar um numero e somar seus digitos, utilizando da recursividade.
#include<stdio.h>
int somdig(int numero) 
{
	int x, y;
	x = numero % 10;
	y = (numero - x) / 10;
	if(y <= 0)
	{
		return x;
	}
	else
	{
		return x + somdig(y);
	}
}
int main(void)
{
	int i, n, numero;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &numero);
		somdig(numero);
		printf("%d\n", somdig(numero));
	}
	return 0;
}
