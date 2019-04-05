#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int pos;
	char name[81];
} turtle;

void shellSort(turtle vet[200], int size) 
{
    int i , j;
    turtle value;
    int gap = 1;
    while(gap < size) 
    {
        gap = 3*gap+1;
    }
    while ( gap > 1) 
    {
        gap /= 3;
        for(i = gap; i < size; i++) 
        {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value.pos < vet[j].pos) 
            {
                vet [j + gap] = vet[j];
                j -= gap;
                printf("%s\n", vet[j].name);
            }
            vet [j + gap] = value;
        }
    }
}

int main(void)
{
	int K, n, i, j, k;
	turtle shells[200], desired_shells[200];
	char c;
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		scanf("%d", &n);
		c = getchar();
		c = getchar();
		for(j = 0; j < n; j++)
		{
			k = 0;
			while(c != '\n' && c != EOF)
			{
				shells[j].name[k] = c;
				k++;
				c = getchar();
			}
			shells[j].name[k] = '\0';
			c = getchar();
		}
		for(j = 0; j < n; j++)
		{
			k = 0;
			while(c != '\n' && c != EOF)
			{
				desired_shells[j].name[k] = c;
				k++;
				c = getchar();
			}
			desired_shells[j].name[k] = '\0';
			for(k = 0; k < n; k++)
			{
				if(strcmp(shells[k].name, desired_shells[j].name) == 0)
				{
					shells[k].pos = j;
				}
			}
			c = getchar();
			if(isdigit(c))
				ungetc(c, stdin);
		}
		shellSort(shells, n);
	}
	return 0;
}