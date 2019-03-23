[ORG 0x7c00]
DESLOCAMENTO_KERNEL equ 0x1000 ; O deslocamento de memoria onde carregaremos o kernel

; As proximas tres instrucoes sao parametros para a funcao "disk_load", que fara uma leitura no disco
MOV [BOOT_DRIVE], DL
MOV BP, 0x8000
MOV SP, BP ; Essa instrucao poe a pilha fora da area onde vamos fazer a leitura do disco
MOV SI, boot16
CALL print  

CALL load_kernel ; Iremos carregar o kernel no segmento de memoria especificado

CALL switch ; Agora iremos do modo real para o modo protegido (nao retornaremos dessa "subrotina")

jmp $

%INCLUDE "disk_load.asm"
%INCLUDE "switch.asm"
%INCLUDE "print32.asm"

[BITS 16]

load_kernel:
	MOV SI, kernel_load ; Mensagem de carregamento do kernel
	CALL print


	MOV BX, DESLOCAMENTO_KERNEL ; Estamos arrumando os parametros para a funcao "disk_load", de maneira a carregar o kernel para o endereço especificado em DESLOCAMENTO_KERNEL
	MOV DH, 15
	MOV DL, [BOOT_DRIVE]

	CALL disk_load
	RET


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

kernel_load DB "Carregando kernel na memoria...", 0

TIMES 510-($-$$) db 0
;TIMES 3536 db 0
DW 0xaa55
