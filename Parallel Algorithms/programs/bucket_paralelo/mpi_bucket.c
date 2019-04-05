#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  int myrank, nprocs;
  
  // Passo 1. Inicializacao
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  
  // Passo 2. Verificando qual processo
  if(myrank == 0)
    printf("Processo MASTER %d de %d\n", myrank, nprocs);
  else
    printf("Processo SLAVE %d de %d\n", myrank, nprocs);
  
  // Passo 3. Finalize o MPI
  MPI_Finalize();
  return 0;
}