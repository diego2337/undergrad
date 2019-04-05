#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i, size, rank, *VetorDados, *SubVetor, *SomaPre, SomaP = 0, Soma = 0, tam_max, tam;
	FILE *flumine;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	flumine = fopen("exemplo.txt", "r");
	fscanf(flumine, "%d", &tam_max);
	tam = (int) tam_max/size;
	VetorDados = (int*)calloc(tam_max, sizeof(int));
	SubVetor = (int*)calloc(tam, sizeof(int));
	SomaPre = (int*)calloc(tam, sizeof(int));
	if(rank == 0)
	{
		for(i = 0; i < tam_max; i++)
		{
			fscanf(flumine, "%d", &VetorDados[i]);
		}
		for(i = 0; i < tam_max; i++)
			printf("%d\n", VetorDados[i]);
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
		SomaPre[i] = SomaPre[i - 1] + SubVetor[i];
	} 
	for(i = 0; i < tam; i++)
	{
		printf("rank %d e SomaPre[%d]: %d\n", rank, i, SomaPre[i]);
	}
	fclose(flumine);
	MPI_Finalize();
	return 0;
}