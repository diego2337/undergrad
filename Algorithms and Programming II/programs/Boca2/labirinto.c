// Programa: labirinto.c
// Programador: Diego Cintra
// Data: 15/11/2012
// O dialogo: Esse programa ira ler uma matriz que representa um labirinto, e achar todas as soluçoes possiveis para esse labirinto.
#include<stdio.h>
int valido(int n, int m, char l[100][100], int ln, int lm)
{
	int ret = 0;
	if(n < ln && m < lm && n >= 0 && m >= 0)
	{
		if(l[n][m] == '1')
		ret = 1;
	}	
	return ret;
}

int procura(int n, int m)
{
	int an, am, i, j, l;
	if(an == (n-1) && am == (m-1))
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			printf("%d ", l[i][j]);
			printf("\n");
		}
	}
	else
	{
		l[an][am] = '*';
		if(valido(an, am + 1, l[100][100]), ln, lm)
		procura(n, m+1);
		if(valido(an + 1, am, l[100][100]), ln, lm))
		procura(n+1, m);
		if(valido(an, am - 1, l[100][100]), ln, lm))
		procura(n, m-1);
		if(valido(an-1, am, l[100][100]), ln, lm))
		procura(n-1, m);
		l[an][am] = '1';
	}
}

int main(void)
{
	int n, m, i, j;
	char l[5][10];
	for(j = 3; j < 4; j++)
	{
		for(i = 0; i < 5; i++)	
		l[j][i] = 1;
			
	}
	
	// Faça todos os caminhos possiveis
	procura(n, m);
	// Imprima o resultado
	return 0;
}
