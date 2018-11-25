#ifndef __LEX
#define __LEX

#include <stdio.h>

#define nSymbols 19
enum {LETRA=nSymbols, DIGITO, INVALIDO, FIM_ARQUIVO};
enum boolean {FALSE=0, TRUE};
enum tKeyword {ELSE=0, FLOAT, FOR, IF, INT, MAIN, VOID, WHILE, nKeywords};
enum tTerminal {ID=nKeywords, NUM, OP_ATRIB, OP_ADIT, OP_MULT, OP_REL, ABRE_PARENT, FECHA_PARENT, 
	PONTO_VIRG, VIRG, ABRE_CHAVES, FECHA_CHAVES, NOT, OP_SUB, E_COMERCIAL, BARRA, OP_DIV, AND, DECREMENTO, INCREMENTO, OR, FIM, nTerminal
};
enum tErros{ERRO_LEXICO=nTerminal, ERRO_SINTATICO};

extern int lines;
extern char lexema[81];
extern char *terminalName[];

#endif
