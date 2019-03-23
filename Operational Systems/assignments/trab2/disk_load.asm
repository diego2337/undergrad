[BITS 16] ; Diz ao montador que o codigo e de 16 bits
[ORG 0x7c00] ; Avisa ao montador para montar as instrucoes no endereco 0x7c00, que e onde a BIOS
;ira procurar o bootloader

MOV [BOOT_DRIVE], DL
MOV BP, 0x8000
MOV SP, BP ; Essa instrucao poe a pilha fora da area onde vamos fazer a leitura do disco
MOV BX, 0x9000 ; Isso carregara 5 setores para 0x0000:0x9000
MOV DH, 5
MOV DL, [BOOT_DRIVE]

disk_load:
	PUSH DX ; Colocando esses valores na pilha, depois poderemos comparar para ver se o numero de setores verificados foi o mesmo que  requisitado (DH)
	MOV AH, 0x02 ; Funcao da BIOS de ler o setor
	MOV AL, DH ; Ler DH setores
	MOV CH, 0x00 ; Seleciona o cilindro 0
	MOV DH, 0x00 ; Seleciona a cabeca 0
	MOV CL, 0x02 ; Ele comecara a ler do setor seguinte ao setor de boot (segundo)
	INT 0x13
	JC disk_error ; Se a carry flag estiver setada, significa que ocorreu um erro
	POP DX ; Voltando o numero de setores para comparar com quantos foram lidos
	CMP DH, AL ; Caso AL (setores lidos) != DH (setores esperados)
	JNE disk_error
	; caso ele nao realize o pulo, entao a leitura foi feita com sucesso
	MOV SI, successmsg
	JMP print
	ret

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

;.DATA
BOOT_DRIVE: db 0
errormsg db "Erro na leitura do disco", 0
successmsg db "A leitura do disco foi bem sucedida!", 0
;TIMES 510 - ($ - $$) db 0 ; como o tamanho do bootloader deve ser EXATAMENTE 512 bytes, essa
;instrucao analisa o comeco do programa ($) ate o final ($$), preenchendo assim os espacos
;restantes
DW 0xAA55 ; a BIOS so ira ler esse arquivo como bootloader caso veja 0x55 e 0xAA


