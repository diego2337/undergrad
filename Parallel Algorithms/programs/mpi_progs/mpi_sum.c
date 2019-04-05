#include <mpi.h>
#include <stdio.h>

#define TAMMAX 128

int main(int argc, char *argv[])
{
    int size, rank, tam, SubVetor[TAMMAX], VetorDados[TAMMAX] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, SomaP, Soma, i, j;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    tam = (int)TAMMAX/size;
    if(rank == 0)
    {
      for(i = 1; i < size; i++)
      {
        for(j = 0; j < tam; j++)
        {
          SubVetor[j] = VetorDados[tam*i+j];
        }
        MPI_Send(SubVetor, tam, MPI_INT, i, 1, MPI_COMM_WORLD);
      }
      for(j = 0; j < tam; j++)
      {
        SubVetor[j] = VetorDados[j];
      }
    }
    else
    {
      MPI_Recv(SubVetor, tam, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    }
    for(i = 0; i < tam; i++)
    {
      SomaP = SomaP + SubVetor[i];
    }
    MPI_Reduce(&SomaP, &Soma, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0)
      printf("Soma: %d\n", Soma);
    MPI_Finalize();
    return 0;
}