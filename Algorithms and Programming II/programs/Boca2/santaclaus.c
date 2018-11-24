// Programa: santaclaus.c
// Programador: Diego Cintra
// Data: 20/11/2012
// O dialogo: Esse programa ira imprimir todas as solucoes possiveis a partir da posicao numero 1, e na ordem crescente.
#include<stdio.h> // printf, scanf
void procura(int p, int mat[5][5], int atual, int c[9])
{
	int j;
	if(p == 8)
	{
		for(j = 0; j < 9; j++)
			printf("%d ", c[j]);
		printf("\n");
	}
	else
	{
		//printf("%d\n", p);
		for(j = 0; j < 5; j++)
		if(mat[atual][j] == 1)
		{
			mat[atual][j] = 2;
			mat[j][atual] = 2;
			c[p] = atual+1;
			procura(p+1, mat, j, c);
			mat[atual][j] = 1;
			mat[j][atual] = 1;
		}
	}
}
int main(void)
{
	int p, c[9], atual;
	int  mat[5][5] = {{0,1,1,0,1},{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{1,1,1,1,0}};
	atual = 0;
	p = 0;
	procura(p, mat, atual, c);
	return 0;
}
