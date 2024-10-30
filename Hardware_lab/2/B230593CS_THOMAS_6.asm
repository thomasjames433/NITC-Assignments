.data
msg1: .asciiz "Enter binary number: "
string: .space 50

.text
main:
li $v0,4
la $a0,msg1
syscall

li $v0,8
la $a0,string
li $a1,50
syscall

li $t0,0
li $t2,0
lb $t1,string($t0)

getnum:

addi $t1,$t1,-48
add $t2,$t2,$t1
addi $t0,$t0,1

lb $t1,string($t0)
beq $t1,'\n',exit
beq $t1,0,exit
mul $t2,$t2,2

j getnum

exit:
li $v0,1
move $a0,$t2
syscall

li $v0,10
syscall

