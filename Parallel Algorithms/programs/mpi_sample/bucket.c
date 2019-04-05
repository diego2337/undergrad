#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define TAMMAX 16

int compare(const void * a, const void * b)
{
  return *(int*)a - *(int*)b;
}

int main(int argc, char *argv[])
{
  FILE *arquivo;
  int rank, size, tam, size_e, *rbuf, *sbuf, tamrbuf, *rec_displ, *S, tamB, root = 0, *send_displ;
  int i, j, k;
  long int n, t, *VetorDados, *SubVetor, *Quartis, *BuckVetor, n_p;
  
  double startTime, endTime;
  
  // Passo 1. Inicializacao
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  /* Passo 2. Ler arquivo */
  if(argc < 2)
  {
    if(rank == 0)
    {
      printf("Para utilizar o programa, insira o arquivo que se deseja ler a entrada e o algoritmo a ser executado - exemplo:\n");
      printf("<nome_do_executavel> <nome_arquivo> <nome_algoritmo>\n");
      printf("onde o nome do algoritmo pode ser 'quicksort' ou 'samplesort'.\n");
    }
    exit(0);
  }
  arquivo = fopen(argv[1], "r");
  if(arquivo != NULL)
  {
    /* Passo 2.1. Ler dados do arquivo */
    fscanf(arquivo, "%ld", &n);
    for(i = 0; i < n; i++)
    {
      fscanf(arquivo, "%ld", &t);
      VetorDados = (long int*)malloc((t+1)*sizeof(long int));
      if(rank == root)
      {
        for(j = 0; j < t; j++)
        {
          fscanf(arquivo, "%ld", &VetorDados[j]);
        }
      }
      /* Passo 3. Distribuir os dados */
      n_p = t/size;
      SubVetor = (long int*)malloc((n_p+1)*sizeof(long int));
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
      qsort(SubVetor, tam, size_e, compare);
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
        qsort(rbuf, tamrbuf, size_e, compare);
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
        printf("%ld ", SubVetor[i]);
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
      
      qsort(BuckVetor, tamB, size_e, compare);
      
      // Passo 10. Imprime vetor 
      for(i = 0; i < tamB; i++)
      {
        printf("rank %d de BuckVetor[%d]: %ld\n", rank, i, BuckVetor[i]);
      }
      
      endTime = MPI_Wtime();
      
      if(rank == root)
        printf("A Ordenacao levou: %f segs\n", endTime-startTime);

      free(S);
      free(rbuf);
      free(sbuf);
      free(send_displ);
      free(rec_displ);
      free(VetorDados);
      free(SubVetor);
    } 
  }
  

  // Passo 10. Finalize o MPI
  MPI_Finalize();
  return 0;
}