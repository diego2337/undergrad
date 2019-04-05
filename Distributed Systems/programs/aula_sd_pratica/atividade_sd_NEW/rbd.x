/* rbd.x  
   especificação rpc para um programa de banco de dados  
   que oferece os procedimentos INSERE, REMOVE e BUSCA 
*/ 
struct agenda {            
          char nome[65];      /* constrói rotinas XDR para converter estruturas */ 
          unsigned int fone;  
	  char endereco[513];
}; 
program RBDPROG{           /* nome do programa remoto */ 
    version RDBVERS{       /* declaração da versão */ 
          int INICIALIZAR(void) = 1;   /* primeiro procedimento deste programa */ 
          int INSERE(agenda) = 2;      /* segundo procedimento deste programa */ 
          int REMOVE(agenda) = 3;      /* terceiro procedimento deste programa */ 
          int BUSCA(agenda) = 4;       /* quarto procedimento deste programa */ 
    } = 1;                /* definição da versão do programa */ 
} = 0x30090949;     /* número do programa remoto (deve ser único) */
