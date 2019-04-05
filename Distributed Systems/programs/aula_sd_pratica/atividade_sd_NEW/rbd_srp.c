/* rbd_srp.c - inicializar, insere, remove, busca*/ 
#include <rpc/rpc.h>
#include <string.h>
#include "rbd.h"


#define BDSIZE  1000

/* Procedimentos remotos do servidor e dados globais */ 


agenda bd[BDSIZE]; /* armazena os contatos da agenda */ 
int  ncontatos = 0;   /* número de contatos na agenda */ 

int inicializar() 
{ 
  ncontatos = 0; 
  return 1; 
} 

int insere(contato) 
agenda contato; 
{ 
  /* strcpy(bd[ncontatos], contato); */
  strcpy(bd[ncontatos].nome, contato.nome);
  bd[ncontatos].fone = contato.fone;
  strcpy(bd[ncontatos].endereco, contato.endereco);
  ncontatos++; 
  return ncontatos; 
}

int remover(contato) 
agenda contato; 
{ 
  int i; 
  for(i = 0; i < ncontatos; i++) 
  {
    if(strcmp(contato.nome, bd[i].nome) == 0) 
    { 
      /* strcpy(bd[i], bd[ncontatos]); */
      bd[i] = bd[ncontatos];
      ncontatos--; 
      return 1; 
    } 
  }
  return 0; 
} 

int busca(contato) 
agenda contato; 
{ 
  int i; 
  for(i = 0; i < ncontatos; i++) 
  {
    if(strcmp(contato.nome, bd[i].nome) == 0) 
    {
      strcpy(contato.nome, bd[i].nome);
      contato.fone = bd[i].fone;
      strcpy(contato.endereco, bd[i].endereco);
      return 1; 
    }
    else
      return 0; 
  }
} 

