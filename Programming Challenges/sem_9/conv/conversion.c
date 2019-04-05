#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

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

void toBinfromBin(int n, char b[32])
{
	int i = 31;
	for(; i >= 0; i--)
	{
		b[i] = n % 10;
		n = n / 10;
	}
}

int toDec(char num[33], char c)
{
	int result = 0, i, j;
	if(c == 'b')
	{
		for(i = 31, j = 0; i >= 0 || j < 32; i--, j++)
		{
			result = result + atoi(&num[i]) * pow(2, j);
			printf("r %d\n", atoi(&num[i]));
		}
	}
	else if(c == 'h')
	{
		for(i = 31, j = 0; i >= 0 || j < 32; i--, j++)
		{
			result = result + toupper(num[i]) * pow(16, j);
		}
	}
	return result;
}

void toHex(char hex[9], char b[32])
{

}

void convert(char num[33], char c)
{
	int dec;
	char b[32], hex[9];
	/* Use binary representation because it's easier to manipulate */
	/* To decimal */
	if(c != 'd')
	{
		dec = toDec(num, c);
		printf("%d dec\n", dec);
	}

	/* To hex */
	if(c != 'h')
	{
		toHex(hex, b);
	}
}

int main(void)
{
	int test_cases, i, j;
	char c, num[33];
	scanf("%d", &test_cases);
	c = getchar();
	c = getchar();
	for(i = 0; i < test_cases; i++)
	{
		for(j = 0; j < 32; j++)
			num[j] = 0;
		j = 0;
		while(c != ' ' && c != '\n')
		{
			num[j] = c;
			c = getchar();
			j++;
			puts("kd");
		}
		c = getchar();
		printf("pi: %c\n", c);
		printf("Case %d:\n", i+1);
		convert(num, c);
		c = getchar();
	}
	return 0;
}