.globl main
.data
msg1: .asciiz "Enter the string: "
string: .space 80

.text
main:

li $v0,4
la $a0,msg1
syscall

li $v0,8
la $a0,string
li $a1,80
syscall

li $t0,0

recursion:
lb $t1,string($t0)
beq $t1,0,exit
blt,$t1,'A',special
bgt $t1,'Z',toupper
addi $t1,$t1,32
sb $t1,string($t0)
addi $t0,$t0,1
j recursion

toupper:
blt $t1,'a',special
addi $t1,$t1,-32
sb $t1, string($t0)
addi $t0,$t0,1
j recursion

special:
addi $t0,$t0,1
j recursion

exit:
li $v0,4
la $a0,string
syscall

li $v0,10
syscall