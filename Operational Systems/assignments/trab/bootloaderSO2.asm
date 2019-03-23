[BITS 16] ; Diz ao montador que o codigo e de 16 bits
ORG 0x7c00 ; Avisa ao montador para montar as instrucoes no endereco 0x7c00, que e onde a BIOS
;ira procurar o bootloader 


MOV [BOOT_DRIVE] , DL ; BIOS stores our boot drive in DL , so it ’s best to remember this for later.
MOV BP , 0x8000
MOV SP , BP ; Here we set our stack safely out of the way , at 0 x8000
MOV BX , 0x9000 ; Load 5 sectors to 0x0000 ( ES ):0 x9000 ( BX )
MOV DH , 5 ; from the boot disk.
MOV DL , [BOOT_DRIVE]	

disk_load:
	push dx ; Store DX on stack so later we can recall  how many sectors were request to be read, even if it is altered in the meantime
	MOV AH, 0x02 ; BIOS read sector function
	mov al , dh ; Read DH sectors
	mov ch , 0x00 ; Select cylinder 0
	mov dh , 0x00 ; Select head 0
	mov cl , 0x02 ; Start reading from second sector ( i.e. after the boot sector )
	int 0x13 ; BIOS interrupt
	jc disk_error ; Jump if error ( i.e. carry flag set )
	pop dx ; Restore DX from the stack
	cmp dh , al ; if AL ( sectors read ) != DH ( sectors expected )
	jne disk_error 
	
	mov SI, successmsg
	jmp print
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

disk_error :
	mov SI , errormsg
	jmp print
	ret
    
;.DATA
BOOT_DRIVE db 0
errormsg db "Erro na leitura do disco", 0
successmsg db "A leitura do disco foi bem sucedida!", 0
TIMES 131 - ($ - $$) db 0 ; como o tamanho do bootloader deve ser EXATAMENTE 512 bytes, essa 
;instrucao analisa o comeco do programa ($) ate o final ($$), preenchendo assim os espacos
;restantes
DW 0xAA55 ; a BIOS so ira ler esse arquivo como bootloader caso veja 0x55 e 0xAA 
times 256 dw 0xdada
times 256 dw 0xface 


