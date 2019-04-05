#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define TAMMAX 16

/*int Compar(const void * a, const void * b)
{
  return *(int*)a - *(int*)b;
}*/

int Compar(const int * Lhs, const int *Rhs)
{
  int LeftKey = *Lhs;
  int RightKey = *Rhs;
  
  return LeftKey < RightKey ? -1 : LeftKey != RightKey;
}

int main(int argc, char *argv[])
{
  int rank, size, tam, size_e, *rbuf, tamrbuf;
  int root = 0;
  int i;
  int VetorDados[16] = {3, 20, 51, 12, 35, 7, 10, 40, 4, 23, 1, 9, 6, 8, 21, 2};
  int SubVetor[TAMMAX], Quartis[TAMMAX];
  
  // Passo 1. Inicializacao
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  tam = (int) TAMMAX/size;
  
  // Passo 2. Distribuicao
  MPI_Scatter(VetorDados, tam, MPI_INT, SubVetor, tam, MPI_INT, root, MPI_COMM_WORLD);
  
  /*printf("rank %d SubVetor[0-%d]=[", rank, tam-1);
  for(i = 0; i < tam; i++)
  {
    printf("%d ", SubVetor[i]);
  }
  printf("]\n");*/
  
  size_e = sizeof(int);
  qsort(SubVetor, tam, size_e, Compar);
  for(i = 1; i < size; i++)
  {
    Quartis[i-1] = (SubVetor[((i*tam)/size)-1] + SubVetor[((i*tam)/size)])/2;
  }
  
 /* printf("rank %d Quartil[0-%d]=[", rank, tam-2);
  for(i = 0; i < tam-1; i++)
  {
    printf("%d ", Quartis[i]);
  }
  printf("]\n");*/
 
  rbuf = (int*)malloc(size*(size-1)*sizeof(int));
  MPI_Gather(Quartis, size-1, MPI_INT, rbuf, size-1, MPI_INT, root, MPI_COMM_WORLD);
  
  /*if(rank == 0)
  {
    tamrbuf = size*(size-1);
    printf("rank %d rbuf[0-%d]=[", rank, tamrbuf);
    for(i = 0; i < tamrbuf; i++)
    {
      printf("%d ", rbuf[i]);
    }
    printf("]\n");
  }*/
  
  // Passo 3. Finalize o MPI
  MPI_Finalize();
  return 0;
}