#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rontgen(char n[1001], int k)
{
	int i, j, l, m, count;
	char *ront, *aux, num, aux2[100];
	ront = (char*)malloc(2000001*sizeof(char));
	aux = (char*)malloc(2000001*sizeof(char));
	for(j = 0; j < strlen(n); j++)
	{
		ront[j] = n[j];
	}
	ront[j] = '\0';
	for(i = 0; i < k; i++)
	{
		num = ront[0];
		count = 0;
		l = 0;
		for(j = 0; j < strlen(n); j++)
		{
			if(ront[j] == num)
				count++;
			else
			{
				if(count != 0)
					printf("%d%c", count, num);
				num = ront[j];
				m = 0;
				while(count / 10 > 0)
				{
					aux2[m] = count%10+48;					
					count = count/10;
					m++;
				}
				aux2[m] = count;
				m++;
				aux2[m] = '\0';
				printf("------------------\n");
				for(m = strlen(aux2); m >= 0; m--)
				{
					aux[l] = aux2[m];
					l++;
					puts("isso mrm");
					printf("%c", aux[l]);
				}
				printf("posso\n");
				aux[l] = num;
				l++;
				count = 0;
			}
		}
		if(count != 0)
			printf("%d%c", count, num);
		m = 0;
		while(count / 10 > 0)
		{
			aux2[m] = count%10+48;					
			count = count/10;
			m++;
		}
		aux2[m] = count;
		m++;
		aux2[m] = '\0';
		printf("------------------\n");
		for(m = strlen(aux2); m >= 0; m--)
		{
			aux[l] = aux2[m];
			l++;
			puts("isso mrm");
			printf("%c\n", aux[l]);
		}
		printf("posso\n");
		aux[l] = num;
		l++;
		aux[l] = '\0';
		for(j = 0; j < strlen(aux); j++)
		{
			ront[j] = aux[j];		
		}
		ront[j] = '\0';
	}
	free(ront);
	free(aux);
}

int main(void)
{
	int test_cases, k, i;
	char n[1001];
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%s %d", n, &k);
		rontgen(n, k);
	}
	return 0;
}