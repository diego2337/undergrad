/* THE INDEPENDENT SET PROBLEM
	Given a graph G = (V, E), find an independent set in G of maximum cardinality

	Obcjective function: Z = MAX sum_(i belongs to E) xi
	Subject to: sum(i belongs to V) xi >= 1
	xi + xj <= 1, For all (i, j) belonging to E */

#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>

int load_instance(FILE *arq, int *n, int *m, int ***A)
{
	int i, j, count;
	fscanf(arq, "%d %d\n", n, m);
	printf("n: %d m: %d\n", *n, *m);
	*A = (int**) malloc(sizeof(int*)*(*n+1));
	for(i=0;i<*n+1;i++)
	{
    	(*A)[i]=(int*) malloc(sizeof(int)*(*n+1));
    	for(j=0;j<*n+1;j++)
    	{
      		(*A)[i][j]=0;
    	}
    }
    count = 0;
    while(!feof(arq))
    {
	    fscanf(arq, "%d %d\n", &i,&j);
	    printf("vertice: %d aresta: %d\n", i,j);
	    /* Can't have a vertice or edge with 0 or bigger than n */
	    if (i<1 || i>*n || j < 1 || j > *n)
	    {
	      return 0;
		}
		/* In case they're connected by an edge */
	    if(!(*A)[i][j])
	    {
	      (*A)[i][j] = (*A)[j][i] = 1;
	      count++;
	    }
 	}
    if(count != *m)
    {
    	if(2*count == *m)
    	{
        	*m = count;
        	return 1;
    	}
    	return 0;
    }
    return 1;
}

int lp_load(glp_prob **lp, int n, int m, int **A)
{

  
	int *ia, *ja, rows, cols, i, j, nz, k, aresta;
	double *ar;
	char name[80];
    rows = m*n + n; 
    cols = n + n*n; 
	// Coefficient matrix's creation
	ia = (int*)malloc(sizeof(int)*(3*(m*n)+n*n+1));
	ja = (int*)malloc(sizeof(int)*(3*(m*n)+n*n+1));
	ar = (double*)malloc(sizeof(double)*(3*(m*n)+n*n+1));     
	// Creating a LP problem
	*lp = glp_create_prob();
	glp_set_prob_name(*lp, "independent_set");
	glp_set_obj_dir(*lp, GLP_MAX);
	// Constraints
	glp_add_rows(lp, rows);
	for(i = 0; i < m*n; i++)
	{
		name[0]='\0';
    	sprintf(name,"p%d", i+1);
		glp_set_row_name(*lp, i+1, name);
		glp_set_row_bnds(*lp, i+1, GLP_LO, 1.0, 0.0);
	}
	for(; i < rows; i++)
	{
		name[0]='\0';
    	sprintf(name,"q%d", i+1);
		glp_set_row_name(*lp, i+1, name);
		glp_set_row_bnds(*lp, i+1, GLP_UP, 0.0, 1.0);
	}
	// Variables
	glp_add_cols(*lp, cols);
	for(i=0;i<n;i++)
	{
		name[0]='\0';
		sprintf(name,"x%d", i+1);
		glp_set_col_name(*lp, i+1, name);
		glp_set_col_bnds(*lp, i+1, GLP_FX, 1.0, 1.0);
		glp_set_obj_coef(*lp, i+1, 1.0);
		glp_set_col_kind(*lp, i+1, GLP_BV); // xi is a binary variable
	}
}
int main(int argc, char **argv)
{
	glp_prob *lp;
	FILE *arq;
	double z;
	int n, m, i, j, k, status;
	int **A;
	glp_smcp parameters;

	if(argc < 2)
	{
		printf("Please insert the './' directive with the executable file name and the graph you wish to use for this program.\n");
		exit(0);
	}
	arq = fopen(argv[0], "r");
	if(!arq)
	{
		printf("The file was not read correctly.\n");
		exit(0);
	}
	if(!load_instance(arq, &n, &m, &A))
	{
		printf("Problem with the instance load.\n");
		exit(0);
	}
	glp_term_out(GLP_OFF);
}