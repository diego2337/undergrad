/* 	Arquivo quickmpi.h
	Este arquivo contém as assinaturas e o corpo de 
	métodos utilizados no algoritmo quicksort paralelo,
	no arquivo quickmpi.c */

#ifndef _quickmpi_h
#define _quickmpi_h

/* Inclusão das bibliotecas necessárias aos algoritmos */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 	Estruturas usadas no algoritmo. Não alinhadas pois
	estamos prezando velocidade a uso de memória		*/
/*	Smaller_elements guarda o vetor de elementos menores que
	o pivot atual e o tamanho dele						*/
typedef struct smaller_elements
{
	unsigned long long int *smaller_array;
	unsigned long long int smaller_quantity;
} smaller_elements;


/*	Larger_elements guarda o vetor de elementos maiores que
	o pivot atual e o tamanho dele						*/
typedef struct larger_elements
{
	unsigned long long int *larger_array;
	unsigned long long int larger_quantity;
}larger_elements;


/*	Recv_elements guarda o vetor de elementos recebidos
	pelo parceiro de comunicação atual e o tamanho dele	*/
typedef struct recv_elements
{
	unsigned long long int *recv_array;
	unsigned long long int recv_quantity;
}recv_elements;


/*	*	*	*	*	*	*	*	*	*	*	*  MÉTODOS	*	*	*	*	*	*	*	*	*	*	*	*/		


/* 
	Método: globalSize_and_globalRank
	Descrição: esta função define o tamanho do comunicador
	global e atribui, a cada processo, seu rank
*/
void globalSize_and_globalRank(int *size, int *rank, int *amIZero, int *size_of_sorting_groups)
{
	MPI_Comm_size(MPI_COMM_WORLD, size);
	MPI_Comm_rank(MPI_COMM_WORLD, rank);
	*amIZero = (*rank == 0 ? 1 : 0);
	*size_of_sorting_groups = *size;
}


/*
	Método: Compar
	Descrição: método de comparação usado no algoritmo
	qsort da biblioteca <cstdlib>
*/
int Compar(const void * a, const void * b)
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
	Método: pot
	Descrição: potência de um número
*/
unsigned long long int pot(unsigned long long int base, unsigned long long int expoente)
{

	if(expoente == 0)
		return 1;
	else
		return base * pot(base, expoente-1);
}



/*
	Método: putIntsOnFile
	Descrição: escreve números inteiros aleatórios
	em um arquivo
*/
void putIntsOnFile(FILE *in_file)
{
	
	int tam = rand() % 20;
	unsigned long long int in_size = pot(10, tam); 
	unsigned long long int i;
	for(i = 0; i < in_size; i++)
		fprintf(in_file, "%llu\n", rand() % pot(2, tam));
}


/*
	Método: openFile
	Descrição: esta função abre o arquivo especificado
	na linha de comando ou gera um arquivo aleatório
	para testar o funcionamento do algoritmo
*/
void openFile(FILE **in_file, char *filename)
{
	if(filename == 0)
	{
		*(in_file) = fopen("random.in", "w");
		putIntsOnFile(*in_file);
	}
	
	else
		*(in_file) = fopen(filename, "r");
	
}


/*
	Método: getFileSize
	Descrição: retorna o número de inteiros de um arquivo.
*/
void getFileSize(FILE *in_file, unsigned long long int *in_size)
{
	int size = 0;
	int mula;
	while(!feof(in_file))
	{
		fscanf(in_file, "%d\n", &mula);
		size++;
	}
	rewind(in_file);
	*in_size = size;
}


/*
	Método: setTimer
	Descrição: dispara o cronômetro e põe o valor em uma variável 
	de precisão dupla
*/
void setTimer(double *tempo)
{
	printf("Disparando o cronômetro...\n");
	*tempo = MPI_Wtime();
}


/*
	Método: printTime()
	Descrição: recebe os valores de tempo(inicial e presente),
	calcula a diferença e imprime o resultado na stdout
*/
void printTime(double *now, double start, unsigned long long int in_size, double soma)
{
	*now = MPI_Wtime() - start;
	printf("O algoritmo quicksort paralelizado levou %f segundos para executar, contando com comm_split.\n", *now);
	printf("Sem contar com o tempo de comm_split, o tempo de execução foi %f segundos\n", *now - soma);
	printf("O tamanho da entrada era de %llu números.\n", in_size);
}


/*
	Método: setAndFillInVec
	Descrição: preenche o vetor de entrada com os inteiros
	do arquivo de entrada
*/
unsigned long long int* setAndFillInVec(FILE *in_file, unsigned long long int in_size)
{
	unsigned long long int it = 0;
	unsigned long long int* inVec = (unsigned long long int *) malloc(sizeof(unsigned long long int) * in_size);
	while(!feof(in_file))
	{
		fscanf(in_file, "%llu\n", (inVec+it));
		it++;
	}
	fclose(in_file);
	return inVec;
}


/*
	Método: setMyVec
	Descrição: prepara o vetor myVec para receber os valores
	que virão de P0 a partir do Scatter
*/
unsigned long long int* setMyVec(int in_size, int numberof_processes, unsigned long long int *myVec_size)
{
	*myVec_size = (in_size/numberof_processes);
	unsigned long long int* myVec = (unsigned long long int *) malloc(sizeof(unsigned long long int) * (*myVec_size));
	return myVec;
}


/*
	Método: setAndSharePivot
	Descrição: seleciona o pivot aleatoriamente, para a execução
	do algoritmo quicksort paralelo e o compartilha entre os outros n processadores
*/
void 
setAndSharePivot(unsigned long long int *pivot, int my_id, unsigned long long int *myVec,
				 unsigned long long int myVec_size, int size_of_sorting_groups, MPI_Comm my_comm)
{
	
	
	int my_virtual_id = my_id % size_of_sorting_groups;
	
	
	
	if(my_virtual_id == 0)
	{
		int randomElement;
		if(myVec_size > 0)
		{
			randomElement = rand() % myVec_size;
			*pivot = myVec[randomElement];
		}
		/*else
			*pivot = my_id;*/
	}
	
	MPI_Bcast(pivot, 1, MPI_UNSIGNED_LONG_LONG, 0, my_comm);
	

}


/*
	Método: setSmaller
	Descrição: retorna os elementos que são menores que o pivot
	atual, dada a lista de elementos de um processo 
*/
smaller_elements setSmaller(unsigned long long int *myVec, unsigned long long int pivot, unsigned long long int myVec_size)
{
	smaller_elements smaller;
	unsigned long long int it, quantity = 0;
	
	smaller.smaller_quantity = 0;
	for(it = 0; it < myVec_size; it++)
		if(myVec[it] <= pivot)
			smaller.smaller_quantity++;
	
	smaller.smaller_array = (unsigned long long int *) malloc(sizeof(unsigned long long int) * smaller.smaller_quantity);
	for(it = 0; it < myVec_size; it++)
		if(myVec[it] <= pivot)
			smaller.smaller_array[it] = myVec[it];
	
	return smaller;

}

/*
	Método: setLarger
	Descrição: retorna os elementos que são maiores que o pivot
	atual, dada a lista de elementos de um processo
*/
larger_elements setLarger(unsigned long long int *myVec, unsigned long long int pivot, unsigned long long int myVec_size)
{
	larger_elements larger;
	unsigned long long int it, larger_it = 0;
	
	larger.larger_quantity = 0;
	for(it = 0; it < myVec_size; it++)
		if(myVec[it] > pivot)
			larger.larger_quantity++;
			
	larger.larger_array = (unsigned long long int *) malloc(sizeof(unsigned long long int) * larger.larger_quantity);
	for(it = 0; it < myVec_size; it++)
	{
		if(myVec[it] > pivot)
		{
			larger.larger_array[larger_it] = myVec[it];
			larger_it++;
		}
		
	}
	return larger;
}

/*
	Método: setGroups
	Descrição: separa os processadores em dois grupos distintos,
	"metade maior" e "metade menor"
*/
int setGroups(int size_of_sorting_groups)
{
	if(size_of_sorting_groups >= 1)	
		return size_of_sorting_groups/2;
	else
		return 0;
}


/*	
	Método: shareInfo
	Descrição: Os processos da metade maior enviam suas listas
	de elementos menores que o pivot para os processos da metade menor.
	Aqueles da metade menor enviam suas listas de elementos maiores que
	o pivot para os processos da metade maior
*/
recv_elements 
shareInfo(int size_of_sorting_groups, smaller_elements *smaller, larger_elements *larger, 
		  int numberof_processes, int my_id, MPI_Comm my_comm)
{
	unsigned long long int send_quantity, i;
	recv_elements recv;
	int my_virtual_id = my_id % size_of_sorting_groups;
	
	  
	if(my_virtual_id < size_of_sorting_groups/2)
	{
		send_quantity = larger->larger_quantity;
		MPI_Send(&send_quantity, 1, MPI_UNSIGNED_LONG_LONG, my_id+size_of_sorting_groups/2, 0, MPI_COMM_WORLD);
		
		MPI_Send(larger->larger_array, send_quantity, MPI_UNSIGNED_LONG_LONG, my_id+size_of_sorting_groups/2, 0, MPI_COMM_WORLD);

		MPI_Recv(&(recv.recv_quantity), 1, MPI_UNSIGNED_LONG_LONG, my_id+size_of_sorting_groups/2, 
				 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		
		recv.recv_array = (unsigned long long int *) malloc(sizeof(unsigned long long int) * recv.recv_quantity);
		
		MPI_Recv(recv.recv_array, recv.recv_quantity, MPI_UNSIGNED_LONG_LONG, my_id+size_of_sorting_groups/2,
				   0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
	}
	else 
	{
		send_quantity = smaller->smaller_quantity;
		MPI_Recv(&(recv.recv_quantity), 1, MPI_UNSIGNED_LONG_LONG, my_id-size_of_sorting_groups/2, 
				 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		
		recv.recv_array = (unsigned long long int *) malloc(sizeof(unsigned long long int) * recv.recv_quantity);
		MPI_Recv(recv.recv_array, recv.recv_quantity, MPI_UNSIGNED_LONG_LONG, my_id-size_of_sorting_groups/2, 
				 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				
		MPI_Send(&send_quantity, 1, MPI_UNSIGNED_LONG_LONG, my_id-size_of_sorting_groups/2, 0, MPI_COMM_WORLD);
		MPI_Send(smaller->smaller_array, send_quantity, 
				 MPI_UNSIGNED_LONG_LONG, my_id-size_of_sorting_groups/2, 0, MPI_COMM_WORLD);
	
	}
	return recv;
	
}


/*
	Método: intercala
	Descrição: faz a junção de dois vetores de tamanhos m e n,
	respectivamente, e põe em um terceiro vetor de tamanho m+n
*/
unsigned long long int* joinVecs(unsigned long long int *vec, unsigned long long int vec_size, unsigned long long int *vec2, unsigned long long int vec2_size)
{
	unsigned long long int vec3_size = vec_size + vec2_size;
	unsigned long long int *vec3 = (unsigned long long int *) malloc(sizeof(unsigned long long int) * vec3_size);
	unsigned long long int it, j = 0;
	
	for(it = 0; it < vec3_size; it++)
	{
		if(it < vec_size)
			vec3[it] = vec[it];
		else
		{
			vec3[it] = vec2[j];
			j++;
		}
	
	}
	
	return vec3;
}


/*
	Método: join
	Descrição: prepara um novo vetor para a intercalação de dois outros e
	libera a memória gasta por vetores que não são mais úteis aos processos
*/
unsigned long long int*
join(larger_elements *larger, smaller_elements *smaller, recv_elements *recv, 
	 int my_id, int size_of_sorting_groups, unsigned long long int *myVec_size)
{
	unsigned long long int new_size;
	unsigned long long int *new_vec;
	int my_virtual_id = my_id % size_of_sorting_groups;
	
	if(my_virtual_id < size_of_sorting_groups/2)
	{
		new_size = smaller->smaller_quantity + recv->recv_quantity;
		new_vec = joinVecs(smaller->smaller_array, smaller->smaller_quantity, 
						   recv->recv_array, recv->recv_quantity);
						   
		larger->larger_quantity = 0;
	}
	else
	{
		new_size = larger->larger_quantity + recv->recv_quantity;
		new_vec = joinVecs(larger->larger_array, larger->larger_quantity, 
						   recv->recv_array, recv->recv_quantity);
		
		smaller->smaller_quantity = 0;
	}
	
	*myVec_size = new_size;
	
	return new_vec; 
}


/*
	Método: setComm
	Descrição: faz o split de um comunicador MPI em outro
*/
void setComm(MPI_Comm *my_comm, int size_of_sorting_groups, int my_id)
{

	int my_color = my_id/size_of_sorting_groups;
	int my_virtual_id = my_id % size_of_sorting_groups;
	
	MPI_Comm_split(MPI_COMM_WORLD, my_color, my_virtual_id, my_comm);
}


/*
	Método: checkAndFree
	Descrição: checa se os vetores alocados
	dinamicamente em uma recursão ainda estão alocados,
	se sim, libera o espaço
*/
void checkAndFree(smaller_elements *smaller, larger_elements *larger, recv_elements *recv)
{
	if(smaller->smaller_array != 0)
		free(smaller->smaller_array);
	
	if(larger->larger_array != 0)
		free(larger->larger_array);
	
	if(recv->recv_array != 0)
		free(recv->recv_array);

}


/*
	Método: get_x_bits
	Descrição: separa os bits de um elemento unsigned long long int
	em seus bits mais e menos significativos, msb e lsb,
	respectivamente.
*/
int get_x_bits(int msb, int lsb, unsigned long long int *elemento)
{
    return ((*elemento >> lsb) & ~(~0 << (msb-lsb+1))); 
}


/*
	Método: parallelQuickSort
	Descrição: começa a executar o algoritmo de ordenação
	QuickSort paralelo
*/
unsigned long long int *
parallelQuickSort(unsigned long long int *myVec, unsigned long long int *myVec_size, int numberof_processes, 
				  int my_id, int size_of_sorting_groups, double *soma)
{
	smaller_elements smaller; 		/* Lista de elementos menores que o pivot						*/
    larger_elements larger; 		/* Lista de elementos maiores que o pivot						*/
    recv_elements recv;				/* Elementos que serão recebidos								*/
    unsigned long long int pivot;						/* Pivot do algoritmo, escolhido aleatoriamente					*/
    MPI_Comm my_comm;				/* Comunicador do grupo corrente de um processo					*/
    double a, b;
	/* 	Passo 0. Condição de parada da recursão														*/
	if(size_of_sorting_groups <= 1)
	{
		if(my_id == 0)
			printf("Tempo total gasto com comm_split: %f\n", *soma);
		return myVec;
	}
	if(my_id == 0)
		a = MPI_Wtime();
	/*	Faz o split do comunicador, dependendo do tamanho dos grupos de ordenação					*/
	setComm(&my_comm, size_of_sorting_groups, my_id);
	if(my_id == 0)
	{
		b = MPI_Wtime() - a;
		*soma = *soma + b;
	}
	
	/* 	Passo 1. Selecionar o Pivot																	*/
	/* 	Passo 2. Distribuir o Pivot entre os n processadores										*/
	setAndSharePivot(&pivot, my_id, myVec, *myVec_size, size_of_sorting_groups, my_comm);
	
	/*MPI_Barrier(MPI_COMM_WORLD);*/
	
    /* 	Passo 3. Separar as entradas de cada processo em Lower e Upper, com base no Pivot 			*/
    smaller = setSmaller(myVec, pivot, *myVec_size);
   	larger = setLarger(myVec, pivot, *myVec_size);
    
    /* 	Passo 4. Trocar informações entre os processos dos grupos									*/
    recv = shareInfo(size_of_sorting_groups, &smaller, &larger, numberof_processes, my_id, my_comm);
    
    /* 	Passo 5. juntar as duas listas de cada processo e ordenar a lista resultante				*/
    free(myVec);
    myVec = join(&larger, &smaller, &recv, my_id, size_of_sorting_groups, myVec_size);
    qsort(myVec, *myVec_size, sizeof(unsigned long long int), Compar);
    checkAndFree(&smaller, &larger, &recv);
    
    /* 	Passo 6. Redefinir o tamanho dos grupos 
    /* 	Passo 7. Executar a operação recursivamente													*/
	size_of_sorting_groups = setGroups(size_of_sorting_groups);
	parallelQuickSort(myVec, myVec_size, numberof_processes, my_id, size_of_sorting_groups, soma);
}

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/





#endif
