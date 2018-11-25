/*
 parser.c : analisador sintatico (exemplo de automato com pilha)
 Autor: Edna A. Hoshino
 Em: junho/2013

 Reconhece programas escritos na linguagem C-.
 C- eh um subconjunto da linguagem C. C- nao contem:
  0) expressoes relacionais e operadores !=, &&, ||;
  1) declaracao de variaveis locais nem globais;
  2) operadores  ++, --, &, -, /;
  3) vetores;
  4) chamada de funcao;
  5) numeros com ponto decimal;
  6) comentarios de bloco e linha;
  7) constantes literais (cadeias delimitadas por ");
  8) comando for, return e break;
  9) tipo char, ponteiros.
 
 A saida do analisador apresenta o total de linhas processadas e uma mensagem de erro ou sucesso. 
 Atualmente, nao ha controle sobre a coluna e a linha em que o erro foi encontrado.
*/

#include "lex.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#define DEBUG  /* descomente esta linha se quiser visualizar conteudo da pilha e simbolo de entrada a cada passo da execucao do automato */

/* variaveis globais */
int topo; /* indice para o topo da pilha */
char pilha[MAXPILHA]; /* pilha do AP*/
char msgErro[200];

/*********************************************************************
 error(): 
 - mostra msg de erro e aborta o programa
**********************************************************************/
void error(char *msg)
{
  printf(msg);
  exit(1);
}

/*********************************************************************
 push(): 
 - substitui o topo da pilha pelo lado direto da producao s 
**********************************************************************/
void push(tProduction s)
{
  int i;

  topo--;
  for(i=s.length-1; i>=0;i--){
    pilha[++topo]=s.rightSide[i];
    if(topo>MAXPILHA){
      error("\nLimite de pilha alcancado!\n");
    }
  }
}

void mostraPilha()
{
  int i;

  printf("\n==========================================\nConteudo da pilha:");
  for(i=topo;i>=0;i--){
    if(isVariable(pilha[i]))
      printf("\npilha[%d]= variavel %s", i, variableName[CodVariable(pilha[i])]);
    else
      printf("\npilha[%d]= terminal %s", i, terminalName[pilha[i]]);
  }
}

/*******************************************************************************************
 parser(): 
 - efetua o processamento do automato com pilha AP
 - devolve uma mensagem para indicar se a "palavra" (programa) estah sintaticamente correta.
********************************************************************************************/
char *parser(FILE *fin)
{
  char token;
  int numProd;

  topo = 0;
  pilha[topo] = initialVariable;//COD(S);
  if((token=lex(fin))==ERRO_LEXICO){
    return ("Simbolo invalido!");
  }
  while (topo >= 0){
#ifdef DEBUG
    mostraPilha();
    printf("\nToken atual: %d (%s)\n", token, terminalName[token]);
#endif
    if(isVariable(pilha[topo])){
      // variavel no topo da pilha?
      if(isProduction((numProd=M[CodVariable(pilha[topo])][token]))){
	// existe transicao?
	push(productions[numProd]);
      }
      else{
	return (erros[numProd-nProductions]);
      }
    }
    else{
      // terminal no topo da pilha
      if(token == pilha[topo]){
#ifdef DEBUG
	printf("\nToken %d (%s) casado!", token, terminalName[token]);
#endif
	// desempilha e avança fita de entrada
	topo--;
	if((token=lex(fin))==ERRO_LEXICO){
	  return ("Simbolo invalido!");
	}
      }
      else{
	sprintf(msgErro, "Esperado token %d (%s)", pilha[topo], terminalName[pilha[topo]]);
	return(msgErro);
      }
    }
  }
  if(token==FIM)
    return("Programa sintaticamente correto!");
  else
    return("Fim de arquivo esperado");
}

void main(int argc, char**argv)
{
  FILE *fin;

  if(argc<2){
    printf("\nUse: compile <filename>\n");
  }
  else{
    printf("\nAnalisando lexica e sintaticamente o programa: %s", argv[1]);
    fin=fopen(argv[1], "r");
    if(!fin){
      printf("\nProblema na abertura do programa %s\n", argv[1]);
      exit(1);
    }
    printf("\nTotal de linhas processadas: %d\nResultado: %s\n", lines, parser(fin));
    fclose(fin);
  }
}

