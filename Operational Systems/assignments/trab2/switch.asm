[BITS 16] ; Diz ao montador que o codigo e de 16 bits - iremos transgredir esse modo para 32 bits
[ORG 0x7c00] ; O endereco inicial da proura do bootloader pela BIOS

	MOV BP, 0x9000 ; teremos de alterar a pilha no modo de 32 bits, entao iremos identifica-la
	MOV SP, BP  
back: ; Agora iremos para o modo de 32 bits

%INCLUDE "GDT.asm"

switch:
	CLI ; desabilita as interrupcoes ate que possamos passar para 32 bits
	LGDT [GDT_descriptor] ; essa instrucao ira carregar a tabela de descricao global para esse modo, que define os segmentos de codigo e de dados
	MOV EAX, CR0 ; devemos alterar esse registrador de controle a fim de podermos trocar os modos
	OR EAX, 0x1 ; Utilizamos a instrucao "OR" para nao mexer em outros valores ja pre definidos nesse registrador
	MOV CR0, EAX ; Finalmente, atualizamos o registrador "CR0"

	JMP CODESEG:inicio32 ; Essa instrucao realiza um pulo distante, o que "gera" na CPU uma "incerteza" em relacao as instrucoes que sucedem essa, forcando-a a limpar seu cache de instrucoes pre-buscadas e decodificadas (tecnica utilizada em arquiteturas com pipeline, o que pode causar problemas)

; o rotulo "inicio32" se encontra no arquivo bootk.asm

boot16 DB "Estamos em modo de 16 bits", 0
boot32 DB "Estamos em modo de 32 bits", 0

;TIMES 622 - ($-$$) db 0
DW 0xAA55
