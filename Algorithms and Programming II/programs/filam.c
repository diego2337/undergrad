#include<stdio.h>
#include<stdlib.h>

typedef int tipo ;

typedef struct _tfila {
     tipo val;
     struct _tfila *prox;
} tfila;

typedef struct _fila {
     tfila *comeco ;
     tfila *fim ;
}fila;

void init (fila *f){
     f->comeco = NULL;
     f-> fim = NULL;
}

int enfileira (fila *f,tipo val){
tfila *aux;
int ret=1;

	aux =(tfila*)malloc(sizeof(tfila));	
	if(aux==NULL){
		ret = 0;
	}
	
	aux->val = val;
	
	if(f->comeco==NULL && f->fim==NULL){
		(*f).comeco = aux;
		(*f).fim = aux; 
	}else{
		aux->prox = NULL;
		f->fim->prox = aux;
		f->fim = aux;
	}
return ret;
}


int desenfileira (fila *f) {
tfila *aux;
int ret=1;	
		
	if(f->fim == NULL && f->comeco == NULL){
		ret = 0;
	}	
	aux = f->comeco;
	if(f->comeco!=NULL)
		f->comeco = f->comeco->prox;
		if(f->comeco == NULL)
			f->fim = NULL;
	free(aux);
	
	return ret;
}


int empty (fila f) {
int ret=0;
    if(f.fim == NULL && f.comeco == NULL) 
    	ret = 1;
    return ret;	
}

int imprime_fila (fila f) {
tfila *aux;
int ret=1;

	if(f.comeco==NULL && f.fim==NULL){
		ret = 0;
	}
	
	aux = f.comeco;
 	if(aux!=NULL){
 		printf("%d ", aux->val);
			aux = aux->prox;
	}else{
		ret = 0;
	}		

	while(aux != NULL){
		printf("%d ", aux->val);
		aux = aux->prox;
	}
	return ret;

}


void limpa_fila (fila *f) {
    while (desenfileira(f)) ;
}

int main(void) {
    char comando;
    fila f;
    tipo val ;
    init(&f);
    while (scanf (" %c", &comando) ==1) {
         if (comando == 'i') {
                scanf("%d", &val) ;
                enfileira(&f ,val) ;
                imprime_fila(f);
                printf("\n");
         }else if (comando == 'r') {
                if (empty(f)) {
                     printf ("empty\n");
                } else {
                     desenfileira(&f);
                   imprime_fila(f);
                    	printf("\n");
                   
                    
                }
               
         }
    }
    limpa_fila(&f) ;
    return 0;
}


