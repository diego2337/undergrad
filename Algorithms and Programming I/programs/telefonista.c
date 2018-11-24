// Programa: telefonista.c
// Programador: Diego Cintra
// Data: 30/06/2012
// O dialogo: Esse programa ira procurar uma pessoa numa lista e achar seu telefone.
// Declaracao das bibliotecas
#include<stdio.h> // printf, scanf
#include<stdbool.h>
#include<string.h>
// Declaracao de tipos
typedef struct
{
    char telefone[50];
    char nome[50];
}
DADOS;
typedef DADOS CATALOGO[100];
// Inicio da funcao main
int main(void)
{
    int i, k, n, m;
    int pos;
    char nome[50];
    CATALOGO pessoas;
    bool encontrou;
    // Passo 1: Insira o numero de pessoas nessa lista
    scanf("%d", &n);
    // Passo 2: Insira o nome dessas pessoas
    for(i = 0; i < n; i++)
    {
        scanf("%s", pessoas[i].nome);
        scanf("%s", pessoas[i].telefone);
    }
    // Passo 3: Insira o numero de pessoas que ira procurar
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        // Passo 4: Insira o nome dessa pessoa
        scanf("%s", nome);
        encontrou = false;
        // Passo 5: Procure seu nome na lista
        for(k = 0; k < n && !encontrou; k++)
        {
            if(strcmp(nome, pessoas[k].nome) == 0)
            {
                encontrou = true;
                pos = k;
            }
        }
        // Passo 6: Imprima os resultados
        if(encontrou)
        printf("%s\n", pessoas[pos].telefone);
        else
        printf("%s nao tem telefone!\n", nome);
    }
    return 0;
} // Fim da funcao main
