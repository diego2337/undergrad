// Programa: cadastro.c
// Programador: Diego Cintra
// Data: 05/02/2013
// O dialogo: Esse programa ira trabalhar em conjunto com os programas hotel.c e checkin.c, para fazer o cadastro do hospede.
#include "hotel.h"
int cadastro(quarto cadastro, int numquarto, char *argv[3], char *argv[2], char *argv[1])
{
	FILE *hotelbin, *quartos, *nomes;
	int barq, bstruct, index;
	cadastro.nome = argv[1];
	cadastro.numero = numquarto;
	cadastro.data_check_in = argv[2];
	cadastro.data_check_out = 0;
	cadastro.tipo_quarto = argv[3];
	cadastro.ocupado = 1;
	hotelbin = fopen("hotel.bin", "a+b");
		// Iremos descobrir o tamanho (em bytes) dos arquivos hotel.bin e quarto.txt. Dividindo os dois saberemos, atraves do quociente, em qual posicao o cadastro ficara.
		fseek(hotelbin, 0, SEEK_END);
		bstruct = sizeof(quarto);
		barq = ftell(bin);
		if(barq == 0)
		index = 0;
		else if(barq == bstruct)
		index = 1;
		else
		index = barq/bstruct;
		fprintf(hotelbin, "%c\n%d\n%c\n%d\n%d\n%d");
		fclose(hotelbin);
	// Agora iremos escrever os dados em quartos.txt e nomes.txt.
	quartos = fopen("quartos.txt", "a+");
		fseek(hotelbin, 0, SEEK_END);
		fprintf(quartos, "%d %d", numquarto, index);
		fclose(quartos);

	nomes = fopen("nomes.txt", "a+");
		fseek(hotelbin, 0, SEEK_END);
		fprintf(nomes, "%d %d", argv[2], index);
		fclose(quartos);
	return cadastro;
}
