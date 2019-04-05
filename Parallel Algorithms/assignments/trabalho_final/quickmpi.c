/*Algoritmo: Ordenação Quicksort paralela
  Alunos: Diego Silva Cintra e Jainor Souza Ribeiro da Cunha
  Feito para a disciplina de Algoritmos Paralelos, ministrada pelo professor
  Marco Aurélio Stefanes, docente da Faculdade de Computação da Universidade
  Federal de Mato Grosso do Sul									*/


/*  					 	OBSERVAÇÕES									*
 *   1. A leitura da entrada é feita atráves de um arquivo				*
 *      que deve ser especificado na linha de comando.					*
 *      Caso o arquivo não seja encontrado, um arquivo de números 		*
 *		aleatórios será gerado e este arquivo será usado para o 		*
 *		teste do algoritmo.												*
 *																		*
 *   2. Compilação feita da seguinte forma: 							*
 *	 	mpicc -ansi -o quickmpi quickmpi.c								*
 *																		*
 *	 3. Execução feita da seguinte forma:								*
 *	 	mpirun --mca orte_base_help_aggregate 0 -np "n" ./quickmpi "a" 	*
 *	 	Onde n é a quantidade de processos que se deseja e				*
 *	 	a é o nome do arquivo de entrada								*
 *																		*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

#include "quickmpi.h"


int main(int argc, char** argv)
{
    int my_id, numberof_processes;  /* Para tamanho do comunicador global e rank do processo 		*/
    FILE *in_file; 				 	/* Para o arquivo de entrada									*/
    unsigned long long int* inVec; 				 	/* Vetor que receberá a entrada 								*/
    int amIZero;				 	/* Facilitar saber se o rank do processo é 0					*/
    unsigned long long int in_size;					/* Tamanho do arquivo de entrada 								*/
    double start, finish; 			/* Para contar o tempo de execução do algoritmo 				*/
    unsigned long long int *myVec;						/* Vetor de dados de cada processo								*/
    unsigned long long int myVec_size;					/* Tamanho de cada subvetor										*/
    int size_of_sorting_groups;		/* Tamanho dos grupos de processadores(para a ordenação)		*/
    unsigned long long int *finalVec;					/* Para receber o vetor ordenado								*/
  	double soma = 0;
    /*	Primeira parte do algoritmo: passos pré requisitos, divisão da entrada
    	e ordenação local dos elementos de cada processo											*/
    /* 	Passos pré requisitados: Passos necessários para a execução do algoritmo
       	Passo pré requisito 0.0. Inicializar o ambiente MPI 										*/
    MPI_Init(&argc, &argv);
    
    /* 	Passo pré requisito 0.1. Atribuir rank aos processos, definir o tamanho
       	do comunicador global, inicializar amIZero e definir o tamanho dos grupos					*/
    globalSize_and_globalRank(&numberof_processes, &my_id, &amIZero, &size_of_sorting_groups);	   
   	srand(time(NULL));
   	
    /* 	Passo pré requisito 0.2. Abrir o arquivo para leitura
       	A entrada deve ser lida de um arquivo pelo processador P0 e distribuída 
       	entre os demais 																			*/
   	
   	
   

   	if(amIZero)
   	{
   		/* 	Passo pré requisito 0.2. Abrir o arquivo para leitura
       	A entrada deve ser lida de um arquivo pelo processador P0 e distribuída 
       	entre os demais 																			*/
   		/* 	Passo pré requisito 0.2.1. Abrir o arquivo para leitura									*/	
   		openFile(&in_file, (argc >=2 ? argv[1] : 0)); 
   	
   		/* 	Passo pré requisito 0.2.2. Contar o tamanho do arquivo e definir o tamanho do subvetor	*/
   		getFileSize(in_file, &in_size);
   		
    	
    	/* 	Passo pré requisito 0.4. Inicializar o vetor que possuirá a entrada						*/
    	/* 	Passo pré requisito 0.4.1. Alocar o vetor que possuirá a entrada						*/
    	/* 	Passo pré requisito 0.4.2. Preencher o vetor com os valores de entrada					*/
    	inVec = setAndFillInVec(in_file, in_size);
    
    }
   	
   	/* 	Apenas garantia da corretude das operações													*/
   	MPI_Barrier(MPI_COMM_WORLD);
   	
   	/* 	Passo pré requisito 0.2.3. Passar o tamanho do subvetor										*/
   	MPI_Bcast(&in_size, 1, MPI_UNSIGNED_LONG_LONG, 0, MPI_COMM_WORLD);	
   	
	/*	Passo pré requisito 0.2.4. Alocar o subvetor												*/
	myVec = setMyVec(in_size, numberof_processes, &myVec_size);
	
   	/* 	Passo 1. Distribuir a entrada igualmente entre os np processadores e
   		ordená-la sequencialmente																	*/
    MPI_Scatter(inVec, myVec_size, MPI_UNSIGNED_LONG_LONG, myVec, myVec_size, MPI_UNSIGNED_LONG_LONG, 0, MPI_COMM_WORLD);
    /* 	Passo pré requisito 0.3. Contar o tempo de execução do algoritmo						*/
   	/* 	Passo pré requisito 0.3.1. Disparar o cronômetro										*/
   	if(amIZero)
   		setTimer(&start);
   	
    qsort(myVec, myVec_size, sizeof(unsigned long long int), Compar);
    
    /*	Segunda parte do algoritmo: ordenar o vetor globalmente										*/																
   	finalVec = parallelQuickSort(myVec, &myVec_size, numberof_processes, my_id, size_of_sorting_groups, &soma);
    
    
    /* 	receber o vetor ordenado
    	cada processo i possui elementos menores que
 		o processo i+1   							*/
    /* 	Passo pré requisito 0.3.2. Imprimir o tempo total de execução do algoritmo					*/
    if(amIZero)
	{
    	printTime(&finish, start, in_size, soma);
    	free(inVec);
    }
    
   
    /* Passo pré requisito 0.5. Liberar alocações de memória e Finalizar o ambiente MPI				*/
   	free(finalVec);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    
    /* Passo Final. Finalizar a execução do algoritmo 												*/
    return 0;
}








