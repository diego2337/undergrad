#include<stdio.h>

int valida(int x, int y, int m, int n, char M[100][100]){
	int ret = 0;
	if(x < m && y < n && x >=0 && y >=0){
		if(M[x][y] == '1'){
			ret = 1;
		}
	}
	return ret;


}

void labirinto(int x, int y, int m, int n, char M[100][100]){
	int i, j;	
	
	if(x == m-1 && y==n-1){
		M[x][y]='x';
		/*printf("solucao\n");	*/
		for (i = 0; i < m; i += 1)
		{
			for (j = 0; j < n; j += 1)
			{
				printf("%c", M[i][j]);
			}
			printf("\n");
		}
			printf("\n");
	
	}else{
		
		M[x][y]='x';	
		
			/*terceiro*/	
		if(valida((x-1), y, m, n, M))
			labirinto((x-1), y, m, n, M);
		
		/*primeiro*/	
		if(valida(x, (y-1), m, n, M))
			labirinto(x, (y-1), m, n, M);
			
	
		
		/*quarto*/	
		if(valida((x+1), y, m, n, M))
			labirinto((x+1), y, m, n, M);	
		
		/*segundo*/	
		if(valida(x, (y+1), m, n, M))
			labirinto(x, (y+1), m, n, M);	
		
			
	}
	M[x][y]='1';


}


int main(){

	int i, ent, m, n, a, b, x, y;
	scanf("%d ", &ent);
	char M[100][100];
	for (i = 0; i < ent; i += 1)
	{
		/*char M[x][y];*/
		x=0;
		y=0;
		scanf("%d %d ", &m, &n);
		/*printf("%d, %d\n\n", m, n);*/
		/*leitura da matriz*/
		
		for (a = 0; a < m; a++)
		{
			
			for (b = 0; b < n; b++)
			{

				scanf("%c ", &M[a][b]);
			}
			
		}	
		
		/*chamada da função recursiva*/
		labirinto(x, y, m, n, M);
			
	}
	
	return 0;

}
