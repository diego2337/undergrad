; TRABALHO DE LM - SIMON GAME
; ALUNOS: Aimee Sousa Calepso, Arthur Frederico Neves, Diego Cintra, Mariana Caravanti, 
; Nicolas Roque dos Santos, Ricardo Masao Kondo e Rogerio Sandim


include 'emu8086.inc' 

.MODEL medium

.STACK 512d  
                                                                     
.DATA                                                                

; Inicio0 - Inici13: Conjunto de strings titulo do jogo

Inicio DW 0Ah, " ***************************************************", 0Dh, 0Ah, 024h
Inici2 DW "*                                                 *", 0Dh, 0Ah, 024h
Inici3 DW "*  ### # #   #  ##  #   #     ###   #   #   # ### *", 0Dh, 0Ah, 024h          
Inici4 DW "* #    # ## ## #  # ##  #    #     # #  ## ## #   *", 0Dh, 0Ah, 024h             
Inici5 DW "*  ##  # # # # #  # # # #    # ## ##### # # # ##  *", 0Dh, 0Ah, 024h              
Inici6 DW "*    # # #   # #  # #  ##    #  # #   # #   # #   *", 0Dh, 0Ah, 024h        
Inici7 DW "* ###  # #   #  ##  #   #     ##  #   # #   # ### *", 0Dh, 0Ah, 024h                   
Inici8 DW "*                                                 *", 0Dh, 0Ah, 024h
Inici9 DW "***************************************************", 0Dh, 0Ah, 024h
           
           
Inici10 DW "Alunos: Aimee S. Calepso, Arthur F. Neves, Diego Cintra,", 0Dh, 0Ah, 024h
Inici11 DW "Mariana Caravanti, Nicolas Roque e Ricardo Kondo.", 0Dh, 0Ah, 024h
Inici12 DW "Baseado no jogo eletronico Simon, da Hasbro Inc.", 0Dh, 0Ah, 024h
          
          
Inici13 DW "Pressione qualquer tecla para iniciar.", 0Dh, 0Ah, 024h

; Padrao - Level2: Selecao do nivel do jogo

Padrao DW " Faca o que Simon faz... Siga o padrao enquanto voce puder...", 0Dh, 0Ah, 024h
Padrao2 DW "Se voce puder!!!", 0Dh, 0Ah, 024h
Level DW "Escolha um nivel de dificuldade: Para facil, tecle 0. Para dificil, tecle 1", 0Dh, 0Ah, 024h
Level2 DW "  Comando invalido. Tente novamente", 0Dh, 0Ah, 024h 


counter DW 0d  
counter2 DW 0d 
string DB 0Dh, 0Ah, 'Repita a sequencia em ordem. ', 0Dh, 0Ah, 024h  
Text DB "Sequencia correta! ", 0Dh, 0Ah, 024h
Text2 DB "Sequencia incorreta... Tente novamente ", 0Dh, 0Ah, 024h 
Text3 DB "Quer continuar tentando? y/n ", 0Dh, 0Ah, 024h
Array DB 100 DUP (?) 

.CODE   
mov ax, @DATA
mov ds, ax 
mov ax, @DATA 	; programa ax com o segmento de dados
mov es,ax 		; coloca em es 
mov bx, 1d 

; a tela inicial do jogo

mov ah, 09h
lea dx, Inicio
int 21h       
lea dx, Inici2
int 21h 
lea dx, Inici3
int 21h       
lea dx, Inici4
int 21h
lea dx, Inici5
int 21h      
lea dx, Inici6
int 21h      
lea dx, Inici7
int 21h      
lea dx, Inici8
int 21h      
lea dx, Inici9
int 21h      
lea dx, Inici10
int 21h        
lea dx, Inici11
int 21h       
lea dx, Inici12
int 21h      
lea dx, Inici13
int 21h 
mov ah, 01h
int 21h 

CALL CLEAR_SCREEN

; escolha o nivel de dificuldade

mov ah, 09h
lea dx, Padrao
int 21h
lea dx, Padrao2
int 21h
WRONG:
lea dx, Level
int 21h
mov ah, 01h
int 21h
cmp al, '0'
je EASY
cmp al, '1'
je HARD 
CALL CLEAR_SCREEN
mov ah, 09h
lea dx, Level2
int 21h
jmp WRONG

; -------------------------------------------------------------------------------------------
; modo facil de jogo - EASY 
CALL CLEAR_SCREEN

EASY:

sloop: 
mov counter, 0d 
; o counter indica aonde no vetor iremos armazenar o novo numero da sequencia.
; perceba que a chamada 'sloop' sempre acontece para recomecar desde o inicio a sequencia - 
; por isso, o counter e inicializado aqui
mov counter2, 0d  ; explicaremos a utilidade do counter2 mais adiante no codigo
; inicializando os contadores com 0
mov cx, 0d 
mov bx, 0d

sequencia:
CALL random
cmp dl, 94d ; corresponde a '^' na tabela ascii 
je fixups
cmp dl, 33d ; caso o numero aleatorio seja menor que 33, iremos ajusta-lo para poder ser digitado
jl fixup
volta:
cmp dl, 125d ; mesmo ajuste, mas para o caso dele ser maior que 125
jg fixup2
volta2:

mov bx, counter ; como dito previamente, a posicao no vetor para o novo numero
mov Array[bx], dl 
inc bx    
mov cx, bx
mov bx, 0d ; para podermos mostrar a string, precisamos de um for - e o acesso as posicoes so
; pode ser feito pelo bx. portanto passamos a posicao para cx

print:
CALL CLEAR_SCREEN
mov dl, Array[bx]
mov ah, 02h
int 21h 
inc bx 
CALL espera  ; o diferencial do EASY e a funcao espera, que faz com que o jogador possa ver
; por um numero maior de tempo o novo numero da sequencia
cmp bx, cx  ; condicao do 'for' previamente mencionado
jne print  
    
mov counter2, cx  ; o counter2 sera utilizado como um comparador para o bx - por isso, subtraimos
; 1 de seu total
sub counter2, 1d 
;mov cx, counter
inc counter ; agora que temos um novo numero, a sequencia e incrementada
  
 
CALL CLEAR_SCREEN    

; mensagem para imprimir a sequencia em ordem
     
lea dx, string
mov ah, 09h
int 21h 
mov bx, -1d 

simon:     
inc bx
mov ah, 01h
int 21h 
cmp al, Array[bx]
jne errado       
cmp bx, counter2 ; se nao ouve desvio para errado, comparamos o bx para saber em que posicao
; ele esta - caso ele esteja na ultima, desviamos para certo
je certo
jne simon   

fixups:          ; e necessario uma adicao menor caso o numero gerado seja 94d
add dl, 15d
jmp volta
          
fixup:
add dl, 50d
jmp volta

fixup2:
sub dl, 50d
jmp volta2  

; decision e chamado caso o jogador acerte e deseja continuar jogando
 
decision PROC NEAR 

lea dx, Text3  
mov ah, 09h 
int 21h
mov ah, 01h
int 21h
cmp al, 'y'
je sequencia
jne thend
decision ENDP       

; ja decision2 ocorre quando ele erra a sequencia e deseja recomecar desde o inicio

decision2 PROC NEAR
lea dx, Text3  
mov ah, 09h 
int 21h
mov ah, 01h
int 21h
cmp al, 'y'
je sloop
jne thend
decision2 ENDP


; random - funcao que gera o numero aleatorio a ser inserido na sequencia

random PROC NEAR
 mov ah, 2ch  ; Set function code
 int 21h      ; armazena o tempo do MS-DOS
 mov ax, dx   ; DH=segundos, DL=centesimos de segundo
 mov dl, al
 and dh, 00h
 mov ah, 02h
 ret        
random ENDP


certo:


lea bp,Text 	
mov ah,13h 		; fundo 13 - escrever string
mov al,01h 		; atributo em al para mover cursor
xor bh,bh 		; pagina de video
mov bl,1 		; Linha que decide a cor que sera utilizada. Ex: verde:10
                ; rosa: 5 
                ; vermelho: 4 
                ; cinza: 8, azul: 1
                ; verde: 2  
                ; cores com fundo a partir do 16
                
mov cx,19		; comprimento da string
mov dh,5 		; linha para colocar a string
mov dl,5 		; coluna para colocar a string
int 10h 		


CALL decision

errado:


lea bp, Text2 	
mov ah,13h 		; fundo 13 - escrever string
mov al,01h 		; atributo em al para mover cursor
xor bh,bh 		; pagina de video
mov bl,4 		; Linha que decide a cor que sera utilizada. Ex: verde:10
                ; rosa: 5 
                ; vermelho: 4 
                ; cinza: 8, azul: 1
                ; verde: 2  
                ; cores com fundo a partir do 16
                
mov cx,41 		; comprimento da string
mov dh,5 		; linha para colocar a string
mov dl,5 		; coluna para colocar a string
int 10h 		


CALL decision2  


thend:

int 20h 
jmp toend ; chama toend que esta no final do codigo - e onde CLEAR_SCREEN esta definida e onde
; o codigo termina (instrucao 'end')
hlt 
 

; --------------------------------------------------------------------------------------------
; modo dificil de jogo - HARD     
; as mesmas funcoes do modo EASY estao presentes no modo HARD, portanto dispensam comentarios
CALL CLEAR_SCREEN

HARD:

slooph: 
mov counter, 0d
mov counter2, 0d
mov cx, 0d
mov bx, 0d

sequenciah:
CALL randomh
cmp dl, 94d ; corresponde a '^' na tabela ascii 
je fixupsh
cmp dl, 33d
jl fixuph
voltah:
cmp dl, 125d
jg fixup2h
volta2h:

mov bx, counter
mov Array[bx], dl 
inc bx   
;cmp cx, counter
;jne sequencia   
mov cx, bx
mov bx, 0d 
printh:

CALL CLEAR_SCREEN
mov dl, Array[bx]
mov ah, 02h
int 21h 
inc bx
cmp bx, cx
jne printh  
;mov bx, cx     
mov counter2, cx
sub counter2, 1d 
mov cx, counter
inc counter  
  
 
CALL CLEAR_SCREEN    
      
lea dx, string
mov ah, 09h
int 21h 
mov bx, -1d 

simonh:     

inc bx
mov ah, 01h
int 21h
;and ah, 00h 
cmp al, Array[bx]
jne erradoh       
cmp bx, counter2
je certoh
jne simonh   

fixupsh:
add dl, 20d
jmp voltah
          
fixuph:
add dl, 50d
jmp voltah

fixup2h:
sub dl, 50d
jmp volta2h
 
decisionh PROC NEAR
lea dx, Text3  
mov ah, 09h 
int 21h
mov ah, 01h
int 21h
cmp al, 'y'
je sequenciah
jne thendh
decisionh ENDP       


decision2h PROC NEAR
lea dx, Text3  
mov ah, 09h 
int 21h
mov ah, 01h
int 21h
cmp al, 'y'
je slooph
jne thendh
decision2h ENDP



randomh PROC NEAR
 mov ah, 2ch  ; Set function code
 int 21h      ; get time from MS-DOS
 mov ax, dx   ; DH=seconds, DL=hundredths of second
 ;and ax, 0fh  ; keep only the 4 last bits of the hundredth of seconds 
 mov dl, al
 and dh, 00h
 mov ah, 02h
 ;int 21h
 ret        
randomh ENDP


certoh:

;mov ax,@data 	; programa ax com o segmento de dados
;mov es,ax 		; coloca em es

lea bp,Text 	; ES:BP aponta para a mensagem
mov ah,13h 		; fundo 13 - escrever string
mov al,01h 		; atributo em bl,move cursor
xor bh,bh 		; pagina de video
mov bl,1 		; >>Linha que decide a cor que sera utilizada. Ex: verde:10
                ;   rosa: 5 
                ;   vermelho: 4 
                ;   cinza: 8, azul: 1
                ;   verde: 2  
                ;   cores com fundo a partir do 16
                
mov cx,19 		; comprimento da string
mov dh,5 		; linha para colocar a string
mov dl,5 		; coluna para colocar a string
int 10h 		; chamada de serviço bios

;mov ax,4C00h    ; retornar para o DOS
;int 21h

CALL decisionh

erradoh:

;mov ax,@data 	; programa ax com o segmento de dados
;mov es,ax 		; coloca em es

lea bp, Text2 	; ES:BP aponta para a mensagem
mov ah,13h 		; fundo 13 - escrever string
mov al,01h 		; atributo em bl,move cursor
xor bh,bh 		; pagina de video
mov bl,4 		; >>Linha que decide a cor que sera utilizada. Ex: verde:10
                ;   rosa: 5 
                ;   vermelho: 4 
                ;   cinza: 8, azul: 1
                ;   verde: 2  
                ;   cores com fundo a partir do 16
                
mov cx,41 		; comprimento da string
mov dh,5 		; linha para colocar a string
mov dl,5 		; coluna para colocar a string
int 10h 		; chamada de serviço bios

;mov ax,4C00h    ; retornar para o DOS
;int 10h

CALL decision2h  


thendh:

int 20h 
jmp toend 
hlt   
          

; tudo que a funcao espera faz e criar um loop que dure uma quantidade consideravel de tempo,
; permitindo o jogador ver por mais tempo o numero na tela

espera: 
    And AX, 0000h
    And DX, 0000h
    MOV AX, -1h
    MOV DX, 50h
    espera2:
    inc AX
    CMP AX, DX
    jne espera2
    ret
         
toend:
    DEFINE_CLEAR_SCREEN
    end  ; fim do programa