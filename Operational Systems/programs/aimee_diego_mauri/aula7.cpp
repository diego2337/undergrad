#include <stdio.h>

bool achou = false;

#define N 3
#define M 3

#define S0 0
#define S1 1
#define S2 2

/*Essa função recebe uma lista de processos, com as tabelas de solicitação e alocação, e os créditos disponíveis
e verifica se é possível que os processos na ordem em que eles estão no vetor A sejam executados sem que haja
deadlock */
bool comparaProcessos(int *a, int solicitacao[N][M], int *disponivel, int alocacao[N][M])
{
	

	int tempDisponivel[M];
	int tempAlocacao[N][M]; 
	int tempSolicitacao[N][M];
	/*Cria uma cópia dos dados originais para que a integridade dos mesmos seja preservada*/
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			tempDisponivel[j] = disponivel[j];
			tempAlocacao[i][j] = alocacao[i][j];
			tempSolicitacao[i][j] = solicitacao[i][j];
		}
	}
	/*Verifica se a execução pode ser concluida sem deadlock*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(tempSolicitacao[a[i]][j] > tempDisponivel[a[i]])
				return false;
			tempDisponivel[j] -= tempSolicitacao[a[i]][j];
			tempAlocacao[a[i]][j] += tempSolicitacao[a[i]][j];
			tempDisponivel[j] += tempAlocacao[a[i]][j];
		}
	}
	/*Caso seja possível que a execução dos processos possa ser 
	 feita em alguma ordem, sem problemas, então imprimimos a mensagem com a sequencia*/
	
	printf("Não houve deadlock. Os processos podem ser atendidos na seguinte ordem: ");
	for(int i= 0; i< N-1; i++)
	{
		printf("p%d, ", a[i]);
	}
	
	printf("p%d", a[N-1]);
	printf("\n");
	
	return true;
}


void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*Essa função calcula a permutação dos processos existentes até que uma ordem correta seja encontrada. 
  Uma ordem é correta quando os processos podem ser executados sem que haja deadlock
*/

void permute(int *a, int i, int n, int solicitacao[N][M], int *disponivel, int alocacao[N][M]) 
{
   int j; 
   if (i == n){
   		if(comparaProcessos(a, solicitacao, disponivel, alocacao))
			achou = true;
	}
   else
   {
        for (j = i; j <= n && !achou; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n, solicitacao, disponivel, alocacao);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 

int main (int argc, char *argv[])
{
	/*						S0  	S1  	S2				*/
	int disponivel[M] = { 	10, 	6, 		2 		};
	int alocacao[N][M] = 
							{
	/*								S1		S2		S3		*/
				/*P0*/			{	1,		2,		2	},
				/*P1*/			{	0,		0,		3	},
				/*P2*/			{	3,		3,		0	}
							};	
	int solicitacao[N][M] =
							{
	/*								S0		S1		S2		*/
				/*P0*/			{	2,		3,		2	},
				/*P1*/			{	1,		1,		2	},
				/*P2*/			{	1,		2,		3	}
							};


	/*A partir daqui inicia o seu código*/

	int processos[N];
	/* guarda o numero de cada processo no vetor */
	for(int i = 0; i < N; i++)
		processos[i] = i;
	
	/*Começa a permutar os processos para tentar achar uma ordem em que a execução não tenha deadlock) */
	permute(processos, 0, N-1, solicitacao, disponivel, alocacao);
	
	/*Caso nenhuma sequencia de execução dos processos 
	 * tenha dado certo então, houve deadlock  */
	
	if(!achou)
	{
		printf("Houve deadlock com os seguintes processos: ");
		for(int i = 0; i<N-1; i++)
			printf("p%d, ", processos[i]);
		printf("p%d\n", processos[N-1]);

	}
	return 0;
}