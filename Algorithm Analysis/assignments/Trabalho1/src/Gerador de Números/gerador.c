#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	if(argv[1] == NULL)
	{
		printf("ERRO! Informe um nome de arquivo de saida ao compilar o programa.\n");
	}
	else
	{
		FILE *fout;
		clock_t start_t, end_t;
		double total_t;
   		int quantidade_gerar, i;
		unsigned long long int gerado;
		int add;
		srand(time(NULL));
		fout = fopen(argv[1],"w");
		
		scanf("%d", &quantidade_gerar); 

		/*fprintf(fout, "%d\n", quantidade_gerar);*/
		start_t = clock();
		for(i = 0;i < quantidade_gerar;i++)
		{
			add = rand() * 123;
			gerado = rand() + (9999999999*add);
			fprintf(fout, "%llu\n", gerado);
			printf("Gerado %i num\n",i);
		}

		printf("---Numeros gerados e salvos no arquivo %s---\n", argv[1]);

		fclose(fout);
		end_t = clock();
   		total_t = (double)(end_t - start_t)/(double)(CLOCKS_PER_SEC);
   		printf("Tempo total gasto: %lf\n", total_t);
	}
	return 0;
}
