[ORG 0x7c00]
DESLOCAMENTO_KERNEL equ 0x1000 ; O deslocamento de memoria onde carregaremos o kernel
MOV SI, boot16
CALL print  

[BITS 16]
load_kernel:
	MOV SI, kernel_load ; Mensagem de carregamento do kernel
	CALL print

switch:
	CLI ; desabilita as interrupcoes ate que possamos passar para 32 bits
	LGDT [GDT_descriptor] ; essa instrucao ira carregar a tabela de descricao global para esse modo, que define os segmentos de codigo e de dados
	MOV EAX, CR0 ; devemos alterar esse registrador de controle a fim de podermos trocar os modos
	OR EAX, 0x1 ; Utilizamos a instrucao "OR" para nao mexer em outros valores ja pre definidos nesse registrador
	MOV CR0, EAX ; Finalmente, atualizamos o registrador "CR0"

	JMP CODESEG:inicio32 ; Essa instrucao realiza um pulo distante, o que "gera" na CPU uma "incerteza" em relacao as instrucoes que sucedem essa, forcando-a a limpar seu cache de instrucoes pre-buscadas e decodificadas (tecnica utilizada em arquiteturas com pipeline, o que pode causar problemas)

[BITS 32] ; Passamos ao modo de 32 bits

inicio32:

	MOV AX, DATASEG ; os segmentos desses registradores estavam relacionados ao modo de 16 bits e, portanto, agora sao inuteis - vamos atribuir os novos segmentos especificados no GDT
	MOV DS, AX
	MOV SS, AX
	MOV ES, AX
	MOV FS, AX ; dois novos registradores de segmento que ganhamos nesse novo modo
	MOV GS, AX
	
	MOV EBP, 0x90000 ; Como especificado anteriormente, agora atualizaremos a pilha para o novo modo
	MOV ESP, EBP
	MOV EBX, boot32
	CALL print32 ; Como prova de que estamos no modo protegido, chamaremos a subrotina de impressao nesse modo, imprimindo diretamente da secao de video da memoria

	CALL DESLOCAMENTO_KERNEL ; Iremos para onde o kernel esta carregado

	JMP $
; o rotulo "inicio32" se encontra no arquivo bootk.asm

disk_error :
	MOV SI , errormsg
	JMP print
	ret

print: MOV AL, [SI]
       INC SI
       CMP AL, 0
       JZ pend2
       MOV AH, 0x0E
       MOV BH, 0x00
       MOV BL, 0x07
       INT 0x10
       JMP print
       pend2:
            ret

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


[BITS 32] ; Assim como nos codigos anteriores, estamos avisando ao montador que este codigo e endereçado em 32 bits

; E importante notar que, dentro dessa secao, utilizaremos registradores estendidos ("EAX", "EBX"...) e que o endereço "0xb8000" corresponde ao segmento de memoria onde os dados de video sao trabalhados.
print32:
	MOV EDX, 0xb8000 ; estamos movendo o registrador EDX para o inicio do segmento de video
	MOV AL, [EBX] ; atribuindo o valor do que esta no registrador "EBX" para AL, para impressao
	CMP AL, 0 ; comparando o registrador para verificar se chegamos ao final da string
	JMP back32 ; caso sim, termina a subrotina
	MOV [EDX], AX ; Estamos armazenando o caractere e seus atributos no seguinte segmento de memoria de video
	ADD EBX, 1 ; Prosseguindo ao proximo caractere
	ADD EDX, 2 ; Prosseguindo a proxima regiao de memoria de video
	JMP print32

back32:
	ret



;.DATA
BOOT_DRIVE: db 0
errormsg db "Erro na leitura do disco", 0
successmsg db "A leitura do disco foi bem sucedida!", 0

boot16 DB "Estamos em modo de 16 bits", 0
boot32 DB "Estamos em modo de 32 bits", 0
kernel_load DB "Carregando kernel na memoria...", 0
CODESEG equ GDT_code - GDT_start
DATASEG equ GDT_data - GDT_start

TIMES 510-($-$$) db 0
;TIMES 3536 db 0
DW 0xaa55

