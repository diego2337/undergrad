/* rbd_cif.c - inicializar, insere, remove, busca */ 

#include "rbd_cif.h"

int inicializar() 
{ 
     return *inicializar_1(NULL,handle); 
} 

int insere(struct agenda *item) 
{ 
    struct agenda *arg; 
    int * result;
     
    /*arg = (agenda*)malloc(sizeof(agenda));
    strcpy(arg->nome, item->nome);
    arg->fone = item->fone;
    strcpy(arg->endereco, item->endereco);*/
    arg = item;
    result =  insere_1(arg, handle); 
     
    if (result == (int *)NULL) 
      cli_error();
     
    return *result; 
} 

int remover(agenda *item) 
{ 
  agenda *arg; 
  int * result;

  arg = item; 

  result = remove_1(arg, handle); 
  if (result == (int *)NULL) 
      cli_error();

  return *result;
} 

int busca(agenda *item) 
{ 
  agenda *arg; 
  int * result;
  arg = item; 

  result = busca_1(arg, handle); 
  if (result == (int *)NULL) 
      cli_error();

  return *result;
}


void cli_error()
{
   /* An error occurred while calling the server. */
   /* Print error message and die. */
   printf("RPC falhou\n");
   //clnt_perror(handle, server);
   clnt_destroy( handle );
   exit(1);
}
