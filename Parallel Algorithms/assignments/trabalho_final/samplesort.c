/*
*   Programa: Ordenação Samplesort paralela
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
*    mpirun.openmpi --mca orte_base_help_aggregate 0 -np "n" ./sample "a"
*    Onde n é a quantidade de processos que se deseja e "a" é o nome do arquivo de entrada.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/* Constante a ser utilizada para definição de intervalo de separadores maiores que o último separador selecionado */
#define MAX_UNSIGNED_INT 18446744070000000001u

/*
* Essa função irá retornar o inteiro especificado com os valores entre os bits 'lsb' e 'msb', aonde 
* lsb = least significant bit (bit menos significativo),
* msb = most significant bit (bit mais significativo) e
* elemento = número a ser extraído o valor
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
* Aqui executa-se o Samplesort propriamente dito; a sequência de passos está descrita dentro da função. Argumentos:
* nlocal: quantidade de dados para cada vetor distribuído para cada processador
* elmnts: vetor de elementos já distribuído para cada processador
* nsorted: variável que posteriormente será alterada e indicará a quantidade de elementos contidos em cada processador ao fim da execução do
* Samplesort
* comm: domínio de comunicação
*/
unsigned long long int *SampleSort(unsigned long long int nlocal, unsigned long long int *elmnts, 
	unsigned long long int *nsorted, MPI_Comm comm)
{
	int i, j, npes, myrank, *scounts, *sdispls, *rcounts, *rdispls;
	unsigned long long int *sorted_elmnts, *splitters, *allpicks;

	/* Passo 4.1. Recuperar o domínio e o rank do processador */
	MPI_Comm_size(comm, &npes);
	MPI_Comm_rank(comm, &myrank);

	/* Passo 4.2. Alocar memória para os vetores que guardarão os separadores */
	splitters = (unsigned long long int*)malloc(npes*sizeof(unsigned long long int));
	allpicks = (unsigned long long int*)malloc(npes*(npes-1)*sizeof(unsigned long long int));

	/* Passo 4.3. Ordenar vetor local */
	qsort(elmnts, nlocal, sizeof(unsigned long long int), compare);
	for(i = 1; i < npes; i++)
	{
		splitters[i-1] = elmnts[i*nlocal/npes];
	}

	/* Passo 4.4. Reunir os separadores nos processadores */
	MPI_Allgather(splitters, npes-1, MPI_UNSIGNED_LONG_LONG, allpicks, npes-1, MPI_UNSIGNED_LONG_LONG, comm);

	/* Passo 4.5. Ordenar os separadores */
	qsort(allpicks, npes*(npes-1), sizeof(unsigned long long int), compare);

	/* Passo 4.6. Selecionar separadores */
	for(i = 1; i < npes; i++)
	{
		splitters[i-1] = allpicks[(i*npes)-1];
	}
  splitters[npes-1] = MAX_UNSIGNED_INT;

	/* Passo 4.7. Calcular a quantidade de elementos em cada bucket */
	scounts = (int*)malloc(npes*sizeof(int));
	for(i = 0; i < npes; i++)
	{
		scounts[i] = 0;
	}
	for(j = i = 0; i < nlocal; i++)
	{
		if(elmnts[i] < splitters[j])
		{
			scounts[j]++;
		}
		else
		{
      i--;
      j++;
			/*scounts[++j]++;*/
		}
	}

	/* Passo 4.8. Determinar o índice de início de cada bucket no vetor elmnts */
	sdispls = (int*)malloc(npes*sizeof(int));
	sdispls[0] = 0;
	for(i = 1; i < npes; i++)
	{
		sdispls[i] = sdispls[i-1] + scounts[i-1];
	}

	/* Passo 4.9. Realizar uma comunicação All-to-all para informar as quantidades de elementos que cada processador irá receber */
	rcounts = (int*)malloc(npes*sizeof(int));
	MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, comm);

	/* Passo 4.10. Determinar em qual local do vetor final esses dados serão guardados, com os dados armazenados em rcounts */
	rdispls = (int*)malloc(npes*sizeof(int));
	rdispls[0] = 0;
	for(i = 1; i < npes; i++)
	{
		rdispls[i] = rdispls[i-1] + rcounts[i-1];
	}
	*nsorted = rdispls[npes-1]+rcounts[i-1];
	sorted_elmnts = (unsigned long long int*)malloc((*nsorted+1)*sizeof(unsigned long long int));

	/* Passo 4.11. Realizar comunicação alltoallv, indicando a quantidade de elementos em cada bucket e seus respectivos índices para cada processador */
	MPI_Alltoallv(elmnts, scounts, sdispls, MPI_UNSIGNED_LONG_LONG, sorted_elmnts, rcounts, rdispls, MPI_UNSIGNED_LONG_LONG, comm);

	/* Passo 4.12. Ordenar o vetor local */
	qsort(sorted_elmnts, *nsorted, sizeof(unsigned long long int), compare);

  /* Passo 4.13. Liberar memória alocada */
	free(splitters);
	free(allpicks);
	free(scounts);
	free(sdispls);
	free(rcounts);
	free(rdispls);

	/* Passo 4.14. Retornar o vetor ordenado */
	return sorted_elmnts;
}

/*
* Na função main, a leitura do arquivo é feita, a inicialização do vetor de dados é executada e a invocação do Samplesort é realizada.
*/
int main(int argc, char *argv[])
{
  FILE *arquivo;
  MPI_Status status;
  int i, j, t, rank, size, root = 0;
  unsigned long long int *VetorDados, *SubVetor, n_p, *VetorOrdenado, tam;
  
  double startTime, endTime;
  
  /* Passo 1. Inicializacao */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /* Passo 2. Ler arquivo */
  if(argc < 2)
  {
    if(rank == 0)
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
    VetorDados = (unsigned long long int*)malloc((t+1)*sizeof(unsigned long long int));
    VetorOrdenado = (unsigned long long int*)malloc((t+1)*sizeof(unsigned long long int));
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

  /* Passo 3. Distribuir os dados */
  MPI_Scatter(VetorDados, n_p, MPI_UNSIGNED_LONG_LONG, SubVetor, n_p, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);  

  /* Passo 4. Aplicar o algoritmo SampleSort */
  startTime = MPI_Wtime();
  VetorOrdenado = SampleSort(n_p, SubVetor, &tam, MPI_COMM_WORLD);
  endTime = MPI_Wtime();

  /* Passo 5. Imprimir os dados ordenados do vetor */
  /*for(i = 0; i < tam; i++)
  {
    printf("%llu\n", VetorOrdenado[i]);
  }*/
  if(rank == root)
  {
    printf("A Ordenacao levou: %f segs\n", endTime-startTime);
  }

  /* Passo 6. Liberar vetores alocados dinamicamente */
  free(SubVetor);
  if(rank == root)
  {
    free(VetorDados);
    free(VetorOrdenado);
  }

  /* Passo 7. Finalizar a execução do MPI */
  MPI_Finalize();
  return 0;  
}
