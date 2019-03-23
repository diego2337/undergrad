/*
Encontra um conjunto independente de cardinalidade maxima

Modelo de PLI para VCP:

min x1 + x2 + ... + xn
s.a.:
   xi + xj  >= 1, para todo (i,j) em E

variaveis: xi binarias, um para cada vertice
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>
#include <time.h>

#define EPSILON 0.000001
#define DBL_MAX 999999

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...) 
#endif
void foo_bar(glp_tree *tree, void *info);

typedef struct{
  int i;
  int j;
} edgeT;

edgeT *E;
int n, m;
int **A;
double bestPrimalBound=-DBL_MAX, bestDualBound=+DBL_MAX;

int carga_instancia(char *filename)
{
  FILE *fin;
  int i,j, edges;

  fin = fopen(filename, "r");
  if(!fin)
  {
    return 0;
  }
  fscanf(fin, "%d %d\n", &n, &m);
  E = (edgeT*)malloc(sizeof(edgeT)*m);
  A = (int**)malloc(sizeof(int*)*n);
  for(i = 0; i < n; i++)
  {
    A[i] = (int*)malloc(sizeof(int)*n);
    for(j = 0; j < n; j++)
    {
      A[i][j] = 0;
    }
  }
  edges = 0;
  while(!feof(fin))
  {
    fscanf(fin, "%d %d\n", &i, &j);
    --i;
    --j;
    A[i][j] = A[j][i] = edges;
    E[edges].i = i;
    E[edges].j = j;
    edges++;
  }
  if(edges != m)
  {
    return 0;
  }
  return 1;
}

int carga_lp(glp_prob **lp)
{
  int *ia, *ja, rows, cols, i, nz;
  double *ar;
  char name[80];// nome da restricao

  rows = m;
  cols = n;

  // Aloca matriz de coeficientes
  ia = (int*)malloc(sizeof(int)*(2*m+1));
  ja = (int*)malloc(sizeof(int)*(2*m+1));
  ar = (double*)malloc(sizeof(double)*(2*m+1));
      
  // Cria problema de PL
  *lp = glp_create_prob();
  glp_set_prob_name(*lp, "VCP1");
  glp_set_obj_dir(*lp, GLP_MIN);

  // Configura restricoes
  glp_add_rows(*lp, rows);
  for(i = 0; i < m; i++)
  {
    sprintf(name, "edge%d", i+1);
    glp_set_row_name(*lp, i+1, name);
    glp_set_row_bnds(*lp, i+1, GLP_LO, 1, 0.0);
  }
  
  // Configura variaveis
  glp_add_cols(*lp, cols);
  for(i = 0; i < cols; i++)
  {
    name[0] = '\0';
    sprintf(name,"x%d", i+1); /* as n variaveis referem-se `as variaveis x1, x2, ..., xn*/
    glp_set_col_name(*lp, i+1, name); 
    glp_set_col_bnds(*lp, i+1, GLP_DB, 0.0, 1.0);
    glp_set_obj_coef(*lp, i+1, 1);
    glp_set_col_kind(*lp, i+1, GLP_BV); // especifica que a variaval xi eh binaria
  }

  // Configura matriz de coeficientes ...
  nz = 1;
  for(i = 0; i < m; i++)
  {
    ia[nz] = i+1;
    ja[nz] = E[i].i+1;
    ar[nz] = 1;
    nz++;
    ia[nz] = i+1;
    ja[nz] = E[i].j+1;
    ar[nz] = 1;
    nz++;
  }

  // Carrega PL
  glp_load_matrix(*lp, nz-1, ia, ja, ar);

  // libera memoria
  free(ia); 
  free(ja); 
  free(ar);
  return 1;
}

void foo_bar(glp_tree *tree, void *info)
{
  double gap, z_lp;
  int ativos, nodes, currNode, pai, level, nodeBestBound;
  glp_prob *prob;

  switch (glp_ios_reason(tree))
  { 
    case GLP_IBRANCH:
      break;
    case GLP_ISELECT:
      break;
    case GLP_IHEUR:
      // recupera nodo atual e sua solucao
      prob = glp_ios_get_prob(tree);
      z_lp = glp_get_obj_val(prob);
      // obtem dados da arvore de enumeracao
      gap = glp_ios_mip_gap(tree);
      glp_ios_tree_size(tree, &ativos, NULL, &nodes);
      nodeBestBound = glp_ios_best_node(tree);
      bestDualBound = glp_ios_node_bound(tree, nodeBestBound);      
      currNode = glp_ios_curr_node(tree);
      pai = glp_ios_up_node(tree, currNode);
      level = glp_ios_node_level(tree, currNode);
      // obtem LB do nodo atual ---> obj_val eh o LP dado pela relaxacao linear e ios_node_bound pode ser outro limitante!
      prob = glp_ios_get_prob(tree);
      z_lp = glp_get_obj_val(prob);
  
      printf("\n%d\t(%.2lf)\t%d\t%d\t%d\t%d\t%.2lf", currNode, z_lp, pai, level,  ativos, nodes, bestDualBound);

      // mostra melhor primal
      if(bestPrimalBound > -DBL_MAX)
      {
	       printf("\t%.2lf", bestPrimalBound);
      }
      else
      {
	       printf("\t*");
      }
      // mostra gap atual
      if(gap > DBL_MAX - EPSILON)
      {
	       printf("\t*");
      }
      else
      {
	       printf("\t%2.2lf", gap*100);
      }
      break;
    case GLP_IBINGO:
      // atualiza melhor primal
      prob = glp_ios_get_prob(tree);
      z_lp = glp_mip_obj_val(prob);
      if(z_lp > bestPrimalBound)
	       bestPrimalBound = z_lp;
      printf("!");
      break;
    default:
      /* ignore call for other reasons */
      break;
    }
    return;
}


int main(int argc, char **argv)
{     
  glp_prob *lp;
  double z, valor, z_lp;
  clock_t antes, agora;
  glp_iocp param;
  glp_smcp param_lp;
  int status, i;
  FILE *arq;
  char *filenome;

  if(argc<2)
  {
	   printf("\nSintaxe: is <input-graph>");
	   exit(1);
  }
  // ler a entrada
  if(!carga_instancia(argv[1]))
  {
	   printf("\nProblema na carga do arquivo: %s", argv[1]);
	   exit(1);
  }

  // carga do lp
  carga_lp(&lp);

  // desabilita saidas do GLPK no terminal
  glp_term_out(GLP_OFF);

  // configura simplex
  glp_init_smcp(&param_lp);
  param_lp.msg_lev = GLP_MSG_OFF;

  // configura branch-bound
  glp_init_iocp(&param);
  param.msg_lev = GLP_MSG_OFF;
  param.pp_tech = GLP_PP_NONE;
  param.cb_func = foo_bar;
  param.fp_heur = GLP_OFF;
  param.tm_lim = 1200000;
  //      param.bt_tech = GLP_BT_DFS;

  printf("\nNode\t(LP)\tpai\tLevel\tAtivos\tNodes\tUB\tLB\tGap");
  antes = clock();
  // Executa Solver de PL
  glp_simplex(lp, NULL); // resolve o problema relaxado
  glp_intopt(lp, &param); // resolve o problema inteiro
  agora = clock();

  status = glp_mip_status(lp);
  PRINTF("\nstatus=%d\n", status);
      
  // Recupera solucao
  z = glp_mip_obj_val(lp);
  z_lp = glp_get_obj_val(lp);
  filenome = argv[1];
  strcat(filenome, ".aresta.sol");
  arq = fopen(filenome, "w");
  fprintf(arq, "%d\n", (int)z);
  for(i = 0; i < n; i++)
  {
     valor=glp_mip_col_val(lp, i+1); // recupera o valor da variavel i+1
     if(valor > EPSILON)
     {
       PRINTF("x%d = %lf\n", i+1, valor);
       fprintf(arq, "%d ", i+1);
     }
  }
  fclose(arq);

  #ifdef DEBUG	
      // Grava solucao e PL
      PRINTF("\n---LP gravado em VCP1.lp e solucao em VCP1.sol");
      glp_write_lp(lp, NULL,"VCP1.lp");
      glp_print_mip(lp, "VCP1.sol");
  #endif

  printf("\n\n%s", argv[1]); fflush(stdout);
  printf("\t%lf\t%lf\t%lf\n", z,z_lp,((double)agora-antes)/CLOCKS_PER_SEC);

  // Destroi problema
  glp_delete_prob(lp);
  return 0;
}

/* eof */