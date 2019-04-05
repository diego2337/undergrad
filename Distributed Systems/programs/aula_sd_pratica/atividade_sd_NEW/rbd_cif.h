/* rbd_cif.h - inicializar, insere, remove, busca */ 
#include <rpc/rpc.h> 
#include "rbd.h"

CLIENT *handle;  /* handle para procedimento remoto */ 

int inicializar();

int insere(agenda *);

int remover(agenda *);

int busca(agenda *);

void cli_error();


