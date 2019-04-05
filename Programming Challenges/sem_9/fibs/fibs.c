#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	inicializa_numgrande(c); /* inicializa digitos com 0 */
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
		/*printf("%d\t%d\t%d\t%d\t%d\t%c\n", c2, c3, (c2-'0'), (c3-'0'), (c2-'0')+(c3-'0'), ((c2-'0')+(c3-'0'))+'0');*/
		c->digitos[i] = ((vaium+(c2-'0')+(c3-'0'))%10) +'0';
		vaium = (vaium+((c2-'0')+(c3-'0'))) / 10;
	}
	justifica_zero(c);
}

void justifica_zero(numerogrande *n)
{
	while((n->ultimodigito > 0) && (n->digitos[n->ultimodigito] == '0'))
		n->ultimodigito--;
	if((n->ultimodigito == 0) && (n->digitos[0] == '0'))
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
		v = (a->digitos[i] - empresta - b->digitos[i]);
		if(v < 0) v = v + 10, empresta = 1;
		else empresta = 0;
		c->digitos[i] = v;
	}
	justifica_zero(c);
}

void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	numerogrande linha; /* linha deslocada */
	numerogrande tmp; /* armazena numero grande */
	int i,j; /* contadores */
	inicializa_numgrande(c);
	linha = *a;
	for(i = 0; i <= b->ultimodigito; i++)
	{
		for(j = 1; j <= b->digitos[i]; j++)
		{
			soma_numgrandes(c, &linha, &tmp);
			*c = tmp;
		}
		desloca_digito(&linha, 1);
	}
	c->sinal = a->sinal * b->sinal;
	justifica_zero(c);
}

/* Compara dois numeros a e b, retornando MAIS se b > a,
MENOS se a > b e 0 se a = b */
int compara_numgrandes(numerogrande *a, numerogrande *b)
{
	int i; /* contador */
	if((a->sinal==MENOS) && (b->sinal==MAIS)) return MAIS;
	if((a->sinal==MAIS) && (b->sinal==MENOS)) return MENOS;
	if(b->ultimodigito > a->ultimodigito) return (MAIS * a->sinal);
	if(a->ultimodigito > b->ultimodigito) return (MENOS * a->sinal);
	for(i = a->ultimodigito; i >= 0; i--)
	{
		if(a->digitos[i] > b->digitos[i]) return (MENOS * a->sinal);
		if(b->digitos[i] > a->digitos[i]) return (MAIS * a->sinal);
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
	n->digitos[i] = 0;
	n->ultimodigito = n->ultimodigito + d;
}

void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	numerogrande linha; /* linha deslocada */
	numerogrande tmp; /* armazena numero grande */
	int asinal, bsinal; /* sinais temporarios */
	int i; /* contador */
	inicializa_numgrande(c);
	c->sinal = a->sinal * b->sinal;
	asinal = a->sinal; bsinal = b->sinal;
	a->sinal = MAIS; b->sinal = MAIS;
	inicializa_numgrande(&linha);
	inicializa_numgrande(&tmp);
	c->ultimodigito = a->ultimodigito;
	for(i = a->ultimodigito; i >= 0; i--)
	{
		desloca_digito(&linha, 1);
		linha.digitos[0] = a->digitos[i];
		c->digitos[i] = 0;
		while(compara_numgrandes(&linha, b) != MAIS)
		{
			c->digitos[i]++;
			subtrai_numgrandes(&linha, b, &tmp);
			linha = tmp;
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
	for(i = 0; i < MAXDIGITOS; i++) n->digitos[i] = 0;
	n->ultimodigito = -1;
	t = abs(s);
	while(t > 0)
	{
		n->ultimodigito++;
		n->digitos[n->ultimodigito] = t % 10;
		t = t / 10;
	}
	if(s == 0) n->ultimodigito = 0;
}

int count = 0;

void big_fibs(numerogrande upper, numerogrande lower)
{
	numerogrande zero, um, t;
	inicializa_numgrande(&zero);
	inicializa_numgrande(&um);
	inicializa_numgrande(&t);
	um.digitos[0] = '1';
	zero.digitos[0] = '0';
	um.ultimodigito = 0;
	zero.ultimodigito = 0;
	/*imprime_numgrande(&um);
	imprime_numgrande(&t);*/
	int i = 0;
	for(; compara_numgrandes(&um, &upper) != MENOS; i++)
	{
		soma_numgrandes(&zero, &um, &t);
		/*printf("t:");
		imprime_numgrande(&t);*/
		zero = um;
		um = t;
		if((compara_numgrandes(&um, &upper) == MAIS || compara_numgrandes(&um, &upper) == 0) && 
			(compara_numgrandes(&um, &lower) == MENOS || compara_numgrandes(&um, &lower) == 0))
			count++;
	}
	/*if(compara_numgrandes(lower, zero) == 0 || compara_numgrandes(upper, zero) == 0)
		return;
	else if(compara_numgrandes(lower, upper) == MENOS)
		return;
	else
	{
		count++;
		
	}*/
}

int main(void)
{
	numerogrande a, b;
	inicializa_numgrande(&a);
	inicializa_numgrande(&b);
	char c[102];
	int i, j, k;
	while(scanf("%s", c) != EOF)
	{
		if(strcmp(c, "0") == 0)
			k = 1;
		count = 0;
		j = strlen(c) - 1;
		a.ultimodigito = j;
		i = 0;
		for(; j >= 0; j--)
		{
			if(c[j] != '-')
			{
				a.digitos[i] = c[j];
				i++;
			}
		}
		if(c[j] == '-')
			a.sinal = MENOS;
		else
			a.sinal = MAIS;
		scanf("%s", c);
		if(k==1 && strcmp(c, "0") == 0)
			break;
		j = strlen(c)-1;
		b.ultimodigito = j;
		i = 0;
		for(; j >= 0; j--)
		{
			if(c[j] != '-')
			{
				b.digitos[i] = c[j];
				i++;
			}
		}
		if(c[j] == '-')
			b.sinal = MENOS;
		else
			b.sinal = MAIS;
		big_fibs(b, a);
		/*imprime_numgrande(&a);
		imprime_numgrande(&b);*/
		printf("%d\n", count);
	}

	return 0;
}