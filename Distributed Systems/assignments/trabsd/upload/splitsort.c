/*
*   Programa: Ordenação Splitsort paralela
*   Alunos: Diego Silva Cintra e Jainor Souza Ribeiro da Cunha
*   Feito para a disciplina de Algoritmos Paralelos, ministrada pelo professor Marco Aurélio Stefanes, docente da Faculdade de Computação da 
*   Universidade Federal de Mato Grosso do Sul, no primeiro semestre de 2015.
*
*   1. A leitura da entrada é feita atráves de um arquivo que deve ser especificado na linha de comando. Esse arquivo DEVE existir,
*   do contrário a execução será encerrada. A primeira linha desse arquivo deve conter a quantidade de elementos que serão lidos.
*
*   2. Compilação feita da seguinte forma:
*     mpicc.openmpi -g -o sample samplesort.c
*
*   3. Execução feita da seguinte forma:
*    mpirun.openmpi --mca orte_base_help_aggregate 0 -np "n" ./split "a"
*    Onde n é a quantidade de processos que se deseja e "a" é o nome do arquivo de entrada.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_UNSIGNED_INT 18446744070000000001u

/*
* Essa função irá retornar o inteiro especificado com os valores entre os bits 'lsb' e 'msb', aonde 
* lsb = least significant bit (bit menos significativo)
* msb = most significant bit (bit mais significativo)
*/
int get_x_bits(int msb, int lsb,unsigned long long int *elemento)
{
  return ((*elemento >> lsb) & ~(~0 << (msb-lsb+1))); 
}

/*
* Essa função, necessária para a execução do qsort, irá extrair e comparar os valores dos 22 bits mais significativos, 
* sucedido dos 20 bits adjacentes e por fim dos 22 bits menos significativos, conforme requisitado
*/
int compare(const void * a, const void * b)
{
  unsigned long long aux = *(unsigned long long int*)a;
  unsigned long long aux2 = *(unsigned long long int*)b;
  int x, y;
  x = get_x_bits(63, 42, &aux);
  y = get_x_bits(63, 42, &aux2);
  if(x == y)
  {
    x = get_x_bits(41, 22, &aux);
    y = get_x_bits(41, 22, &aux2);
    if(x == y)
    {
      x = get_x_bits(21, 0, &aux);
      y = get_x_bits(21, 0, &aux2);
    }
  }
  if(x < y) return -1;
  else if(x == y) return 0;
  else return 1;
}

/*
* Na função principal, ocorre a execução do algoritmo Splitsort propriamente dito; os passos estão comentados ao longo do código. 
* Nos argumentos temos a leitura do arquivo de entrada para alocação do vetor que será utilizado na ordenação.
*/
int main(int argc, char *argv[])
{
  FILE *arquivo;
  MPI_Status status;
  int i, j, k, l, t, rank, size, root = 0, tamrbuf, *sbuf, *send_displ, *rbuf2, *rec_displ;
  unsigned long long int *VetorDados, *SubVetor, *Quartis, *BuckVector, n_p, *S, tamB, *rbuf;
  
  double startTime, endTime;
  
  /* Passo 1. Inicializacao */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /* Passo 2. Ler arquivo */
  if(argc < 2)
  {
    if(rank == root)
    {
      printf("Para utilizar o programa, insira o arquivo que se deseja ler a entrada - exemplo:\n");
      printf("<nome_do_executavel> <nome_arquivo>\n");
      MPI_Finalize();
      exit(0);
    }
  }

  /* Passo 2.1. Ler dados do arquivo */  
  if(rank == root)
  {
    arquivo = fopen(argv[1], "r");
    if(arquivo == NULL)
    {
      printf("Falha na abertura do arquivo.\n");
      MPI_Finalize();
      exit(0);
    }
    if(fscanf(arquivo, "%d", &t) != 1)
    {
      printf("Falha na leitura do arquivo.\n");
      MPI_Finalize();
      exit(0);
    }
    /*printf("Insira a quantidade de elementos do vetor: ");
    scanf("%d", &t);*/
    VetorDados = (unsigned long long int*)malloc((t+1)*sizeof(unsigned long long int));
    for(j = 0; j < t; j++)
    {
      if(fscanf(arquivo, "%llu", &VetorDados[j]) != 1)
      {
        printf("Falha na leitura do arquivo.\n");
        MPI_Finalize();
        exit(0);
      }
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
  Quartis = (unsigned long long int*)malloc((size)*sizeof(unsigned long long int));

  /* Passo 3. Distribuir os dados */
  MPI_Scatter(VetorDados, n_p, MPI_UNSIGNED_LONG_LONG, SubVetor, n_p, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);

  /* CONTAGEM DE TEMPO - INÍCIO */
  startTime = MPI_Wtime();

  /* Passo 4. Calcular os Quartis */
  qsort(SubVetor, n_p, sizeof(unsigned long long int), compare);
  for(i = 1; i < size; i++)
  {
    /* TODO - mudar isso pra size e size+1, problema quando size > n_p */
    Quartis[i-1] = (SubVetor[((i*n_p)/size)-1] + SubVetor[((i*n_p)/size)])/2;
  }

  /* Passo 4.1. Juntar os quartis no processador P0 */
  rbuf = (unsigned long long int*)malloc(size*(size-1)*sizeof(unsigned long long int));
  MPI_Gather(Quartis, size-1, MPI_UNSIGNED_LONG_LONG, rbuf, size-1, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);

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
    S[size-1] = MAX_UNSIGNED_INT;
  }

  /* Passo 6. Enviar S a todas as tarefas */
  MPI_Bcast(S, size, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);

  /* Passo 7. Calcular os buckets (tamanho da distribuição) */
  sbuf = (int*)calloc(sizeof(int), size);
  send_displ = (int*)calloc(sizeof(int), size);
  /* j = 0; */
  k = 0;
  l = 0;
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < n_p; j++)
    {
      if(i == 0)
      {
        if(SubVetor[j] < S[i])
        {
          k++;  
        }
      }
      else
      {
        if(SubVetor[j] < S[i] && SubVetor[j] >= S[i-1])
        {
          k++;
        }
      }
    }
    sbuf[l] = k;
    l++;
    k = 0;
  }
  send_displ[0] = 0;
  for(i = 1; i < size; i++)
  {
    send_displ[i] = send_displ[i-1] + sbuf[i-1];
  }
  rbuf2 = (int*)calloc(sizeof(int), size);
  rec_displ = (int*)calloc(sizeof(int), size);
  MPI_Alltoall(sbuf, 1, MPI_INT, rbuf2, 1, MPI_INT, MPI_COMM_WORLD);

  /* Passo 8. Enviar (receber) os buckets */
  rec_displ[0] = 0;
  for(i = 1; i < size; i++)
  {
    rec_displ[i] = rec_displ[i-1]+rbuf2[i-1];
  }

  /* Passo 9. Calcular o tamanho de cada bucket */
  tamB = 0;
  for(i = 0; i < size; i++)
  {
    tamB = tamB + rbuf2[i];
  }
  BuckVector = (unsigned long long int*)malloc(tamB*sizeof(unsigned long long int));
  MPI_Alltoallv(SubVetor, sbuf, send_displ, MPI_UNSIGNED_LONG_LONG, BuckVector, rbuf2, rec_displ, MPI_UNSIGNED_LONG_LONG, MPI_COMM_WORLD);

  /* Passo 10. Ordenar os buckets */
  qsort(BuckVector, tamB, sizeof(unsigned long long int), compare);

  /* CONTAGEM DE TEMPO - FIM */
  endTime = MPI_Wtime();
  
  /* Passo 11. Imprimir vetor */
  for(i = 0; i < tamB; i++)
  {
    printf("%llu\n", BuckVector[i]);
  }
  if(rank == root)
  {
    printf("A Ordenacao levou: %f segs\n", endTime-startTime);
  }
  
  /* Passo 12. Liberar vetores alocados dinamicamente */
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

  /* Passo 13. Finalizar a execução do MPI */
  MPI_Finalize();
  return 0;  
}
