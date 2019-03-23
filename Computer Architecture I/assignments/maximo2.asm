# Programa Maximo.asm:
#	Encontra o elemento maximo de um vetor a de n elementos (n > 0).

# Resultado : Memoria[60 61 62 63] = 78

# Algoritmo:
#	maximo := a[0]
#	para i := 1 ate n - 1 faca
#		se maximo < a[i] entao
#			maximo := a[i]

# Registradores usados:
#	$t0 - i
#	$t1 - endereco de a[i]
#	$t2 - maximo
#	$t3 - n
#	$t4 - a[i]
#	$t5 - resultado de (maximo < a[i])

.text
add $t0, $zero,	$zero # i = 0
addi $t1, $gp, 8 # $t1 = endereco inicial de a
lw $t2,	0($t1) # maximo = a[0]
lw $t3,	n($gp) # $t3 = n
loop: 
	addi $t0, $t0, 1 # i = i + 1
	beq $t0, $t3, fim_loop # se i = n entao sai do loop
	addi $t1, $t1, 4 # $t1 = endereco de a[i]
	lw $t4,	0($t1) # $t4 = a[i]
	slt $t5, $t2, $t4 # se maximo >= a[i] entao
	beq $t5, $zero,	nao_muda # desvia para nao_muda
	add $t2, $t4, $zero # maximo = a[i]
	nao_muda:
		j loop # volta para inicio do loop

fim_loop: 
	sw $t2, maximo($gp) # maximo = $t2
	addi $v0, $zero, 10
	syscall

.data
n: 6
maximo: 0
a: 50 # vetor de n elementos
   33
   50
   51
   49
   78
