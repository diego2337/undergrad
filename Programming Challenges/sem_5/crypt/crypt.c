#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char fox[43] = "the quick brown fox jumps over the lazy dog";
bool found = true;

void find_the_fox(char caracteres[], char frases[101][101], int n_phrases)
{
	int i, j, k;
	bool found2 = false;
	for(i = 0; i < n_phrases; i++)
	{
		for(j = 0; j < strlen(frases[i]); j++)
		{
			if(frases[i][3] == ' ' && frases[i][9] == ' ' && frases[i][15] == ' ' && frases[i][19]
				&& frases[i][25] == ' ' && frases[i][30] == ' ' && frases[i][34] == ' '
				&& frases[i][39] == ' ')
			{
				for(k = 0; k < 43; k++)
				{
					if(fox[k] != ' ' && caracteres[frases[i][k]-97] != -1 && caracteres[frases[i][k]-97] != fox[k])
					{
						k = 45;
						j = strlen(frases[i]) + 10;
						found2 = false;
					}
					else if(fox[k] != ' ')
					{
						caracteres[frases[i][k]-97] = fox[k];
						if(k == 42)
							found2 = true;
					}
					/*frases[i][k] = -1;*/
				}
				/*for(k = 0; k < 26; k++)
				{
					printf("%c ", caracteres[k]);
				}*/
			}
		}
	}
	/* Se sim, entao nao foi encontrada a frase chave */
	if(!found2)
	{
		printf("No solution.\n");
		found = false;
	}
}

void decrypt(char caracteres[], char frases[101][101], int n_phrases)
{
	int i, j;
	for(i = 0; i < n_phrases; i++)
	{
		for(j = 0; j < strlen(frases[i]); j++)
		{
			if(frases[i][j] == ' ')
				printf(" ");
			else
				printf("%c", caracteres[frases[i][j]-97]);
		}
		printf("\n");
	}
}

int main(void)
{
	/* Todas as letras do alfabeto - o indice corresponde a letra, em ordem (ou seja, 'a' eh igual a 0, 'b' eh 1, e assim por diante */
	char caracteres[27], frases[101][101], c;
	int i, j, k, test_cases, n_phrases;
	scanf("%d", &test_cases);
	c = getchar();
	c = getchar();
	for(i = 0; i < test_cases; i++)
	{
		for(j = 0; j < 101; j++)
		{
			for(k = 0; k < 101; k++)
				frases[j][k] = 0;
		}
		for(j = 0; j < 26; j++)
			caracteres[j] = -1;
		j = 0; 
		found = true;
		c = getchar();
		while((c != '\n' && c != EOF))
		{
			k = 0;
			frases[j][k] = c;
			k++;
			c = getchar();
			while((c != '\n'))
			{
				frases[j][k] = c;
				k++;
				c = getchar();
			}
			frases[j][k] = '\0';
			j++;
			c = getchar();
		}
		n_phrases = j;
		/*for(j = 0; j < n_phrases; j++)
		{
			for(k = 0; k < strlen(frases[j]); k++)
			{
				printf("%c", frases[j][k]);
			}
			printf("\n");
		}*/
		find_the_fox(caracteres, frases, n_phrases);
		if(found)
			decrypt(caracteres, frases, n_phrases);
		if(i+1 != test_cases)
			printf("\n");
	}
	return 0;
}