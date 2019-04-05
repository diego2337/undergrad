#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 16

int main(int argc, char *argv[])
{
 	int i, tam, npes, rank, VetorDados[TAMMAX], *SubVetor, SomaP = 0, *SomaPre, Soma = 0;
	srand(time(NULL));

	printf("\n");
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	tam = (int) TAMMAX/npes;

	SubVetor = (int*)calloc(tam, sizeof(int));
	SomaPre = (int*)calloc(tam, sizeof(int));
	
	if(rank == 0)
	{
		for(i = 0; i < TAMMAX; i++)
		{
			VetorDados[i] = rand() % 20;
		}

		for(i = 0; i < TAMMAX; i++)
		{
			printf("%d\n", VetorDados[i]);
		}


	}
  	MPI_Scatter(VetorDados, tam, MPI_INT, SubVetor, tam, MPI_INT, 0, MPI_COMM_WORLD);
  	for(i = 0; i < tam; i++)
  	{
    	SomaP = SomaP + SubVetor[i];
  	}
	MPI_Scan(&SomaP, &Soma, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	SomaPre[0] = Soma - SomaP + SubVetor[0];
	for(i = 1; i < tam; i++)
	{
	  SomaPre[i] = SomaPre[i-1] + SubVetor[i];
	}
	for(i = 0; i < tam; i++)
	{
	  printf("rank %d e SomaPre[%d]: %d\n", rank, i, SomaPre[i]);
	}
	MPI_Finalize();
	return 0;
}