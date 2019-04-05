#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int consumo;
	int pessoas;
}drought;

int compare(const void *a, const void *b)
{
	drought aux = *(drought*)a;
	drought aux2 = *(drought*)b;
	return aux.consumo - aux2.consumo;
}

int main(void)
{
	int n, *people, *consumption, i, j, cities = 1, total_people;
	double consumo_medio;
	drought *total;
	scanf("%d", &n);
	while(n != 0)
	{
		people = (int*)malloc((n+1)*sizeof(int));
		consumption = (int*)malloc((n+1)*sizeof(int));
		total = (drought*)malloc((n+1)*sizeof(drought));
		consumo_medio = 0;
		total_people = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &people[i]);
			scanf("%d", &consumption[i]);
			total[i].consumo = consumption[i] / people[i];
			total[i].pessoas = people[i];
			consumo_medio = consumo_medio + consumption[i];
			total_people = total_people + people[i];
		}
		consumo_medio = consumo_medio / total_people;
		qsort(total, n, sizeof(drought), compare);
		printf("Cidade# %d:\n", cities);
		cities++;
		for(i = 0; i < n; i++)
		{
			j = 0;
			total_people = total[i].pessoas;
			while(i+(j+1) < n && total[i+(j+1)].consumo == total[i].consumo)
			{
				total_people = total_people+total[i+(j+1)].pessoas;
				j++;
			}
			if(i == 0)
				printf("%d-%d", total_people, total[i].consumo);
			else
				printf(" %d-%d", total_people, total[i].consumo);
			i = i+j;
		}
		printf("\n");
		printf("Consumo medio: %.2lf m3.\n", ((int)(100 *consumo_medio)) / 100.0 );
		scanf("%d", &n);
		if(n != 0)
			printf("\n");
		free(people);
		free(consumption);
		free(total);
	}
	return 0;
}