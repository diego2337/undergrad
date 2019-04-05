// www.GeeksBR.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

// struct aluno para guardar os dados de cada aluno
typedef struct aluno
{
    char nome[16];
    int pontuacoes[12];
    int totalPontuacao;
    int classificacao;
} taluno;

typedef int (*compfn)(const void*, const void*);

// fun��o para comparar as pontua��es para que sejam ordenadas
int compare(const void * a, const void * b)
{
    return (*(int*)a - * (int*)b);
}

// fun��o para ordenar o total de pontos
int comp(taluno *x, taluno *y)
{
    // verifica se a pontua��o do aluno x � igual a pontua��o do aluno y
    if(x->totalPontuacao == y->totalPontuacao)
    {

        // se for igual ent�o compara os nomes
        if(strcmp(x->nome, y->nome) > 0)
            return -1;
        if(strcmp(x->nome, y->nome) < 0)
            return 1;
        return 0;
    }
    
    return (x->totalPontuacao - y->totalPontuacao);
}

int main()
{
    taluno alunos[MAX]; // declara��o do vetor alunos
    int teste = 1;
    int J, i, k, flag, soma;
    do
    {
        scanf("%d", &J); // pega a quantidade de alunos
        if(J == 0) break;
        for(i = 0; i < J; i++) // for para armazenar os alunos
        {
            scanf("%s", alunos[i].nome); // armazena o nome
            alunos[i].totalPontuacao = 0; // inicializa com 0 a pontua��o
            
            for(k = 0; k < 12; k++) // armazena as 12 pontua��es de cada jogador
            {
                scanf("%d", &alunos[i].pontuacoes[k]);
                alunos[i].totalPontuacao += alunos[i].pontuacoes[k];
            }
            
            // qsort ordenar as pontua��es em ordem crescente
            qsort(alunos[i].pontuacoes, (size_t) 12, sizeof(int), compare);
            
            // a pontua��o maior e a menor s�o descartadas do total
            alunos[i].totalPontuacao -= alunos[i].pontuacoes[0];
            alunos[i].totalPontuacao -= alunos[i].pontuacoes[11];
        }
        
        // qsort para ordenar o total das pontua��es
        qsort(alunos, (size_t) J, sizeof(taluno), (compfn)comp);
        
        printf("Teste %d\n", teste);
        printf("1 %d %s\n", alunos[J - 1].totalPontuacao, alunos[J - 1].nome);
        flag = J - 2;
        soma = 1;
        
        /* 
           for para imprimir o �ndice, a pontua��o e o nome.
           O �ndice � em ordem crescente, a pontua��o em ordem decrescente e o
           nome em ordem crescente caso haja empate.
        */
        for(i = 1; flag >= 0; flag--)
        {
            if(alunos[flag].totalPontuacao != alunos[flag + 1].totalPontuacao)
            {
                i += soma;
                soma = 1;
            }
            else
            {
                soma++;
            }
            printf("%d %d %s\n", i, alunos[flag].totalPontuacao, alunos[flag].nome);
        }
        printf("\n");
        teste++;
    }
    while(1);
    return 0;
}

