#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	int control, bank, owner1, owner2, owner3, owner4;
} bank;

int *count, *visited;

int compare(const void * a, const void * b)
{
	bank aux = *(bank*)a;
	bank aux2 = *(bank*)b;
	if(aux.control != aux2.control) return aux.control - aux2.control;
	if(aux.bank != aux2.bank) return aux.bank - aux2.bank;
	if(aux.owner1 != aux2.owner1) return aux.owner1 - aux2.owner1;
	if(aux.owner2 != aux2.owner2) return aux.owner2 - aux2.owner2;
	if(aux.owner3 != aux2.owner3) return aux.owner3 - aux2.owner3;
	return aux.owner4 - aux2.owner4;
}

int main(void)
{
	int t, n, i, j;
	bank *accounts;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		count = (int*)calloc(n, sizeof(int));
		visited = (int*)calloc(n, sizeof(int));
		accounts = (bank*)malloc(n*sizeof(bank));
		for(j = 0; j < n; j++)
		{
			scanf("%d", &accounts[j].control);
			scanf("%d", &accounts[j].bank);
			scanf("%d", &accounts[j].owner);
		}
		qsort(accounts, n, sizeof(bank), compare);
		for(j = 0; j < n; j++)
		{
			
		}
		scanf("\n");
		free(count);
		free(visited);
	}
	return 0;
}