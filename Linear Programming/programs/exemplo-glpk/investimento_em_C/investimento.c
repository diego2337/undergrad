/* investimento.c 
Exemplo de uso da biblioteca GLPK para resolver um problema de programacao linear: 
  em que fundos investir um montante m passado como argumento de entrada do programa ?

Neste exemplo, ha um total de 6 fundos com diferentes rendimentos, classificacao e maturacao.
O LP associado eh:

Variaveis: xi = total investido no fundo i

Funcao objetivo:
max z = .0865x1 + .095x2 + .10x3 + .0875x4 + .0925x5 + .09x6
Restricao (i): xi ≤ 187.500, i = 1, . . . , 6
Restricao (ii): x1 + x2 + x4 + x6 ≥ 375.000
Restricao (iii): x3 + x5 ≤ 262.500
Total investido: x1 + x2 + x3 + x4 + x5 + x6 = 750.000
Nao negatividade: x1 , x2 , x3 , x4 , x5 , x6 ≥ 0

O exemplo eh usado como exemplo inicial para conhecer as rotinas da biblioteca GLPK.
*/

#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>
#include <time.h>

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...) 
#endif

int carga_lp(glp_prob **lp, int montante)
{
  int *ia, *ja, rows, cols, i,nz;
  double *ar;
  char name[80];

  rows=9;
  cols=6; 

  // Aloca matriz de coeficientes
  ia=(int*)malloc(sizeof(int)*20);
  ja=(int*)malloc(sizeof(int)*20);
  ar=(double*)malloc(sizeof(double)*20);
      
  // Cria problema de PL
  *lp = glp_create_prob();
  glp_set_prob_name(*lp, "investimento");
  glp_set_obj_dir(*lp, GLP_MAX);

  // Configura restricoes
  glp_add_rows(*lp, rows);
  for(i=0;i<rows;i++){
    name[0]='\0';
    sprintf(name,"restricao%d", i+1);
    glp_set_row_name(*lp, i+1, name); /* configura o nome da restricao i+1 */
    glp_set_row_bnds(*lp, i+1, GLP_UP, 0.0, 0.25*montante); /* configura o rhs da restricao i+1 e se o rhs eh um limitante superior <= GLP_UP, inferior >= GLP_LO ou de igualdade = GLP_FX  */
  }
  glp_set_row_bnds(*lp, 7, GLP_LO, 0.5*montante, 0.0);
  glp_set_row_bnds(*lp, 8, GLP_UP, 0.0, 0.35*montante);
  glp_set_row_bnds(*lp, 9, GLP_FX, montante, montante);

  // Configura variaveis
  glp_add_cols(*lp, cols);
  for(i=0;i<cols;i++){
    name[0]='\0';
    sprintf(name,"x%d", i+1);
    glp_set_col_name(*lp, i+1, name); /* configura o nome da variavel i+1 */
    glp_set_col_bnds(*lp, i+1, GLP_LO, 0.0, 0.0); /* configura os limitantes inferior e superior (se existirem) para a variavel i+1 (GLP_LO 0.0 equivale: variavel >= 0.0 */
  }
  
  /* define o coeficiente de cada variavel na funcao objetivo */
  glp_set_obj_coef(*lp, 1, 0.0865); 
  glp_set_obj_coef(*lp, 2, 0.095);
  glp_set_obj_coef(*lp, 3, 0.10);
  glp_set_obj_coef(*lp, 4, 0.0875);
  glp_set_obj_coef(*lp, 5, 0.0925);
  glp_set_obj_coef(*lp, 6, 0.09);

  // Configura matriz de coeficientes
  nz=1;
  for(i=1;i<=6;i++){
    ia[nz] = i; ja[nz] = i; ar[nz++] =  1.0; /* a[i,i] =  1 */
    ia[nz] = 9; ja[nz] = i; ar[nz++] =  1.0; /* a[9,i] =  1 */
  }
  ia[nz] = 7; ja[nz] = 1; ar[nz++] =  1.0; /* a[7,1] =  1 */
  ia[nz] = 7; ja[nz] = 2; ar[nz++] =  1.0; /* a[7,2] =  1 */
  ia[nz] = 7; ja[nz] = 4; ar[nz++] =  1.0; /* a[7,4] =  1 */
  ia[nz] = 7; ja[nz] = 6; ar[nz++] =  1.0; /* a[7,6] =  1 */
  ia[nz] = 8; ja[nz] = 2; ar[nz++] =  1.0; /* a[8,2] =  1 */
  ia[nz] = 8; ja[nz] = 3; ar[nz++] =  1.0; /* a[8,3] =  1 */
  ia[nz] = 8; ja[nz] = 5; ar[nz++] =  1.0; /* a[8,5] =  1 */

  // Carrega PL
  glp_load_matrix(*lp, nz-1, ia, ja, ar);

  // libera memoria
  free(ia); free(ja); free(ar);
  return 1;
}
int main(int argc, char **argv)
{     glp_prob *lp;
      double z;
      int n, i;
      double valor;
      clock_t antes, agora;
      double montante;

      glp_smcp param_lp;

      if(argc<2){
	PRINTF("Sintaxe: investimento <montante>\n");
	exit(1);
      }

      montante=atof(argv[1]);
      n=6;
      
      // desabilita saidas do GLPK no terminal
      glp_term_out(GLP_OFF);

      // carga do lp
      carga_lp(&lp, montante);

      // configura simplex
      glp_init_smcp(&param_lp);
      param_lp.msg_lev = GLP_MSG_OFF; /* desabilita output */

      antes=clock();
      // Executa Solver de PL
      glp_simplex(lp, &param_lp);
      agora=clock();

      // Recupera solucao
      printf("\n\n**** solucao:\n");
      z = glp_get_obj_val(lp); /* recupera o valor da solucao */
      for(i=0;i<n;i++){
	valor=glp_get_col_prim(lp, i+1); /* recupera o valor da variavel i+1 */
	printf("y%d = %g\n", i+1, valor);
      }

#ifdef DEBUG	
      // Grava solucao e PL
      PRINTF("\n---LP gravado em investimento.lp e solucao em investimento.sol");
      glp_write_lp(lp, NULL,"investimento.lp");
      glp_write_sol(lp, "investimento.sol");
#endif

      PRINTF("\n\n\n**** z =%g tempo=%g\n", z, ((double)agora-antes)/CLOCKS_PER_SEC);
      printf("%g\t%g\n", z,((double)agora-antes)/CLOCKS_PER_SEC);

    
      // Destroi problema
      glp_delete_prob(lp);
      return 0;
}

/* eof */
