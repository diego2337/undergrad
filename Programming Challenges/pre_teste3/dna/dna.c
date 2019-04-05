#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void shellSort(int vet[100001], int size) 
{
    int i , j , value;
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
            while (j >= 0 && value < vet[j]) 
            {
                vet [j + gap] = vet[j];
                count++;
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}


int main(void)
{
	int t, n, elements[100001], i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		count = 0;
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%d", &elements[j]);
		}
		shellSort(elements, n);
		printf("%d\n", count);
	}
	return 0;
}