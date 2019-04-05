#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char b[], int first_one)
{
	int i = 31;
	while(i > first_one)
	{
		if(b[i] != b[first_one])
			return false;
		i--;
		first_one++;
	}
	return true;
}

void toBin(unsigned int n, char b[32], unsigned int *first_one)
{
	int c, i = 0, aux;
	bool first = true;
	for(c = 31, i; c >= 0; c--, i++)
	{
		aux = n >> c;
		if(aux & 1)
		{
			b[i] = '1';
			if(first)
				*first_one = i,	first = false;
		}
		else
			b[i] = '0';
	}
}

int main(void)
{
	unsigned int n, first_one;
	char b[32] = {'0'};
	scanf("%d", &n);
	while(n != 0)
	{
		toBin(n, b, &first_one);
		if(palindrome(b, first_one))
			printf("Numero %d e palindromo\n", n);
		else
			printf("Numero %d nao e palindromo\n", n);
		scanf("%d", &n);
	}
	return 0;
}