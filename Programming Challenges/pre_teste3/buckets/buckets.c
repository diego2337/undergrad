#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

int isSorted(int sorted[100001], int sequence[100001], int N)
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(sorted[i] != sequence[i])
			return 0;
	}
	return 1;
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
	int N, sequence[100001], sorted[100001], i, max, max_index, last, aux;
	scanf("%d", &N);
	while(N != 0)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d", &sequence[i]);
			sorted[i] = -1;
		}
		last = N-1;
		count = 0;
		/*while(!isSorted(sorted, sequence, N))
		{
			max = 0;
			for(i = 0; i < N; i++)
			{
				if(sequence[i] > max)
				{
					max = sequence[i];
					max_index = i;
				}
			}	
			aux = sequence[max_index];
			sequence[max_index] = sequence[last];
			sequence[last] = aux;
			count++;
			sequence[last] = -1;
			last--;
			for(i = 0; i < N; i++)
				printf("%d ", sequence[i]);
			printf("\n");
		}*/
		shellSort(sequence, N);
		if(count % 2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");
		scanf("%d", &N);
	}
	return 0;
}