/* coloring-cg.c
codigo exemplo de aplicacao do metodo de geracao de colunas
 usando o solver do glpk para resolver o problema mestre restrito e o pricing
By: Edna A. Hoshino

Encontra a relaxacao linear do problema da k-coloracao de vertices para um grafo G de entrada.
A coloracao atribui k cores para cada vertice de G de modo que vertices adjacentes (vizinhos, ou seja, que tem aresta conectando-os) tenham cores diferentes.

Formato do arquivo de entrada:
tipo 1:
n m (n=|V| e m=|E| do grafo)
i j (uma linha para cada aresta (i,j) do grafo)
tipo 2:
n m (n=|V| e m=|E| do grafo)
c1 c2 c3... ci (peso associado ao vertice i)
i j (uma linha para cada aresta (i,j) do grafo)

Modelo de PLI para coloracao:

min lambda1 + lambda2 + lambda3 + ... + lambdap
s.a.:
   \sum_{p \in P} aip lambda_p <=1, para cada vertices i em G
   \sum_{p \in P} lambda_p <= K

onde aip = 1, se o vertice i estah no conjunto independente p
lambdap = 1, se o conjunto independente p eh selecionado na coloracao
K e o numero de cores que o grafo pode ser colorido

Obs.:
1) Ha uma variavel p para cada conjunto independente possivel (que potencialmente eh exponencial em n=|V|).
2) A ideia eh comecar com um subconjunto P contendo apenas alguns conjuntos independentes (de fato, um conjunto indenpendente de tamanho unitario eh criado para conter cada vertice).
3) O problema de pricing eh executado para encontrar um conjunto independente de custo reduzido negativo para entrar em P.
4) Se nao houver nenhum conj. indep. com esta propriedade, o programa para, pois a solucao atual eh a solucao otima da relaxacao linear.

*/

#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _GNU_SOURCE
#define EPSILON 0.00000001

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...) 
#endif

int n, m, k, *c;
int **A;
typedef struct{
  int i;
  int j;
}edgeT;
edgeT *E;

double sum_fp(double xstar[])
{
  int i;
  double sum = 0.000000;
  printf("\n");
  for(i = 1; i <= n; i++)
  {
    if(xstar[i] == 1.000000)
    {
      sum = sum + c[i-1];
    }
  }
  return sum;
}

int carga_instancia(FILE *fin, int type)
{
  int i,j, edges;
  fscanf(fin, "%d %d\n", &n, &m);
  E=(edgeT*)malloc(sizeof(edgeT)*m);
  c = (int*)malloc(sizeof(int)*(n+1));
  A=(int**)malloc(sizeof(int*)*n);
  if(type == 2)
  {
    for(i=0;i<n;i++)
    {
      A[i]=(int*)malloc(sizeof(int)*n);
      for(j=0;j<n;j++)
      {
        A[i][j] = -1;
      }
      fscanf(fin, "%d ", &c[i]);
    }
    c[n] = 1;
    fscanf(fin, "\n");
  }
  else if(type == 1)
  {
    for(i=0;i<n;i++)
    {
      A[i]=(int*)malloc(sizeof(int)*n);
      for(j=0;j<n;j++)
      {
        A[i][j] = -1;
      }
      c[i] = 1;
    }
    c[n] = 1;
  }
  edges=0;
  while(!feof(fin))
  {
    fscanf(fin, "%d %d\n", &i, &j);
    --i;--j;
    A[i][j]=A[j][i]=edges;
    E[edges].i=i;
    E[edges].j=j;
    edges++;
  }

#ifdef DEBUG
  for(i=0;i<m;i++)
  {
    printf("\nEdge%d: (%d,%d)", i+1, E[i].i+1, E[i].j+1);
  }
#endif

  if(edges!=m)
  {
    return 0;
  }
  return 1;
}

int carga_pmr(glp_prob **lp)
{
  int *ia, *ja, i, nz, k2;
  double *ar;
  int rows, cols;
  char name[100];

  rows=n+1; // restricao de cobertura, um para cada vertice mais a ultima linha correspondente a segunda restriçao
  cols=n; // inicialmente, n c.i.'s unitarios, cada um contendo 1 vertice de V
  
  // Aloca matriz de coeficientes
  ia=(int*)malloc(sizeof(int)*2*n+1);
  ja=(int*)malloc(sizeof(int)*2*n+1);
  ar=(double*)malloc(sizeof(double)*2*n+1);
  
  
  // Cria problema de PL
  *lp = glp_create_prob();
  glp_set_prob_name(*lp, "RCP");
  glp_set_obj_dir(*lp, GLP_MAX);
  
  // Configura restricoes
  glp_add_rows(*lp, rows+1);
  for(i=0;i<rows-1;i++)
  {
    name[0]='\0';
    sprintf(name,"cover%d", i+1);
    glp_set_row_name(*lp, i+1, name);
    glp_set_row_bnds(*lp, i+1, GLP_UP, 0, 1);
  }
  name[0]='\0';
  sprintf(name,"MIS");
  glp_set_row_name(*lp, i+1, name);
  glp_set_row_bnds(*lp, i+1, GLP_UP, 0, k);
  // Configura variaveis
  glp_add_cols(*lp, cols);
  for(i=0;i<cols;i++)
  {
    name[0]='\0';
    sprintf(name,"lambda%d", i+1);
    glp_set_col_name(*lp, i+1, name);
    glp_set_col_bnds(*lp, i+1, GLP_LO, 0.0, 0.0);
    glp_set_obj_coef(*lp, i+1, c[i]);
  }

  // Configura matriz de coeficientes
  for(nz = 1, k2 = 0; k2 < n; k2++)
  { // para cada vertice
    ia[nz] = k2+1; 
    ja[nz] = k2+1; 
    ar[nz] = 1; /* a[nz,i] =  1 */
    nz++;
  }
  for(nz = nz, k2 = 0; k2 < 2*n + 1 && nz < 2*n + 1; k2++)
  {
    ia[nz] = n+1;
    ja[nz] = k2+1;
    ar[nz] = 1;
    nz++;
  }

  // Carrega PL
  PRINTF("\nCarregando mestre...");
  glp_load_matrix(*lp, nz-1, ia, ja, ar);

#ifdef DEBUG
  // Grava PL do PMR inicial
  PRINTF("\n---- LP do PMR inicial gravado em coloracao-pmr.lp");
  glp_write_lp(*lp, NULL,"coloracao-pmr.lp");
  getchar();
#endif
  
  // desaloca matrizes
  free(ia); free(ja); free(ar);
  return 1;
}

int carga_pricing(glp_prob **lp)
{
  int *ia, *ja, rows, cols, i, nz;
  double *ar;
  char name[80];// nome da restricao

  rows=m; // uma restricao para cada aresta
  cols=n; // uma variavel para cada vertice

  // Aloca matriz de coeficientes
  ia=(int*)malloc(sizeof(int)*(2*m+1));
  ja=(int*)malloc(sizeof(int)*(2*m+1));
  ar=(double*)malloc(sizeof(double)*(2*m+1));
      
  // Cria problema de PL
  *lp = glp_create_prob();
  glp_set_prob_name(*lp, "RCP");
  glp_set_obj_dir(*lp, GLP_MAX);

  // Configura restricoes
  glp_add_rows(*lp, rows);
  for(i=0;i<m;i++)
  {
    sprintf(name, "edge%d", i+1);
    glp_set_row_name(*lp, i+1, name);
    glp_set_row_bnds(*lp, i+1, GLP_UP, 0.0, 1);
  }
  
  // Configura variaveis
  glp_add_cols(*lp, cols);
  for(i=0;i<cols;i++)
  {
    name[0]='\0';
    sprintf(name,"x%d", i+1); /* as n variaveis referem-se `as variaveis x1, x2, ..., xn*/
    glp_set_col_name(*lp, i+1, name); 
    glp_set_col_bnds(*lp, i+1, GLP_DB, 0.0, 1.0);
    glp_set_obj_coef(*lp, i+1, 1);
    glp_set_col_kind(*lp, i+1, GLP_BV); // especifica que a variaval xi eh binaria
  }

  // Configura matriz de coeficientes ... xi + xj <= 1, para cada aresta (i,j)
  nz=1;
  for(i=0;i<m;i++)
  {
    ia[nz]=i+1;
    ja[nz]=E[i].i+1;
    ar[nz]=1;
    nz++;
    ia[nz]=i+1;
    ja[nz]=E[i].j+1;
    ar[nz]=1;
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


int main(int argc, char **argv)
{     
  glp_prob *lp, *pric; // lp e problema mestre
      double z, *dual, *xstar, z_pric;
      FILE *fin;
      int i,j, *ind, icol, flg = 0;
      char name[80], *filenome;
      int it, masterCols, type;
      int colsgen, *count;
      int nels, *index, *saida, *cover, list = 0, list2 = 0, aux = 0, aux2 = 0;
      double *val;
      FILE *arq;

      glp_iocp param;
      glp_smcp param_lp;
      clock_t antes, agora;

      double valor;

      if(argc<2)
      {
      	printf("Sintaxe: Coloring <grafo>\n");
      	exit(1);
      }
      
      fin=fopen(argv[1], "r");
      if(!fin)
      {
      	printf("Problema na abertura do arquivo: %s\n", argv[1]);
      	exit(1);
      }
      if(!argv[2])
      {
        printf("Especifique o tipo da instância.\n");
        exit(1);
      }
      type = atoi(argv[2]);
      if(!argv[3])
      {
        printf("Especifique o número de cores.\n");
        exit(1);
      }
      k = atoi(argv[3]);
      if(!carga_instancia(fin, type))
      {
      	printf("Problema na carga da instancia\n");
      	exit(1);
      }
      // desabilita saidas do GLPK no terminal
      glp_term_out(GLP_OFF);

      // Carrega Problema Mestre Restrito
      carga_pmr(&lp);
      // Carrega Pricing
      carga_pricing(&pric);

      // Aloca memoria
      index=(int*)malloc(sizeof(int)*(n+1));
      val=(double*)malloc(sizeof(double)*(n+1));
      dual=(double*)malloc(sizeof(double)*(n+2));
      xstar=(double*)malloc(sizeof(double)*(n+2));
      ind=(int*)malloc(sizeof(int)*(n+2));
      saida=(int*)malloc(sizeof(int)*(n*n));
      count = (int*)malloc(sizeof(int)*(n*n));
      cover = (int*)malloc(sizeof(int)*(n+2));
	
      // Configura parametros do glpk
      glp_init_iocp(&param);
      param.presolve = GLP_ON;
      param.msg_lev = GLP_MSG_OFF;

      // Configura parametros do Simplex
      glp_init_smcp(&param_lp);
      param_lp.msg_lev = GLP_MSG_OFF;
      param.tm_lim = 1200000;

      for(i = 1; i <= n+1; i++)
      {
	      ind[i] = i;
        cover[i] = -1;
      }

      it=0;
      colsgen=0;
      antes=clock();
      do
      {
        // Executa Solver de PL para resolver PMR
        glp_simplex(lp, &param_lp);
        it++;

        // Recupera solucao
        z = glp_get_obj_val(lp);
        printf("\n****z=%g\n****it=%d\n\n", z, it);
        /* Verifica se solucao atual é inteira e se é melhor do que a inteira anterior encontrada */
        if(z >= list)
        {
          masterCols=glp_get_num_cols(lp);
          for(i=0;i<masterCols;i++)
          {
            valor=glp_get_col_prim(lp, i+1);
            if(valor > EPSILON)
            {
              if(fmod(valor, 1) != 0)
              {
                flg = 1;
              }
              nels=glp_get_mat_col(lp, i+1, index, val);
            
                printf("\n\tx%d (%g)= {", i+1, valor );
                for(j=1;j<=nels;j++)
                {
                  printf("%d (%g) ", index[j], val[j]);
                }
                printf("}\n");
            }
          }
          if(flg == 0)
          {
            /* Atualiza a nova solucao otima */
            aux2 = n;
            list = 0;
            /* Reinicializando o vetor de vertices cobertos */
            for(i = 1; i <= n+1; i++)
            {
              cover[i] = -1;
            }
            for(i = 0; i < masterCols; i++)
            {
              valor=glp_get_col_prim(lp, i+1);
              if(valor>EPSILON)
              {
                nels=glp_get_mat_col(lp, i+1, index, val);
                for(j=1;j<=nels;j++)
                {
                  if(index[j] < n + 1)
                  {
                    cover[index[j]] = list;
                    aux2--;
                  }
                }
                list++; 
              }
              nels=glp_get_mat_col(lp, i+1, index, val);
            }
            list = z;
          }
        }
        flg = 0;
       	// recupera duais
       	for(i=0;i<n;i++)
        {
          dual[i+1] = c[i];
       	  dual[i+1] = dual[i+1] - glp_get_row_dual(lp, i+1);
       	  /*printf("\n\tdual de %d = %g\n ", i+1, dual[i+1]);*/
       	  glp_set_obj_coef(pric, i+1, dual[i+1]);
          saida[i] = 0;
       	}

        #ifdef DEBUG
        	// Grava PL do Pricing atual
        	name[0]='\0';
        	sprintf(name,"pricing%d.lp", it);

        	PRINTF("\n---- LP gravado em %s", name);
        	glp_write_lp(pric,NULL,name);
        #endif

       	// resolve pricing
       	glp_intopt(pric, &param);
       	// recupera valor da solucao 
       	z_pric = glp_mip_obj_val(pric);
       	// recupera a solucao otima
       	for(i=1;i<=n;i++)
        {
       	  xstar[i]=glp_mip_col_val(pric, i);
      	}
       	//	testa se existe coluna de c.r. positivo
       	printf("\n****zPric=%g", z_pric);
       	if((z_pric) - glp_get_row_dual(lp, n+1) > EPSILON && colsgen < 2000)
        {
       	  // adiciona 1 nova coluna no PMR
       	  icol=glp_add_cols(lp, 1);
       	  name[0]='\0';
       	  sprintf(name,"n%d", icol);
       	  glp_set_col_name(lp, icol, name);
       	  glp_set_col_bnds(lp, icol, GLP_LO, 0.0, 0.0);
       	  glp_set_obj_coef(lp, icol, sum_fp(xstar)); // cada coluna contribui com quantos vertices ela tem
       	  printf("\n\tNova coluna:{ ");
       	  for(i=1;i<=n;i++)
          {
       	    if(xstar[i]>EPSILON) // uma nova linha com valor 1
     	      printf("%d (%g) ", i, xstar[i]);
       	  }
       	  printf("}\n");
        	xstar[n+1] = 1;
       	  glp_set_mat_col(lp, icol, n+1,ind,xstar); // seta os coeficientes da nova coluna no PMR, "icol" coluna i, n
          // numero de elementos na coluna, "ind" ia e "xstar" ar  
       	  colsgen++;
       	}
       	else
        {
      	  break;
       	}
        #ifdef DEBUG
         	// Grava PL do PMR atual
         	name[0]='\0';
         	sprintf(name,"coloring%d.lp", it);
           	
         	PRINTF("\n---- LP gravado em %s", name);
         	glp_write_lp(lp, NULL,name);
         	getchar();
        #endif
	  
      } while(1);
      agora=clock();
      /* gravando a solução encontrada */
      filenome = argv[1];
      strcat(filenome, ".sol");
      arq = fopen(filenome, "w");
      fprintf(arq, "%d ", aux2);
      for(i = 1; i <= n; i++)
      {
        if(cover[i] == -1)
        {
          aux = aux + c[i];
        }
      }
      /* soma dos custos de spill */
      fprintf(arq, "%d ", aux);
      fprintf(arq, "\n");
      /* variaveis nao associadas a registradores */
      for(i = 1; i <= n; i++)
      {
        if(cover[i] == -1)
        {
          fprintf(arq, "%d ", i);
        }
      }
      fprintf(arq, "\n%d\n", k);
      /* listas*/
      for(i = 0; i < k; i++)
      {
        list2 = 0;
        for(j = 1; j <= n; j++)
        {
          if(cover[j] == i)
            list2++;
        }
        fprintf(arq, "%d ", list2);
        for(j = 1; j <= n; j++)
        {
          if(cover[j] == i)
            fprintf(arq, "%d ", j);
        }
        fprintf(arq, "\n");
      }
      fclose(arq);
	
#ifdef DEBUG      
      PRINTF("\n---- solucao gravada em coloring-cg.sol");
      glp_print_sol(lp, "coloring-cg.sol");
#endif
      printf("\nSolução gravada em %s\n", filenome);
      printf("\n\n\n****z=%g\n****it=%d tempo=%g\n****colsgen=%d\n\n", z, it, ((double)agora-antes)/CLOCKS_PER_SEC, colsgen);

      // Destroi problema
      glp_delete_prob(lp);
      glp_delete_prob(pric);

      // libera memoria
      free(dual);
      free(xstar);
      free(ind);
      free(index);
      free(val);
      free(count);
      free(saida);
      free(cover);

      return 0;
}

/* eof */

