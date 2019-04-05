#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int sum(char b1[32], char b2[32])
{
	int i, j;
	unsigned int soma = 0;
	for(i = 0, j = 31; i < 32, j >= 0; i++, j--)
	{
		if((b1[j] == '1' && b2[j] == '0') || (b1[j] == '0' && b2[j] == '1'))
		{
			soma += pow(2, i);
		}
	}
	return soma;
}

void toBin(unsigned int n, char b[32])
{
	int c, i = 0, aux;
	for(c = 31, i; c >= 0; c--, i++)
	{
		aux = n >> c;
		if(aux & 1)
			b[i] = '1';
		else
			b[i] = '0';
	}
}

int main(void)
{
	unsigned int n1, n2, soma;
	int i;
	char b1[32] = {'0'}, b2[32] = {'0'};
	while(scanf("%u %u", &n1, &n2) != EOF)
	{
		toBin(n1, b1);
		toBin(n2, b2);
		soma = sum(b1, b2);
		printf("%u\n", soma);
	}
	return 0;
}