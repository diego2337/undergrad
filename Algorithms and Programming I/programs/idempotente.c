// Programa: idempotente.c
// Programador: Diego Cintra
// Data: 05/07/2012
// O dialogo: Esse programa ira ler uma matriz de tamanho n x n e verificar se ela e idempotente ou nao.
// Declaracao das bibliotecas
#include<stdio.h> // Printf, scanf
#include<string.h>
// Declaracao de funcoes
void mult_mat(int n, int A[100][100], int B[100][100], int C[100][100]); // ira multiplicar as matrizes
int iguais(int n, int A[100][100], int B[100][100]); // ira verificar se A = B
// Inicio da funcao main
int main(void)
{
    // Declaracao das variaveis
    int A[100][100], B[100][100], C[100][100], linhascolunas, j, n, k, i;
    // Inicio da funcao for
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        // Passo 1: Insira o tamanho da matriz. Visto que ela e n x n, e necessario somente um valor.
        scanf("%d", &linhascolunas);
        for(j = 0; j < linhascolunas; j++)
        {
            for(k = 0; k < linhascolunas; k++)
            scanf("%d", &A[j][k]);
        }
        // Passo 2: Iguale-a a outra matriz para fazer multiplicacao de matrizes
        for(j = 0; j < linhascolunas; j++)
        {
            for(k = 0; k < linhascolunas; k++)
            B[j][k] = A[j][k];
        }
        // Passo 3: Faca a multiplicacao das matrizes
        mult_mat(n, A, B, C); // Chamada da funcao
        /*for(j = 0; j < linhascolunas; j++)
        {
            for(k = 0; k < linhascolunas; k++)
            A[j][k] = C[j][k];
        }*/
        // Passo 4: Verifique se a matriz A e igual a matriz B
        iguais(n, A, C); // Chamada da funcao
        // Passo 5: Imprima os resultados
        if(iguais(n, A, C) == 1)
        printf("I\n");
        else
        printf("N\n");
    }
    return 0;
} // Fim da funcao main

void mult_mat(int n, int A[100][100], int B[100][100], int C[100][100])
{
    // Essa funcao ira fazer multiplicacao das matrizes.
    // Declaracao das variaveis
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
        }
    }
    return;
} // Fim da funcao

int iguais(int n, int A[100][100], int C[100][100])
{
    // Essa funcao ira verificar se A = B
    int i, j;
    for (i = 0; i < n; i += 1)
    {   
		for(j = 0; j < n; j++)
		    {
		        if(A[i][j] != C[i][j])
		        return 0;
		    }
     }   
     return 1;
} // Fim da funcao

