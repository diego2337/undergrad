/*
  avaliaLex.c
  Faz chamadas sucessivas ao lex() para reconhecer todas as palavras validas pelo automato
  Faça:
     gcc avaliaLex.c lex.c -o avaliaLex

*/
#include "lex.h"
#include <stdlib.h>

void main(int argc, char **argv){
  char t;
  FILE *fin;

  if(argc<2){
    printf("\nUse: lex <file>\n");
    exit(1);
  }
  
  fin=fopen(argv[1], "r");
  if(!fin){
    printf("\nProblema na abertura do arquivo %s\n", argv[1]);
    exit(1);   
  }
  do{
    t = lex(fin);
    if(t==ERRO_LEXICO){
      printf("\nNa linha %d encontrado um simbolo invalido: (codigo %d): [%s]", lines, t, lexema);
    }
    else
      printf("\nNa linha %d encontrado token: %s (codigo %d): [%s]", lines, terminalName[t], t, lexema);
  }while (t!=FIM);
  fclose(fin);
}
