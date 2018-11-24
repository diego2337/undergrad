// Programa: estudante.c
// Programador: Diego Cintra
// Data: 23/11/2012
// O dialogo: Esse programa ira procurar o nome de um estudante com base no seu numero. Se esse estudante nao for achado, retornara not found.
#include<stdio.h>
typedef struct
	{
		int numest;
		char nomest[20];
	}
	ESTUDANTE;
int buscabin(ESTUDANTE array[100], int n, int k)
{
	int esq, dir, meio;
	esq = -1;
	dir = n;
	while(esq < dir-1)
	{		
		meio = (esq + dir)/2;
		if(array[meio].numest < k)
		esq = meio;
		else
		dir = meio;
	}
	if(array[dir].numest == k)
	return dir;
	else
	return -1;
}

int main(void)
{
	int i, n, j, k, s, rep;
	ESTUDANTE array[100];
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		scanf("%d", &k); // numero do estudante que queremos achar
		scanf("%d", &n); // tamanho do vetor
		for(j = 0; j < n; j++)
		scanf("%d %s", &array[j].numest, array[j].nomest);
		s = buscabin(array, n, k); // chamada da funcao
		if(buscabin(array, n, k) != -1)
		printf("%s\n", array[s].nomest);
		else
		printf("not found\n");
	}
	return 0;
}
