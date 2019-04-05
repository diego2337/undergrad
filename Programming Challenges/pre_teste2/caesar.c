#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char cipher[51], int shift)
{
	int i;
	for(i = 0; i < strlen(cipher); i++)
	{
		printf("%c", (cipher[i]-shift >= 'A' ? cipher[i]-shift : cipher[i]-shift + 'Z' - 'A' + 1));
	}
	printf("\n");
}

int main(void)
{
	int test_cases, shift, i, j;
	char cipher[51], c;
	scanf("%d", &test_cases);
	c = getchar();
	for(i = 0; i < test_cases; i++)
	{
		for(j = 0; j < 51; j++)
			cipher[j] = 0;
		j = 0;
		c = getchar();
		while(c != '\n')
		{
			cipher[j] = c;
			j++;
			c = getchar();
		}
		cipher[j] = '\0';
		scanf("%d", &shift);
		scanf("\n");
		decrypt(cipher, shift);
	}
	return 0;
}