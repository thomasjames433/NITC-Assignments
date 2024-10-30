.globl main
.data
msg1: .asciiz "Enter the number: "
msg2: .asciiz "Number is odd"
msg3: .asciiz "Number is even"

.text
main:

li $v0,4
la $a0,msg1
syscall

li $v0,5
syscall
move $t1,$v0

li $t2,2

div $t1,$t2
mfhi $t3
beq $t3,$zero even
j odd

even:
li $v0,4
la $a0,msg3
syscall
j exit

odd:
li $v0,4
la $a0,msg2
syscall

exit:
li $v0,10
syscall
 