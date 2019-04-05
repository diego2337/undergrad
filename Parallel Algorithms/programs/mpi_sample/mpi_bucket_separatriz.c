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
  int rank, size, tam, size_e, *rbuf, *sbuf, tamrbuf, *rec_displ, *S, tamB;
  int root = 0, *send_displ;
  int i, j, k;
  int VetorDados[16] = {3, 20, 51, 12, 35, 7, 10, 40, 4, 23, 1, 9, 6, 8, 21, 2};
  int SubVetor[TAMMAX], Quartis[TAMMAX], BuckVetor[TAMMAX];
  
  double startTime, endTime;
  
  // Passo 1. Inicializacao
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  tam = (int) TAMMAX/size;
  
  startTime = MPI_Wtime();
  
  // Passo 2. Distribuicao
  MPI_Scatter(VetorDados, tam, MPI_INT, SubVetor, tam, MPI_INT, root, MPI_COMM_WORLD);
  
  /*printf("rank %d SubVetor[0-%d]=[", rank, tam-1);
  for(i = 0; i < tam; i++)
  {
    printf("%d ", SubVetor[i]);
  }
  printf("]\n");*/
  
  size_e = sizeof(int);
  qsort(SubVetor, tam, size_e, ((int(*)(const void*, const void*))Compar));
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
  
  S = (int*)malloc(size*sizeof(int));
  if(rank == 0)
  {
    tamrbuf = size*(size-1);
    qsort(rbuf, tamrbuf, size_e, ((int(*)(const void*, const void*))Compar));
    for(i = 1; i < size; i++)
    {
      S[i-1] = (rbuf[((i*tamrbuf)/size)-1]+rbuf[((i*tamrbuf)/size)])/2;
    }
    S[size-1] = 10000;
    
    /*printf("rank %d rbuf[0-%d]=[", rank, tamrbuf);
    for(i = 0; i < tamrbuf; i++)
    {
      printf("%d ", rbuf[i]);
    }
    printf("]\n");
    printf("S[0-%d]=[", size-2);
    for(i = 0; i < size-1; i++)
    {
      printf("%d ", S[i]);
    }
    printf("]\n");*/
    
  }
  
  // Passo 6. Enviar S a todas as tarefas
  MPI_Bcast(S, size, MPI_INT, root, MPI_COMM_WORLD);
  
  // Passo 7. Calcula os buckets
  sbuf=(int*)malloc(size*sizeof(int));
  send_displ = (int*)malloc(size*sizeof(int));
  j = 0;
  k = 1;
  for(i = 0; i < tam; i++)
  {
    if(SubVetor[i] < S[j])
      k++;
    else
    {
      sbuf[j] = k-1;
      j++;
      k = 1;
      i--;
    }
  }
  sbuf[j] = k-1;
  send_displ[0] = 0;
  for(i = 1; i < size; i++)
  {
    send_displ[i] = send_displ[i-1] + sbuf[i-1];
  }
  printf("rank %d SubVetor[0-%d]=[", rank, tam-1);
  for(i = 0; i < tam; i++)
  {
    printf("%d ", SubVetor[i]);
  }
  printf("]\n");
  free(rbuf);
  rbuf = (int*)malloc(size*sizeof(int));
  rec_displ = (int*)malloc(size*sizeof(int));
  
  MPI_Alltoall(sbuf, 1, MPI_INT, rbuf, 1, MPI_INT, MPI_COMM_WORLD);
  
  printf("rank %d rbuf[0-%d]=[", rank, size-1);
  for(i = 0; i < size; i++)
  {
    printf("%d ", rbuf[i]);
  }
  printf("]\n");
  
  // Passo 8.2. Envie (receba) os buckets
  rec_displ[0] = 0;
  for(i = 1; i < size; i++)
  {
    rec_displ[i] = rec_displ[i-1]+sbuf[i-1];
  }
    
  MPI_Alltoallv(SubVetor, sbuf, send_displ, MPI_INT, BuckVetor, rbuf, rec_displ, MPI_INT, MPI_COMM_WORLD);
  
  // Passo 9. Ordene os buckets
  tamB = 0;
  for(i = 0; i < size; i++)
  {
    tamB = tamB + rbuf[i];
  }
  
  qsort(BuckVetor, tamB, size_e, ((int(*)(const void*, const void*))Compar));
  
  // Passo 10. Imprime vetor 
  for(i = 0; i < tamB; i++)
  {
    printf("rank %d de BuckVetor[%d]: %d\n", rank, i, BuckVetor[i]);
  }
  
  endTime = MPI_Wtime();
  
  if(rank == root)
    printf("A Ordenacao levou: %f segs\n", endTime-startTime);

  free(S);
  free(rbuf);
  free(sbuf);
  free(send_displ);
  free(rec_displ);
  // Passo 10. Finalize o MPI
  MPI_Finalize();
  return 0;
}