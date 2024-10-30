.globl main
.data
msg1: .asciiz "Enter number: "
msg2: .asciiz "Factorial is "

.text
main:

li $v0,4
la $a0,msg1
syscall

li $v0,5
syscall
move $t0,$v0

li $t1,1

factorial:
beq $t0,$zero,exit
mul $t1,$t0,$t1
addi $t0,$t0,-1


j factorial


exit:
li $v0,4
la $a0,msg2
syscall

li $v0,1
move $a0,$t1
syscall

li $v0,10
syscall
