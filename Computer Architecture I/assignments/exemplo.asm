.text
lw $t0, a($gp)
addi $t0, $t0, 2
sw $t0, b($gp)
lw $t1, b($gp)
addi $v0, $zero, 10
syscall
.data
a: 10
b: 0
