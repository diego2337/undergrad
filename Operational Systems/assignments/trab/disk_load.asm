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
	
	mov dx, [0x9000]
	call print_hex
	mov dx, [0x9000+512]
	call print_hex
	ret

print2: MOV AL, [SI]
       INC SI
       CMP AL, 0
       JZ pend2
       MOV AH, 0x0E
       MOV BH, 0x00
       MOV BL, 0x07
       INT 0x10
       JMP print2
       pend2:
            ret

disk_error :
	mov SI , errormsg
	jmp print2
	ret

errormsg db "Erro na leitura do disco", 0
	
