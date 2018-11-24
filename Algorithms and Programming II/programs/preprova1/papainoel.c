#include<stdio.h>

//fcao procura
void procura(int p, int m[5][5], int atual, int c[10]){
int i;

	if (p==8){
	c[p] = atual;
		for(i=0; i<9; i++){
			printf("%d", c[i]+1);
		}
		printf("\n");
		
	}else{
		for(i=0; i<5; i++){
			if (m[atual][i] == 1){
				m[atual][i] = 2;
				m[i][atual] = 2;
				c[p] = atual;
				procura(p+1, m, i, c);
				m[atual][i] = 1;
				m[i][atual] = 1;
			}
		}
	}
}

int main(void){
//variaveis
int p;
int atual;
int c[10];


int m[5][5] = {
		{0,1,1,0,1},
		{1,0,1,0,1},
		{1,1,0,1,1},
		{0,0,1,0,1},
		{1,1,1,1,0}
	};

p = 0;
atual = 0;

procura(p, m, atual, c);
return 0;
}//fim fcao main
