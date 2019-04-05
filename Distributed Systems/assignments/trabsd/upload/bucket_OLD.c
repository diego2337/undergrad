#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int compare(const void * a, const void * b)
{
  return *(unsigned long long int*)a - *(unsigned long long int*)b;
}

void impressao(int rank, unsigned long long int size, unsigned long long int *vector)
{
  int i;
  printf("rank %d Vector[0-%llu]=[", rank, size-1);
  for(i = 0; i < size; i++)
  {
    MPI_Barrier(MPI_COMM_WORLD);
    printf("%llu ", vector[i]);
  }
  printf("]\n");
}

int main(int argc, char *argv[])
{
  FILE *arquivo;
  MPI_Status status;
  int i, j, k, l, t, n, rank, size, *sbuf, *send_displ, root = 0, tamrbuf, *rbuf2, *rec_displ;
  unsigned long long int *VetorDados, *SubVetor, *Quartis, *BuckVector, n_p, *S, tamB, *rbuf;
  
  double startTime, endTime;
  
  /* Passo 1. Inicializacao */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  /* Passo 2. Ler arquivo */
  if(argc < 1)
  {
    if(rank == 0)
    {
      printf("Para utilizar o programa, insira o arquivo que se deseja ler a entrada - exemplo:\n");
      printf("<nome_do_executavel> <nome_arquivo>\n");
    }
  }
  /* Passo 2.1. Ler dados do arquivo */  
  if(rank == root)
  {
    arquivo = fopen(argv[1], "r");
    if(fscanf(arquivo, "%d", &t) != 1)
      printf("Falha na leitura do arquivo.\n");
    VetorDados = (unsigned long long int*)malloc((t+1)*sizeof(unsigned long long int));
    for(j = 0; j < t; j++)
    {
      if(fscanf(arquivo, "%llu", &VetorDados[j]) != 1)
        printf("Falha na leitura do arquivo.\n");
    }
    n_p = t/size;
    for(i = 1; i < size; i++)
    {
      MPI_Send(&n_p, 1, MPI_UNSIGNED_LONG_LONG, i, 0, MPI_COMM_WORLD);
    }
    fclose(arquivo);
  }
  else
  {
    MPI_Recv(&n_p, 1, MPI_UNSIGNED_LONG_LONG, root, 0, MPI_COMM_WORLD, &status);
  }
  SubVetor = (unsigned long long int*)malloc((n_p+1)*sizeof(unsigned long long int));
  /* TODO - alteração disso (size) */
  Quartis = (unsigned long long int*)malloc((size)*sizeof(unsigned long long int));
  // CONTAGEM DE TEMPO - INÍCIO
  //startTime = MPI_Wtime();
  /* Passo 3. Distribuir os dados */
  MPI_Scatter(VetorDados, n_p, MPI_UNSIGNED_LONG_LONG, SubVetor, n_p, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);  
  //impressao(rank, n_p, SubVetor);

  /* Passo 4. Calcular os Quartis */
  qsort(SubVetor, n_p, sizeof(unsigned long long int), compare);
  for(i = 1; i < size; i++)
  {
    // TODO - mudar isso pra size e size+1, problema quando size > n_p
    Quartis[i-1] = (SubVetor[((i*n_p)/size)-1] + SubVetor[((i*n_p)/size)])/2;
  }
  MPI_Barrier(MPI_COMM_WORLD);
  //puts("Quartis:");
  //impressao(rank, size-1, Quartis);
  /* Passo 4.1. Juntar os quartis no processador P0 */
  rbuf = (unsigned long long int*)malloc(size*(size-1)*sizeof(unsigned long long int));
  MPI_Gather(Quartis, size-1, MPI_UNSIGNED_LONG_LONG, rbuf, size-1, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);
  /*if(rank == root)
  {
    printf("rbuf[0-%d]: ", size*(size-1));
    for(i = 0; i < size*(size-1); i++)
      printf("%llu ", rbuf[i]);
    printf("\n");
  }*/
  /* Passo 5. Calcular os quartis dos quartis */
  S = (unsigned long long int*)malloc(size*sizeof(unsigned long long int));
  if(rank == 0)
  {
    tamrbuf = size*(size-1);
    qsort(rbuf, tamrbuf, sizeof(unsigned long long int), compare);
    for(i = 1; i < size; i++)
    {
      S[i-1] = (rbuf[((i*tamrbuf)/size)-1]+rbuf[((i*tamrbuf)/size)])/2;
    }
    /* TODO - necessidade disso - qual? */
    S[size-1] = 10000;
  }
  /*if(rank == root)
  {
    printf("S[0-%d]: ", size-2);
    for(i = 0; i < size-1; i++)
      printf("%llu ", S[i]);
    printf("\n");
  }*/

  /* Passo 6. Enviar S a todas as tarefas */
  MPI_Bcast(S, size, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);
  /* Passo 7. Calcular os buckets (tamanho da distribuição) */
  sbuf = (int*)calloc(sizeof(int), size);
  send_displ = (int*)calloc(sizeof(int), size);
  j = 0;
  k = 1;
  l = 0;
  for(i = 0; i < n_p; i++)
  {
    if(l < size-1 && SubVetor[i] < S[l])
      k++;
    else if(l >= size-1 && SubVetor[i] < S[size-1])
      k++;
    else
    {
      sbuf[j] = k-1;
      j++;
      l++;
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
  rbuf2 = (int*)calloc(sizeof(int), size);
  rec_displ = (int*)calloc(sizeof(int), size);
  MPI_Alltoall(sbuf, 1, MPI_INT, rbuf2, 1, MPI_INT, MPI_COMM_WORLD);
  /*printf("rank %d rbuf[0-%d]=[", rank, size-1);
  for(i = 0; i < size; i++)
  {
    printf("%d ", sbuf[i]);
  }
  printf("]\n");*/

  /* Passo 8. Enviar (receber) os buckets */
  rec_displ[0] = 0;
  for(i = 1; i < size; i++)
  {
    rec_displ[i] = rec_displ[i-1]+rbuf2[i-1];
  }

  tamB = 0;
  for(i = 0; i < size; i++)
  {
    tamB = tamB + rbuf2[i];
  }
  //printf("rank: %d\ttamB: %llu\n", rank, tamB);
  BuckVector = (unsigned long long int*)malloc(tamB*sizeof(unsigned long long int));
    
  MPI_Alltoallv(SubVetor, sbuf, send_displ, MPI_UNSIGNED_LONG_LONG, BuckVector, rbuf2, rec_displ, MPI_UNSIGNED_LONG_LONG, MPI_COMM_WORLD);

  /* Passo 9. Ordenar os buckets */
  qsort(BuckVector, tamB, sizeof(unsigned long long int), compare);
  // CONTAGEM DE TEMPO - FIM
  //endTime = MPI_Wtime();
  /* Passo 10. Imprimir vetor */
  for(i = 0; i < tamB; i++)
  {
    printf("rank %d de BuckVector[%d]: %llu\n", rank, i, BuckVector[i]);
  }

  if(rank == root)
    printf("A Ordenacao levou: %f segs\n", endTime-startTime);

  /* Passo 11. Liberar vetores alocados dinamicamente */
  free(S);
  free(rbuf);
  free(rbuf2);
  free(sbuf);
  free(send_displ);
  free(rec_displ);
  free(BuckVector);
  free(SubVetor);
  if(rank == root)
    free(VetorDados);
  free(Quartis);

  /* Passo 12. Finalizar a execução do MPI */
  MPI_Finalize();
  return 0;  
}