/*
 parser.h
 Autor: Edna A. Hoshino
 Em: junho de 2013
 Descreve a gramatica e as transicoes do automato com pilha que, respectivamente, gera e aceita um subconjunto dos programas da linguagem C.
*/
#include "lex.h"
#define P(x) (x)
#define E(x) (x+nProductions)
#define CodVariable(x) (x-nTerminal)  /* um numero de 0 a nVariables-1 associado a cada variavel da gramatica (usado para indexar vetor variableName) */
#define isVariable(x) (x<nTerminal?0:1)
#define isProduction(x) (x<nProductions?TRUE:FALSE)

#define nVariables 13 /* numero de variaveis da gramatica */
#define nProductions 37 /* numero de producoes da gramatica */
#define maxRightSideLength 20 /* tamanho maximo do lado direito de cada producao */
#define MAXPILHA 500 /* tamanho maximo da pilha do Automato */

typedef struct{
  int length; /* tamanho do lado direito da producao */
  int rightSide[maxRightSideLength]; /* lado direito da producao (pode ter terminais e variaveis) */
} tProduction;

enum tVariable {S=nTerminal, Function, Type, Command, Block, Expression, S_, Expression_, Command_, Function_, Ele, Jota, Ponteiro, Jota_};
char *variableName[]={"S", "Function", "Type", "Command", "Block", "Expression", "S_", "Expression_", "Command_", "Function_", "Ele", "Jota", "Ponteiro", "Jota_"};

tProduction productions[] = { /* lado direito das producoes */
  /*0*/  {-1,{}}, /* usado para efetuar epsilon-transicao */
  /*1*/  {0, {}}, /* equivale a epsilon-transicao */
  /*2*/  {2, {Function, S_ }}, /* S -> Function S_  e  S_ -> Function S_ | epsilon */
  /*3*/  {2, {Type, Function_}}, /* Function -> Type Function_ */
  /*4*/  {2, {Command, Block}}, /* Block -> Command Block | epsilon */
  /*5*/  {4, {ABRE_PARENT, Expression, FECHA_PARENT, Expression_}}, /* Expression -> ( Expression ) Expression_ */
  /*6*/  {2, {NUM, Expression_}}, /* Expression -> NUM Expression_ */
  /*7*/  {3, {OP_ADIT, Expression, Expression_}}, /* Expression_ -> + Expression Expression_ */
  /*8*/  {1, {INT}},  /* Type -> int */
  /*9*/  {1, {FLOAT}}, /* Type -> float */
  /*10*/  {1, {VOID}}, /* Type -> void */
  /*11*/  {6, {IF, ABRE_PARENT, Expression, FECHA_PARENT, Command, Command_}}, /* Command -> if ( Expression ) Command Command_ */
  /*12*/  {2, {ELSE, Command}}, /* Command_ -> else Command | epsilon */
  /*13*/  {5, {WHILE, ABRE_PARENT, Expression, FECHA_PARENT, Command}}, /* Command -> while ( Expression ) Command */
  /*14*/  {3, {ABRE_CHAVES, Block, FECHA_CHAVES}}, /* Command -> { Block } */
  /*15*/  {4, {ID, OP_ATRIB, Expression, PONTO_VIRG}}, /* Command -> id = Expression ; */
  /*16*/  {2, {ID, Expression_}}, /* Expression -> id Expression_ */
  /*17*/  {3, {OP_ADIT, Expression, Expression_}}, /* Expression_ -> + Expression Expression_ | epsilon */
  /*18*/  {3, {OP_MULT, Expression, Expression_}}, /* Expression_ -> * Expression Expression_ | epsilon */
  /*19*/  {6, {ID, ABRE_PARENT, FECHA_PARENT, ABRE_CHAVES, Block, FECHA_CHAVES}},  /* Function_ -> id () { Block } */
  /*20*/  {6, {MAIN, ABRE_PARENT, FECHA_PARENT,ABRE_CHAVES, Block, FECHA_CHAVES}}, /* Function_ -> main () { Block } */
  /*21*/  {2, {NOT, Expression}}, /* Expression -> NOT Expression_ */
  /*22*/  {3, {OP_SUB, Expression, Expression_}}, /* Expression_ -> - Expression Expression_ | epsilon */
  /*23*/  {2, {E_COMERCIAL, Expression}}, /* Expression -> E_COMERCIAL Expression_ */
  /*24*/  {2, {BARRA, Expression}}, /* Expression -> BARRA Expression_ */
  /*25*/  {3, {OP_DIV, Expression, Expression_}}, /* Expression_ -> / Expression Expression_ | epsilon */
  /*26*/  {2, {AND, Expression}}, /* Expression_ -> BARRA Expression_ */
  /*27*/  {1, {DECREMENTO}}, /* Expression_ -> DECREMENTO */
  /*28*/  {3, {OP_REL, Expression, Expression_}}, /* Expression_ -> OP_REL Expression Expression_ | epsilon */
  /*29*/  {1, {INCREMENTO}}, /* Expression_ -> INCREMENTO */
  /*30*/  {2, {OR, Expression}}, /* Expression_ -> OR Expression_ */
  /*31*/  {2, {Type, Jota}}, /* Ele -> Type Jota*/
  /*32*/  {4, {Ponteiro, ID, Jota_, PONTO_VIRG}}, /* Jota -> Ponteiro ID Jota_ ; */
  /*33*/  {2, {OP_MULT, Ponteiro}}, /* Ponteiro -> * Ponteiro */
  /*34*/  {4, {VIRG, Ponteiro, ID, Jota_}}, /* Jota_ -> , Ponteiro ID Jota_ */
  /*35*/  {3, {Ele, Function, S_}}, /* S -> Ele Function S_ */
  /*36*/  {3, {Type, Jota, Block}} /* Block -> Type Jota Block */
};

int M[][nTerminal]={ /* transicoes do automato com pilha (pode ser uma producao P(n) ou um erro E(n)) */
//              ELSE,FLOAT,  FOR,   IF,  INT, MAIN, VOID,WHILE,    id,  num,  '=',  '+',  '*',  '<',  '(',  ')',  ';',  ',',  '{',  '}', '!',  '-',  '&',  '|',  '/',  'AND', '--', '++', 'OR', FIM
  /*S*/         P(2),P(35), P(2), P(2),P(35), P(2), P(2), P(2),  P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2), P(2),  P(2), P(2), P(2), P(2), P(2), 
/*Function*/    P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3),  P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3), P(3),  P(3), P(3), P(3), P(3), P(3),
/*Type*/        E(1), P(9), E(1), E(1), P(8), E(1),P(10), E(1),  E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1), E(1),  E(1), E(1), E(1), E(1), E(1), 
/*Command*/     E(2), E(2), E(1),P(11), E(2), E(2), E(2),P(13), P(15), E(2), E(2), E(2), E(2), E(2), E(2), E(2), E(2), E(2),P(14), E(2), E(2), E(2), E(2), E(2), E(2),  E(2), E(2), E(2), E(2), E(2),
/*Block*/       P(0),P(36), P(0), P(4),P(36), P(0), P(0), P(4),  P(4), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(4), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0),  
/*Expression*/  E(3), E(3), E(3), E(3), E(3), E(3), E(3), E(3), P(16), P(6), E(3), E(3), E(3), E(3), P(5), E(3), E(3), E(3), P(4), E(3), P(21),E(3), P(23),P(24),E(3),  E(3), E(3), E(3), E(3), E(3),
/*S_*/          P(1), P(2), P(1), P(1), P(2), P(1), P(2), P(1),  P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1),  P(1), P(1), P(1), P(1), P(1),  
/*Expression_*/ P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1),  P(1), P(1), P(1),P(17),P(18),P(28), P(1), P(1), P(1), P(1), P(1), P(1),P(28),P(22),P(16),P(16),P(25), P(26),P(27),P(29),P(30),P(1),
/*Command_*/   P(12), P(1), P(1), P(1), P(1), P(1), P(1), P(1),  P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1), P(1),  P(1), P(1), P(1), P(1), P(1),
/*Function_*/   E(5), E(5), E(5), E(5), E(5),P(20), E(5), E(5), P(19), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5), E(5),  E(5), E(5), E(5), E(5), E(5),
/*Ele*/         P(0),P(31), P(0), P(0),P(31), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0),
/*Jota*/       P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32), P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32),P(32), P(32),P(32),P(32),P(32),P(32),
/*Ponteiro*/    P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0),P(33), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0),
/*Jota_*/       P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0), P(0),P(34), P(0), P(0), P(0), P(0), P(0), P(0), P(0),  P(0), P(0), P(0), P(0), P(0)
};

char *erros[]={ /* mensagens de erros associada a cada E(n) */
 "simbolo inesperado", "tipo esperado", "comando esperado", "identificador ou numero esperado", "operador esperado", "identificador esperado"
};
int initialVariable=S; /* variavel inicial da base da pilha */
