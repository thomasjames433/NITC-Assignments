.data
intarr: .space 80
spc: .asciiz " "
.text
main:
li $t0,0

getint:

li $v0,5
syscall

sw $v0,intarr($t0)
beq $v0,0,exit
addi $t0,$t0,4
j getint



exit:
li $t0,0
print:
li $v0,1
lw $a0,intarr($t0)
beq $a0,0,exit2

syscall
li $v0,4
la $a0,spc
syscall
addi $t0,$t0,4
j print

exit2:
li $v0,10
syscall

