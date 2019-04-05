#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return n * fact(n-1);
}

int mult_fact(int alphabet[25])
{
	int i, final_fact = 1;
	for(i = 0; i < 25; i++)
	{
		if(alphabet[i] > 0)
		{
			final_fact = final_fact * fact(alphabet[i]);
			printf("%d\n", alphabet[i]);
		}
	}
	printf("%d\n", final_fact);
	return final_fact;
}

void rep_permutation(int alphabet[25], int j)
{
	printf("%d\n", fact(j)/mult_fact(alphabet));
}

int main(void)
{
	char c;
	int alphabet[25], i, j;
	c = getchar();
	while(c != EOF)
	{
		j = 0;
		for(i = 0; i < 25; i++)
		{
			alphabet[i] = 0;
		}
		while(c != '\n' && c != EOF)
		{
			alphabet[c-65] = alphabet[c-65] + 1;
			j++;
			c = getchar();
		}
		for(i = 0; i < 25; i++)
		{
			printf("%d ", alphabet[i]);
		}
		rep_permutation(alphabet, j);
		c = getchar();
	}
	return 0;
}