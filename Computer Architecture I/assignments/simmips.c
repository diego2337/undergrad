/* Alunos: Diego Cintra e Nicolas Roque */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned char bytes[4];
}instructions;

void swap(instructions *mem)
{
	char sw;
	sw = (mem)->bytes[0];
	(mem)->bytes[0] = (mem)->bytes[3];
	(mem)->bytes[3] = sw;
	sw = (mem)->bytes[1];
	(mem)->bytes[1] = (mem)->bytes[2];
	(mem)->bytes[2] = sw;
}

void init2(instructions *instrucoes)
{
	instrucoes->bytes[0] = 0;
	instrucoes->bytes[1] = 0;
	instrucoes->bytes[2] = 0;
	instrucoes->bytes[3] = 0;
}

typedef struct{
	int ninstructions; // Ira armazenar o numero de instruçoes que o programa possui
	int nALUexecutions; // Armazena o numero de instruçoes logico-aritmeticas executadas
	int nmultdivexecutions; // Armazena o numero de instruçoes de multiplicaçao e divisao executadas
	int nmemoryexecutions; // Ira armazenar o numero de instruçoes que acessam a memoria
	int ncmpexecutions; // Armazena o numero de instruçoes de comparaçao executadas
	int nbeqexecutions; // Armazena o numero de instruçoes de desvios condicionais executadas
	int njexecutions; // Ira armazenar o numero de instruçoes de desvios incondicionais executadas	
	int nsysexecutions; // Armazena o numero de instruçoes que chamam o SO executadas
	int notherexecutions; // Armazena o numero de outras instruçoes executadas
}statistics;

void init(statistics *estatisticas)
{
	estatisticas->ninstructions = 0;
	estatisticas->nALUexecutions = 0;
	estatisticas-> nmultdivexecutions = 0;
	estatisticas->nmemoryexecutions = 0;
	estatisticas->ncmpexecutions = 0;
	estatisticas->nbeqexecutions = 0;
	estatisticas->njexecutions = 0;
	estatisticas->nsysexecutions = 0;
	estatisticas->notherexecutions = 0;
}

/* Funcao que retorna o número requisitado de bits */
int get_x_bits(int msb, int lsb, int *IR)
{
	return ((*IR >> lsb) & ~(~0 << (msb-lsb+1))); 
}

void instruction_fetch(int *IR, int *PC, instructions memaux)
{
	*IR = memaux.bytes[0]; // Guardando a instruçao em IR 
	*IR = *IR << 8;
	*IR = *IR | memaux.bytes[1];
	*IR = *IR << 8;
	*IR = *IR | memaux.bytes[2];
	*IR = *IR << 8;
	*IR = *IR | memaux.bytes[3];
	*PC = *PC + 1; // Apesar de em uma arquitetura real o PC ser incrementado em 4 bytes, visto
	// que estamos em um simulador, iremos so incrementa-lo para a proxima instruçao no vetor mem
	// (estamos utilizando uma struct)
}

void instruction_decode(int *IR, int *op, int *rs, int *rt, int *rd, int *shamt, int *funct, int *immediate, int *address)
{
	// Campo OP: 31-26; Campo rs: 25-20...
	*op = get_x_bits(31, 26, IR);
	*rs = get_x_bits(25, 21, IR);
	*rt = get_x_bits(20, 16, IR);
	*rd = get_x_bits(15, 11, IR);
	*shamt = get_x_bits(10, 6, IR);
	*funct = get_x_bits(5, 0, IR);
	*immediate = get_x_bits(15, 0, IR);
	*address = get_x_bits(25, 0, IR);

}

void execution(int op, int rs, int rt, int rd, int shamt, int funct, int immediate, int address, int registradores[], instructions *mem, statistics *estatisticas, int *PC, int *Hi, int *Lo)
{
	switch(op)
	{
		/* instruçoes do tipo R */
		case 0: 
			switch(funct)
			{
				case 0: // shift left logical (sll rd, rs, shamt)
					registradores[rd] = registradores[rs] << shamt;
					estatisticas->notherexecutions++;
					break;		
				case 2: // shift right logical (srl rd, rs, shamt)
					registradores[rd] = registradores[rs] >> shamt;
					estatisticas->notherexecutions++;
					break;
				case 8: // jump register (jr rs)
					*PC = registradores[rs];
					estatisticas->njexecutions++;
					break;
				case 12: // system call (syscall)
					// sempre olha o registrador $v0 (na posicao 2)
					if(registradores[2] == 10)
						*PC = -1;
					estatisticas->nsysexecutions++;
					break;
				case 16: // move from Hi (mfhi rd)
					registradores[rd] = *Hi;
					estatisticas->notherexecutions++;
					break;
				case 18: // move from Lo (mflo rd)
					registradores[rd] = *Lo;
					estatisticas->notherexecutions++;
					break;
				case 24: // multiply (mult rs, rt)
					*Hi = registradores[rs] * registradores[rt];
					*Lo = registradores[rs] * registradores[rt];
					estatisticas->nmultdivexecutions++;
					break;
				case 26: // divide (div rs, rt)
					*Lo = (registradores[rs]/registradores[rt]);
					*Hi = (registradores[rs] % registradores[rt]);
					estatisticas->nmultdivexecutions++;
					break;
				case 32: // add (add rd, rs, rt)
					registradores[rd] = registradores[rs]+registradores[rt];
					estatisticas->nALUexecutions++;
					break;
				case 34: // sub (sub rd, rs, rt)
					registradores[rd] = registradores[rs]-registradores[rt];
					estatisticas->nALUexecutions++;
					break;
				case 36: // and (and rd, rs, rt)
					registradores[rd] = registradores[rs] && registradores[rt];
					estatisticas->nALUexecutions++;
				case 37: // or (or rd, rs, rt)
					registradores[rd] = registradores[rs] || registradores[rt];
					estatisticas->nALUexecutions++;
				case 39: // nor (nor rd, rs, rt)
					registradores[rd] = !(registradores[rs] || registradores[rt]);
					estatisticas->nALUexecutions++;
				case 42: // set on less than (slt rd, rs, rt)
					if(registradores[rs] < registradores[rt])
						registradores[rd] = 1;
					else
						registradores[rd] = 0;
					estatisticas->ncmpexecutions++;
					break;
			}
			break;
		/* Instruçoes do tipo J */
		case 2: // jump (j address)
			// É necessario concatenar bits aqui
			*PC = (get_x_bits(31, 28, PC) << 26) | address;
			estatisticas->njexecutions++;
			break;
		case 3: // jump and link (jal address)
			registradores[31] = *PC;
			*PC = (get_x_bits(31, 28, PC) << 26) | address;
			estatisticas->njexecutions++;
			break;
		/* Instruçoes do tipo I */
		case 4: // branch on equal (beq rs, rt, immediate)
			if(registradores[rs] == registradores[rt])
				*PC += (immediate);
			estatisticas->nbeqexecutions++;
			break;
		case 5: // branch on not equal (bne rs, rt, immediate)
			if(registradores[rs] != registradores[rt])
				*PC += (immediate);
			estatisticas->nbeqexecutions++;
			break;
		case 8:	// add immediate (addi, rt, rs, immediate)
			registradores[rt] = registradores[rs] + (immediate);
			estatisticas->nALUexecutions++;
			break;
		case 10: // set on less than immediate (slti rt, rs, immediate)
			if(registradores[rs] < (immediate))
				registradores[rt] = 1;
			else
				registradores[rt] = 0;
			estatisticas->ncmpexecutions++;
			break;
		case 12: // and immediate (andi rt, rs, immediate)
			registradores[rt] = registradores[rs] && (immediate);
			estatisticas->nALUexecutions++;
			break;
		case 13: // or immediate (ori rt, rs, immediate)
			registradores[rt] = registradores[rs] || (immediate);
			estatisticas->nALUexecutions++;
			break;
		case 15: // load upper immediate (lui rt, immediate)
			registradores[rt] = (immediate); //  shiftar 16 bits a esquerda?
			estatisticas->notherexecutions++;
			break;
		case 35: // load word (lw rt, immediate (rs))
			registradores[rt] = ((mem+(registradores[rs]/4)+(immediate)-1)->bytes[0]); // estamos subtraindo 1 porque a primeira instruçao do codigo esta na posiçao 0
			registradores[rt] = registradores[rt] << 8;
			registradores[rt] = registradores[rt] | ((mem+(registradores[rs]/4)+(immediate)-1)->bytes[1]);
			registradores[rt] = registradores[rt] << 8;
			registradores[rt] = registradores[rt] | ((mem+(registradores[rs]/4)+(immediate)-1)->bytes[2]);
			registradores[rt] = registradores[rt] << 8;
			registradores[rt] = registradores[rt] | ((mem+(registradores[rs]/4)+(immediate)-1)->bytes[3]);
			estatisticas->nmemoryexecutions++;
			break;
		case 43: // store word (sw rt, immediate (rs))
			((mem+(registradores[rs]/4)+(immediate)-1)->bytes[0]) = get_x_bits(31, 24, &registradores[rt]);
			((mem+(registradores[rs]/4)+(immediate)-1)->bytes[1]) = get_x_bits(23, 16, &registradores[rt]);
			((mem+(registradores[rs]/4)+(immediate)-1)->bytes[2]) = get_x_bits(15, 8, &registradores[rt]);
			((mem+(registradores[rs]/4)+(immediate)-1)->bytes[3]) = get_x_bits(7, 0, &registradores[rt]);
			estatisticas->nmemoryexecutions++;
			break;
	}
}

int main(int argc, char *argv[])
{
	int *aux, *aux2, tmp;
	int PC, *$gp, *$sp, IR, i, j, Hi, Lo, registradores[30] = { 0 };
	int op, rs, rt, rd, shamt, funct, immediate, address;
	unsigned char *temp;
	instructions *mem, memaux;
	statistics estatisticas;
	FILE *arq;
	arq = fopen(argv[1], "rb");
	rewind(arq);
		PC = fseek(arq, 8, SEEK_SET); // Pulando os dois primeiros inteiros para
	//posicionar PC no endereço da primeira instruçao. Servira como indice para o vetor mem
	rewind(arq);
		aux = malloc(4*sizeof(int));
		aux2 = malloc(4*sizeof(int));
		temp = malloc(1*sizeof(char));
		fread(aux, 4, 1, arq); // Armazenando em "aux" o inteiro que indica o numero de instruçoes
	// de maquina
	rewind(arq);
		fseek(arq, 4, SEEK_SET); 
		fread(aux2, 4, 1, arq); // Armazenando em "aux2" o numero de dados do programa
	rewind(arq);
		fseek(arq, 8, SEEK_SET);
		mem = malloc(((*aux)+(*aux2))*sizeof(instructions));
		for(i = 0; i < (*aux + *aux2); i++)
		{
			for(j = 0; j < 4; j++)
			{
				fread(temp, 1, 1, arq);
				((mem+i)->bytes[j]) = *temp;
			}
			swap(&*(mem+i));
		}
	rewind(arq);
		tmp = *aux+1;
	init(&estatisticas);
	estatisticas.ninstructions = *aux;
	while(PC != -1)
	{
		registradores[28] = tmp*4; // o registrador 28 corresponde ao $gp, e sempre deve
		// apontar para o começo da seçao de dados do programa
		registradores[29] = (tmp + *aux2)*4; // ja o registrador 29 sempre ira armazenar o topo
		// da pilha de dados, ou seja, o ultimo dado presente
		// multiplicamos por 4 os valores para, quando quisermos usar as instruçoes load word e 
		// store word, elas pulem de palavra em palavra
		(memaux.bytes[0]) = (((mem+PC)->bytes[0]));
		(memaux.bytes[1]) = (((mem+PC)->bytes[1]));
		(memaux.bytes[2]) = (((mem+PC)->bytes[2]));
		(memaux.bytes[3]) = (((mem+PC)->bytes[3]));
		instruction_fetch(&IR, &PC, memaux);
		instruction_decode(&IR, &op, &rs, &rt, &rd, &shamt, &funct, &immediate, &address);
		execution(op, rs, rt, rd, shamt, funct, immediate, address, registradores, mem, &estatisticas, &PC, &Hi, &Lo);
	}
	/* Vamos imprimir as estatisticas da execuçao */
	printf("%d\n", estatisticas.ninstructions);
	printf("%d\n", estatisticas.nALUexecutions);
	printf("%d\n", estatisticas.nmultdivexecutions);
	printf("%d\n", estatisticas.nmemoryexecutions);
	printf("%d\n", estatisticas.ncmpexecutions);
	printf("%d\n", estatisticas.nbeqexecutions);
	printf("%d\n", estatisticas.njexecutions);
	printf("%d\n", estatisticas.nsysexecutions);
	printf("%d\n", estatisticas.notherexecutions);
	fclose(arq);
	return 0;	
}