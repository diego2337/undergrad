#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXDIGITOS 101
#define MAIS 1
#define MENOS -1

typedef struct{
	char digitos[MAXDIGITOS]; /* representa o numero */
	int sinal; /* representa o sinal */
	int ultimodigito; /* indice do digito de mais alta ordem */
}numerogrande;

void inicializa_numgrande(numerogrande *n);
void imprime_numgrande(numerogrande *n);
void soma_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void subtrai_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void justifica_zero(numerogrande *n);
int compara_numgrandes(numerogrande *a, numerogrande *b);
void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void desloca_digito(numerogrande *n, int d);
void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void le_numgrandes(char c[MAXDIGITOS], numerogrande *n);

int max(int a, int b)
{
	return a > b ? a : b;
}

void inicializa_numgrande(numerogrande *n)
{
	int i;
	n->sinal = MAIS;
	n->ultimodigito = 0;
	for(i = 0; i < MAXDIGITOS; i++)
		n->digitos[i] = '0';
}

void imprime_numgrande(numerogrande *n)
{
	int i;
	if(n->sinal == MENOS) printf("-");
	for(i = n->ultimodigito; i >= 0; i--)
		printf("%c", n->digitos[i]);
	printf("\n");
}

void soma_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int vaium; /* vai um */
	int i; /* contador */
	char c2, c3;
	/*inicializa_numgrande(c); inicializa digitos com 0 */
	if(a->sinal == b->sinal) 
		c->sinal = a->sinal;
	else
	{
		if(a->sinal == MENOS)
		{
			a->sinal = MAIS; subtrai_numgrandes(b,a,c); a->sinal = MENOS;
		}
		else
		{
			b->sinal = MAIS; subtrai_numgrandes(a,b,c); b->sinal = MENOS;
		}
		return;
	}
	c->ultimodigito = max(a->ultimodigito, b->ultimodigito)+1;
	vaium = 0;
	for(i = 0; i <=(c->ultimodigito); i++)
	{
		c2 = (*a).digitos[i];
		c3 = (*b).digitos[i];
		if(c2 < '0')
			c2 = '0';
		if(c3 < '0')
			c3 = '0';
		/*printf("%d\t%d\t%d\t%d\t%d\t%c\n", c2, c3, (c2-'0'), (c3-'0'), (c2-'0')+(c3-'0'), ((c2-'0')+(c3-'0'))+'0');*/
		c->digitos[i] = ((vaium+(c2-'0')+(c3-'0'))%10) +'0';
		vaium = (vaium+((c2-'0')+(c3-'0'))) / 10;
	}
	justifica_zero(c);
}

void justifica_zero(numerogrande *n)
{
	while((n->ultimodigito > 0) && (n->digitos[n->ultimodigito] <= '0'))
		n->ultimodigito = n->ultimodigito - 1;
	if((n->ultimodigito == 0) && (n->digitos[0] <= '0'))
		n->sinal = MAIS; /* para evitar o -0 */
}

void subtrai_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int empresta; /* empresta do vizinho */
	int v; /* digito componente da solucao */
	int i; /* contador */
	inicializa_numgrande(c); /* inicializa digitos com 0 */
	if((a->sinal == MENOS) || (b->sinal == MENOS))
	{
		b->sinal = -1 * b->sinal; soma_numgrandes(a, b, c);
		b->sinal = -1 * b->sinal; return;
	}
	if(compara_numgrandes(a,b) == MAIS)
	{
		subtrai_numgrandes(b,a,c); c->sinal = MENOS;
		return;
	}
	c->ultimodigito = max(a->ultimodigito, b->ultimodigito);
	empresta = 0;
	for(i = 0; i <= (c->ultimodigito); i++)
	{
		if(a->digitos[i] < '0')
			a->digitos[i] = '0';
		if(b->digitos[i] < '0')
			b->digitos[i] = '0';
		v = ((a->digitos[i]-'0') - empresta - (b->digitos[i]-'0'));
		if(v < 0) v = v + 10, empresta = 1;
		else empresta = 0;
		c->digitos[i] = v+'0';
	}
	justifica_zero(c);
}

void recebe_numgrandes(numerogrande *a, numerogrande *b)
{
	int i;
	a->sinal = b->sinal;
	a->ultimodigito = b->ultimodigito;
	for(i = 0; i <=  b->ultimodigito; i++)
	{
		a->digitos[i] = b->digitos[i];
	}
}

void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int i,j; /* contadores */
	numerogrande linha, tmp;
	/*linha = *a;*/
	inicializa_numgrande(c);
	inicializa_numgrande(&linha);
	inicializa_numgrande(&tmp);
	recebe_numgrandes(&linha, a);
	for(i = 0; i <= b->ultimodigito; i++)
	{
		for(j = 1; j <= b->digitos[i] - '0'; j++)
		{
			soma_numgrandes(c, &linha, &tmp);
			recebe_numgrandes(c, &tmp);
		}
		desloca_digito(&linha, 1);
		/*for(j = 1; j <= (b->digitos[i] - '0')*pow(10, i); j++)
		{
			soma_numgrandes(c, a, c);
		}*/
	}
	c->sinal = a->sinal * b->sinal;
	justifica_zero(c);
}

/* Compara dois numeros a e b, retornando MAIS se b > a,
MENOS se a > b e 0 se a = b */
int compara_numgrandes(numerogrande *a, numerogrande *b)
{
	int i; /* contador */
	if((a->sinal==MENOS) && (b->sinal==MAIS)) {/*puts("1");*/ return MAIS;}
	if((a->sinal==MAIS) && (b->sinal==MENOS)) {/*puts("2");*/ return MENOS;}
	if(b->ultimodigito > a->ultimodigito) {/*puts("3");*/ return (MAIS * a->sinal);}
	if(a->ultimodigito > b->ultimodigito) {/*puts("4");*/ return (MENOS * a->sinal);}
	for(i = a->ultimodigito; i >= 0; i--)
	{
		if(a->digitos[i] > b->digitos[i]) {/*puts("5");*/ return (MENOS * a->sinal);}
		if(b->digitos[i] > a->digitos[i]) {/*puts("6");*/ return (MAIS * a->sinal);}
	}
	return 0;
}

/* Desloca digito (multiplica n por 10^d) */
void desloca_digito(numerogrande *n, int d)
{
	int i; /* contador */
	if((n->ultimodigito == 0) && (n->digitos[0] == 0)) return;
	for(i = n->ultimodigito; i >= 0; i--)
	n->digitos[i+d] = n->digitos[i];
	for(i = 0; i < d; i++)
	n->digitos[i] = '0';
	n->ultimodigito = n->ultimodigito + d;
}

void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	numerogrande linha; /* linha deslocada */
	numerogrande tmp; /* armazena numero grande */
	numerogrande zero;
	inicializa_numgrande(&zero);
	int asinal, bsinal; /* sinais temporarios */
	int i; /* contador */
	inicializa_numgrande(c);
	c->sinal = a->sinal * b->sinal;
	asinal = a->sinal; bsinal = b->sinal;
	a->sinal = MAIS; b->sinal = MAIS;
	inicializa_numgrande(&linha);
	inicializa_numgrande(&tmp);
	c->ultimodigito = a->ultimodigito;
	if(compara_numgrandes(&linha, &b) == 0)
	{
		printf("Divisão por zero. Finalizando programa.\n");
		exit(1);
	}
	for(i = a->ultimodigito; i >= 0; i--)
	{
		desloca_digito(&linha, 1);
		linha.digitos[0] = a->digitos[i];
		justifica_zero(&linha);
		c->digitos[i] = '0';
		while(compara_numgrandes(&linha, b) != MAIS)
		{
			c->digitos[i] = c->digitos[i] + 1;
			subtrai_numgrandes(&linha, b, &tmp);
			recebe_numgrandes(&linha, &tmp);
		}
	}
	justifica_zero(c);
	a->sinal = asinal;
	b->sinal = bsinal;
}

/* Converte inteiros para numeros grandes */
void int_to_numgrandes(int s, numerogrande *n)
{
	int i; /* contador */
	int t; /* guarda copia do inteiro */
	if(s >= 0) n->sinal = MAIS;
	else n->sinal = MENOS;
	for(i = 0; i < MAXDIGITOS; i++) n->digitos[i] = '0';
	n->ultimodigito = -1;
	t = abs(s);
	while(t > 0)
	{
		n->ultimodigito++;
		n->digitos[n->ultimodigito] = (t % 10)+'0';
		t = t / 10;
	}
	if(s == 0) n->ultimodigito = '0';
}

/* Le um numero grande */
void le_numgrandes(char c[MAXDIGITOS], numerogrande *n)
{
	int i, j = 0;
	scanf("%s", c);
	if(c[0] == '-')
	{
		n->sinal = MENOS;
		j++;
		n->ultimodigito = strlen(c)-2;
	}
	else
	{
		n->sinal = MAIS;
		n->ultimodigito = strlen(c)-1;
	}
	for(i = n->ultimodigito; i >= 0; i--, j++)
	{
		n->digitos[i] = c[j];
	}
}


/* f(n) = 2*f(n-1) + f(n-2) + f(n-3) */
numerogrande* count(numerogrande *n1, numerogrande *um, numerogrande *dois, numerogrande *tres)
{
	numerogrande one, two, three, tmp, tmp2, tmp3, tmp4, n1_copy;
	int_to_numgrandes(1, &one);
	int_to_numgrandes(2, &two);
	int_to_numgrandes(3, &three);
	inicializa_numgrande(&tmp);
	inicializa_numgrande(&tmp2);
	inicializa_numgrande(&tmp3);
	inicializa_numgrande(&tmp4);
	recebe_numgrandes(&n1_copy, n1);
	if(compara_numgrandes(n1, &one) == 0)
	{
		return um;
	}	
	else if(compara_numgrandes(n1, &two) == 0)
	{
		return dois;
	}
	else if(compara_numgrandes(n1, &three) == 0)
	{
		return tres;
	}
	else
	{
		/* obter f(n-1) */
		subtrai_numgrandes(&n1_copy, &one, &tmp);
		recebe_numgrandes(n1, &tmp);
		recebe_numgrandes(&tmp, count(n1, um, dois, tres));
		/*puts("f(n-1)");
		imprime_numgrande(&tmp);*/
		/* multiplicar por 2 */
		multiplica_numgrandes(&tmp, &two, &tmp2);
		/* obter f(n-2) */
		subtrai_numgrandes(&n1_copy, &two, &tmp);
		recebe_numgrandes(n1, &tmp);
		recebe_numgrandes(&tmp3, count(n1, um, dois, tres));
		/*puts("f(n-2)");
		imprime_numgrande(&tmp3);*/
		/* obter f(n-3) */
		subtrai_numgrandes(&n1_copy, &three, &tmp);
		recebe_numgrandes(n1, &tmp);
		recebe_numgrandes(&tmp, count(n1, um, dois, tres));
		/*puts("f(n-3)");
		imprime_numgrande(&tmp);*/
		/* 'n_copy' vira auxiliar */
		soma_numgrandes(&tmp2, &tmp3, &n1_copy);
		/* Armazena soma em 'um' */
		soma_numgrandes(&n1_copy, &tmp, &tmp4);
		return &tmp4;
	}
}


int main(void)
{
	numerogrande n1, cnt[10000], um;
	int x, i;
	int_to_numgrandes(2, &cnt[1]);
	int_to_numgrandes(5, &cnt[2]);
	int_to_numgrandes(13, &cnt[3]);
	inicializa_numgrande(&um);
	for(i = 4; i < 10000; i++)
	{
		inicializa_numgrande(&cnt[i]);
		soma_numgrandes(&cnt[i-1], &cnt[i-1], &um);
		recebe_numgrandes(&cnt[i], &um);
		/*soma_numgrandes(&cnt[i-1], &cnt[i], &cnt[i]);*/
		soma_numgrandes(&cnt[i-2], &um, &cnt[i]);
		recebe_numgrandes(&um, &cnt[i]);
		soma_numgrandes(&cnt[i-3], &um, &cnt[i]);
	}
	while(scanf("%d", &x) != EOF)
	{
		inicializa_numgrande(&n1);
		int_to_numgrandes(x, &n1);
		imprime_numgrande(&cnt[x]);
		/*imprime_numgrande(count(&n1, &um, &dois, &tres));*/
	}
	return 0;
}