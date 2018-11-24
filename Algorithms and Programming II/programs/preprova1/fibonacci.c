#include<stdio.h>
// Programa: fibonacci.c
// Programador: Diego Cintra
// Data: 09/11/2012
// O dialogo: Esse programa ira devolver o i-ésimo termo de uma sequencia fibonacci.
int fibonacci(int num)
{
	int x, y;
	if(num == 1)
	return 1;
	else if(num == 2)
	return 1;
	else
	x = fibonacci(num-1);
	y = fibonacci(num-2);
	return x + y;
}
int main(void)
{
	int i, n, num;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		fibonacci(num);
		printf("%d\n", fibonacci(num));
	}
return 0;
}
