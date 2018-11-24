// Programa: quadmagico.c
// Programador: Diego Cintra
// Data: 30/06/2012
// Este programa le uma matriz quadrada e verifica se ela e uma quadrado
// magico. Ou seja, se a soma das linhas, colunas e diagonais principal
// e secundaria tem o mesmo valor.
// Declaracao das bibliotecas utilizadas
#include<stdio.h>
#include<stdbool.h>
// Inicio da funcao principal
int main(void)
{
    // Declaracao das variaveis locais
    int matriz[10][10], k, kp, i, j, n, linhas, colunas, soma, soma2;
    bool quadmagico;
    // Inicio da funcao for
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        // Passo 1: Leia o formato da matriz
        scanf("%d %d", &linhas, &colunas);
        // Passo 2: Leia a matriz
        for(j = 0; j < linhas; j++)
        {
            for(k = 0; k < colunas; k++)
            scanf("%d", &matriz[j][k]);
        }
        // Inicialize as somas
        soma = 0;
        soma2 = 0;
        // Passo 3: Some as colunas
        for(k = 0; k < colunas; k++)
        {
            for(j = 0; j < linhas; j++)
            soma = soma + matriz[j][k];
        }
        soma = soma / linhas;
        // Passo 4: Some as linhas
        for(j = 0; j < linhas; j++)
        {
            for(k = 0; k < colunas; k++)
            soma2 = soma2 + matriz[j][k];
        }
        soma2 = soma2 / colunas;
        // Passo 5: Compare
        // printf("%d %d\n", soma, soma2);
        if(soma == soma2)
        {
            quadmagico == true;
            // Passo 6: Some as diagonais
            for(j = 0; j < linhas; j++)
            {
                for(k = j; k < 1; k++)
                soma = soma + matriz[j][k];
            }
            // Soma da diagonal secundaria
            kp = colunas - 1;
            for(k = colunas -1; k >= 0; k--)
            {
                for(j = kp - k; j < k; j++)
                soma2 = soma2 + matriz[j][k];
            }
            printf("%d %d\n", &soma, &soma2);
            // Passo 7: Compare
            if(soma == soma2)
            quadmagico == true;
            // Passo 8: Imprima os resultados
            if(quadmagico == true)
            printf("1\n");
        }
        else
        printf("0\n");
    } // Fim da funcao for
    return 0;
} // Fim da funcao main
