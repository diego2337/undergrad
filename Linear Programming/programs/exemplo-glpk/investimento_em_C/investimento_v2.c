/* investimento_v2.c 

Exemplo de uso da biblioteca GLPK para resolver um problema de programacao linear: 
  em que fundos investir para obter o maior rendimento anual ?

Neste exemplo, o montante, o total de fundos, o rendimento, classificacao e maturacao de cada um deles eh lido de um arquivo de entrada.

O exemplo eh usado como exemplo mais completo para conhecer as rotinas da biblioteca GLPK.
*/

#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>
#include <time.h>

#define EPSILON 0.000001

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...) 
#endif

typedef struct {
  double rendimento;
  int maturacao;
  char classificacao;
} Tinvest;

int carga_instancia(FILE* fin, int *n, double *m, Tinvest **fundos)
{
  int i;
  
  fscanf(fin,"%d %lf\n", n, m);
  PRINTF("%d %lf\n", *n,*m);

  *fundos=(Tinvest*) malloc(sizeof(Tinvest)*(*n));

  i=0;
  while(!feof(fin)){
    fscanf(fin, "%lf %d %c\n", &((*fundos)[i].rendimento),&((*fundos)[i].maturacao), &((*fundos)[i].classificacao));
    PRINTF("%lf %d %c\n",  (*fundos)[i].rendimento, (*fundos)[i].maturacao, (*fundos)[i].classificacao);
    i++;
  }
  if(i!=*n){
    return 0;
  }
  return 1;
}


int carga_lp(glp_prob **lp, int n, double montante, Tinvest* fundos)
{
  int *ia, *ja, rows, cols, i, nz, nLongoPrazo, nClassifBaixa;
  double *ar;
  char name[80];

  rows=n+3;// uma restricao para cada fundo + 1 restr para fundos de longo prazo + 1 para fundos ruins + 1 para montante
  cols=n; 

  // contabiliza total de fundos de longo prazo, i.e., maturacao > 10 anos
  PRINTF("\nFundos de longo prazo: ");
  nLongoPrazo=0;
  for(i=0;i<n;i++){
    if(fundos[i].maturacao>=10){
      PRINTF("%d ", i+1);
      nLongoPrazo++;
    }
  }
  // contabiliza total de fundos de classficacao baixa, i.e., inferior a "m"=Muito Bom (b=Bom, a=Aceitavel)
  PRINTF("\nFundos de classificacao baixa: ");
  nClassifBaixa=0;
  for(i=0;i<n;i++){
    if(fundos[i].classificacao=='b' || fundos[i].classificacao=='a'){
      PRINTF("%d ", i+1);
      nClassifBaixa++;
    }
  }

  // Aloca matriz de coeficientes
  ia=(int*)malloc(sizeof(int)*(2*n+nClassifBaixa+nLongoPrazo+1));
  ja=(int*)malloc(sizeof(int)*(2*n+nClassifBaixa+nLongoPrazo+1));
  ar=(double*)malloc(sizeof(double)*(2*n+nClassifBaixa+nLongoPrazo+1));
      
  // Cria problema de PL
  *lp = glp_create_prob();
  glp_set_prob_name(*lp, "investimento");
  glp_set_obj_dir(*lp, GLP_MAX);

  // Configura restricoes
  glp_add_rows(*lp, rows);
  for(i=0;i<n;i++){
    name[0]='\0';
    sprintf(name,"restricao%d", i+1);
    glp_set_row_name(*lp, i+1, name);
    glp_set_row_bnds(*lp, i+1, GLP_UP, 0.0, 0.25*montante);
  }
  glp_set_row_name(*lp, n+1, "LongoPrazo");
  glp_set_row_bnds(*lp, n+1, GLP_LO, 0.5*montante, 0.0);
  glp_set_row_name(*lp, n+2, "ClassifBaixa");
  glp_set_row_bnds(*lp, n+2, GLP_UP, 0.0, 0.35*montante);
  glp_set_row_name(*lp, n+3, "Montante");
  glp_set_row_bnds(*lp, n+3, GLP_FX, montante, montante);

  // Configura variaveis
  glp_add_cols(*lp, cols);
  for(i=0;i<cols;i++){
    name[0]='\0';
    sprintf(name,"x%d", i+1);
    glp_set_col_name(*lp, i+1, name);
    glp_set_col_bnds(*lp, i+1, GLP_LO, 0.0, 0.0); // xi>=0
    glp_set_obj_coef(*lp, i+1, fundos[i].rendimento);
  }

  // Configura matriz de coeficientes
  nz=1;
  for(i=1;i<=n;i++){
    ia[nz] = i; ja[nz] = i; ar[nz++] =  1.0;  /* a[i,i] =  1 */
    ia[nz] = n+3; ja[nz] = i; ar[nz++] =  1.0; /* a[n+3,i] =  1 */
  }
  for(i=0;i<n;i++){
    if(fundos[i].maturacao>=10){
      ia[nz] = n+1; ja[nz] = i+1; ar[nz++] =  1.0; /* a[n+1,i+1] =  1 */
    }
    if(fundos[i].classificacao=='b'|| fundos[i].classificacao=='a'){
      ia[nz] = n+2; ja[nz] = i+1; ar[nz++] =  1.0; /* a[n+2,i+1] =  1 */
    }
  }

  // Carrega PL
  glp_load_matrix(*lp, nz-1, ia, ja, ar);

  // libera memoria
  free(ia); free(ja); free(ar);
  return 1;
}
int main(int argc, char **argv)
{     glp_prob *lp;
      double z;
      FILE *fin;
      int n, i;
      Tinvest* fundos;
      double valor;
      clock_t antes, agora;
      double montante;

      glp_smcp param_lp;

      if(argc<2){
	PRINTF("Sintaxe: investimento <arquivo>\n");
	exit(1);
      }

      fin=fopen(argv[1], "r");
      if (!fin){
	printf("problema na abertura do arquivo: %s", argv[1]);
	exit(1);
      }
      if(!carga_instancia(fin, &n, &montante, &fundos)){
	printf("\nErro na carga do problema");
	exit(1);
      }

      // desabilita saidas do GLPK no terminal
      glp_term_out(GLP_OFF);

      // carga do lp
      carga_lp(&lp, n, montante, fundos);

      // configura simplex
      glp_init_smcp(&param_lp);
      param_lp.msg_lev = GLP_MSG_OFF;

      antes=clock();
      // Executa Solver de PL
      glp_simplex(lp, &param_lp);
      agora=clock();

      // Recupera solucao
      printf("\n\n**** solucao:\n");
      z = glp_get_obj_val(lp);
      for(i=0;i<n;i++){
	valor=glp_get_col_prim(lp, i+1);
	printf("y%d = %g\n", i+1, valor);
      }

#ifdef DEBUG	
      // Grava solucao e PL
      PRINTF("\n---LP gravado em investimento2.lp e solucao em investimento2.sol");
      glp_write_lp(lp, NULL,"investimento2.lp");
      glp_print_sol(lp, "investimento2.sol");
#endif

      PRINTF("\n\n\n**** z =%.2lf tempo=%.2lf\n", z, ((double)agora-antes)/CLOCKS_PER_SEC);
      printf("%.2lf\t%.2lf\n", z,((double)agora-antes)/CLOCKS_PER_SEC);


      // libera memoria alocada
      free (fundos);
    
      // Destroi problema
      glp_delete_prob(lp);
      return 0;
}

/* eof */
