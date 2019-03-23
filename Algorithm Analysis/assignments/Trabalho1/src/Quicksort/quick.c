#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int get_x_bits(int msb, int lsb,unsigned long long int *elemento)
{
    return ((*elemento >> lsb) & ~(~0 << (msb-lsb+1))); 
}

int separa(unsigned long long int v[], int p, int r)
{
	unsigned long long int x, aux;
	int i, j, bit_x, bit_atual;

	x = v[r];
	i = p-1;
	for(j = p;j <= r-1;j++)
	{
		bit_atual = get_x_bits(63,42,&v[j]);
		bit_x = get_x_bits(63,42,&x);
		

		if(bit_atual < bit_x)
		{
			i++;
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}

		else if(bit_atual == bit_x)
		{
			bit_atual = get_x_bits(41,22,&v[j]);
			bit_x = get_x_bits(41,22,&x);
			if(bit_atual < bit_x)
			{
				i++;
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;		
			}

			else if(bit_atual == bit_x)
			{
				bit_atual = get_x_bits(21,0,&v[j]);
				bit_x = get_x_bits(21,0,&x);
				if(bit_atual < bit_x)
				{
					i++;
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
			}
		}
	}

	aux = v[i+1];
	v[i+1] = v[r];
	v[r] = aux;
return i+1;
}

void quicksort(unsigned long long int v[], int p, int r)
{
	int q;
	 
	if(p < r)
	{
		q = separa(v, p, r);
		quicksort(v, p, q-1);
		quicksort(v, q+1, r);
	}
}

int main(int argc, char const *argv[])
{
	if(argv[1] == NULL || argv[2] == NULL)
	{
		printf("ERRO! Informe um arquivo de entrada/saida ao executar o programa!\n");
		exit(0);
	}
	else
	{	
		FILE *fin, *fout;
		struct timeval tv1, tv2;
		int i;/*,j,k,n,m;  variáveis de apoio */
		unsigned long long int *vector; /* vetor para guardar os numeros de entrada */
		int quantidade_numeros;

		fin = fopen(argv[1], "r");
		fout = fopen(argv[2], "w");
		
		printf("Entre com o tamanho do vetor a ser ordenado: ");
		scanf("%d", &quantidade_numeros);

		vector = (unsigned long long int*)malloc(quantidade_numeros*sizeof(unsigned long long int));
		for(i = 0;i < quantidade_numeros;i++)
		{
			fscanf(fin, "%llu", &vector[i]);
		}
		
		gettimeofday(&tv1, NULL);
		quicksort(vector, 0, quantidade_numeros-1);
		gettimeofday(&tv2, NULL);
   		
		for(i = 0;i < quantidade_numeros;i++)
		{
			fprintf(fout, "%llu\n", vector[i]);
		}
	
		fclose(fin);
		fclose(fout);
		free(vector);

		printf ("Tempo total = %f segundos\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
	}

return 0;
}
