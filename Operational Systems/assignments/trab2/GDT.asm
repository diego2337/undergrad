; Essa sera a tabela de descricao global, que servira para armazenar as caracteristicas dos segmentos de memoria 
GDT_start: ; pusemos esse rotulo dessa maneira a fim de calcularmos o tamanho da tabela (abaixo)
	GDT_null: ; a primeira entrada do GDT contem um NULL para tratamento de exceçoes
		DD 0x0
		DD 0x0

	GDT_code: ; agora, a descricao do segmento de CODIGO que queremos identificar
		DW 0xffff ; O limite do segmento (ate onde ele e endereçado)
		DW 0x0 ; A base do segmento
		DB 0x0 ; Para completar os 24 bits da base
		DB 10011010b ; aqui, identificamos as 8 primeiras flags que compoem a tabela
		DB 11001111b ; agora, o restante das flags que faltavam ser identificadas
		DB 0x0

	GDT_data: ; agora, a descricao do segmento de DADOS que iremos identificar
		DW 0xffff ; O limite do segmento (ate onde ele e endereçado)
		DW 0x0 ; A base do segmento
		DB 0x0 ; Para completar os 24 bits da base
		DB 10010010b ; aqui, identificamos as 8 primeiras flags que compoem a tabela
		DB 11001111b ; agora, o restante das flags que faltavam ser identificadas
		DB 0x0

GDT_end: ; com esses dois rotulos, podemos calcular o tamanho do GDT 

GDT_descriptor:

	DW GDT_end - GDT_start - 1 ; Calculando o tamanho do GDT, que e sempre menos um 
	DD GDT_start ; Endereco inicial do GDT

CODESEG equ GDT_code - GDT_start
DATASEG equ GDT_data - GDT_start
