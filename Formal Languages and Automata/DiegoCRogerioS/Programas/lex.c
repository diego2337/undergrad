/*
 lex.c : analisador lexico (automato finito)
 Autor: Edna A. Hoshino
 Em: junho/2013
*/
#include <stdio.h>
#include "lex.h"

/* variaveis globais */
char lexema[81]; /* armazena a palavra processada pelo automato */
char ilexema;    /* indice usado para atualizar lexema */
int lines;       /* contador de linhas processadas */
char c;          /* armazena caracter lido da entrada */

char symbols[] = { /* alfabeto de entrada */
  '=', '+', '*', '<', '>', '(', ')', ';', ',', '{', '}', ' ', '\t', '\n', '!', '-', '&', '|', '/'
};
               
char delta[][nSymbols+3] = { /* tabela de transicao do AFD */
/*                       '=',  '+',  '*', '<', '>', '(', ')', ';', ',', '{', '}', ' ', '\t', '\n', '!', '-', '&', '|', '/', letra, dig,invalido */
/*0*/                      1,    2,    3,   4,   4,   5,   6,   7,   8,   9,  10,   0,    0,    0,  16,  17,  18,  19,  20,   11,  12, 15,
/*1*/			                13,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*2*/			                -1,   23,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*3*/			                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*4*/			                14,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*5*/			                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*6*/			                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*7*/			                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*8*/			                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1, 
/*9*/  		                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*10*/			              -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*11*/			              -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   11,  11, -1,
/*12*/        	          -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  12, -1,
/*13*/ 		                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*14*/ 		                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*15*/ 		                -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*16*/                    13,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*17*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  22,  -1,  -1,  -1,   -1,  -1, -1,
/*18*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  21,  -1,  -1,   -1,  -1, -1,
/*19*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  24,  -1,   -1,  -1, -1,
/*20*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*21*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*22*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*23*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1,
/*24*/                    -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,   -1,  -1, -1


};

char *keywords[] = { /* palavras reservadas da linguagem */
  "else", "float","for", "if", "int", "main", "void", "while"
};

int action[] = { /* ação associada a cada estado do automato */
  ERRO_LEXICO, OP_ATRIB, OP_ADIT, OP_MULT, OP_REL, ABRE_PARENT, FECHA_PARENT, PONTO_VIRG, VIRG, 
  ABRE_CHAVES, FECHA_CHAVES, ID, NUM, OP_REL, OP_REL, ERRO_LEXICO, NOT, OP_SUB, E_COMERCIAL, BARRA, OP_DIV, AND, 
  DECREMENTO, INCREMENTO, OR
};

char *terminalName[] = { /* nome dos terminais aceitos pelo automato */
  "else", "float","for", "if", "int", "main", "void", "while", "id", "num", "OP_ATRIB", "OP_ADIT", "OP_MULT", "OP_REL", "ABRE_PARENT", 
  "FECHA_PARENT", "PONTO_VIRG", 
  "VIRG", "ABRE_CHAVES", "FECHA_CHAVES", "NOT", "OP_SUB", "E_COMERCIAL", "BARRA", "OP_DIV", "AND", 
  "DECREMENTO", "INCREMENTO", "OR", "FIM"
};

/*******************************************************
 nextSymbol(): 
 - avança o ponteiro da fita de entrada do AFD
 - devolve o simbolo lido na entrada
*******************************************************/
char nextSymbol (FILE* fin)
{
  int i;

  c=getc(fin);
  if(feof(fin)){
    return FIM_ARQUIVO;
  }
  
  if (c!='\t' && c!=' ' && c!='\n'){
    lexema[ilexema++]=c;
  }
  else{
    if(c=='\n')
      lines++;
  }
  
  if(isdigit(c))
    return DIGITO;
  else if(isalpha(c))
    return LETRA;
  else{
    for(i=0;i<nSymbols && symbols[i]!=c; i++)
      ;
    if(i<nSymbols)
      return i;
    else
      return INVALIDO;
  }
}

/********************************************************************************
 isKeyword(): 
 - verifica se s eh uma palavra reservada
 - devolve o codigo da keyword s ou o codigo ID p/ indicar que s eh uma variavel.
*********************************************************************************/
char isKeyword (char *s)
{
  char i, f, m;
  int x;

  i=0; f=nKeywords-1;
  while(i<=f){
    m=(i+f)/2;
    if((x=strcmp(s,keywords[m]))>0){
      i=m+1;
    }
    else if(x<0){
      f=m-1;
    }
    else{
      return m;
    }
  }
  return ID;
}

/********************************************************************************
 lex(): 
 - realiza o processamento do AFD considerando o arquivo fin como fita de entrada
 - devolve codigo da palavra aceita pelo AFD (ou codigo de erro)
*********************************************************************************/
char lex(FILE *fin)
{
  char estado_atual, prox_estado, t, lookahead;

  ilexema =0;
  lookahead = nextSymbol(fin);
  estado_atual=0;

  while((lookahead != FIM_ARQUIVO) && (prox_estado=delta[estado_atual][lookahead]) != -1){
    estado_atual=prox_estado;
    lookahead=nextSymbol(fin);
  }

  if(lookahead!=FIM_ARQUIVO){
    if(c!='\t' && c!='\n' && c!=' '){
      ungetc(c, fin);
      ilexema--;
    }
    lexema[ilexema]='\0';
    ilexema=0;
    t=action[estado_atual];
    if(t==ID){
      return (isKeyword(lexema));
    }
    return t;
  }
  else
    return FIM;
}
