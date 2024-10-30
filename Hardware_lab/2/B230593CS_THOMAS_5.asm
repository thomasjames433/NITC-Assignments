.data
msg1: .asciiz "Enter number 1: "
msg2: .asciiz "Enter number 2: "
mnot: .asciiz "Not prime" 
mis: .asciiz "Is prime"

.text
main:

li $v0,4
la $a0,msg1
syscall

li $v0,5
syscall
move $t0,$v0

li $v0,4
la $a0,msg2
syscall

li $v0,5
syscall
move $t1,$v0

add $t0,$t0,$t1

beq $t0,2,is

li $t1,2

isprime:
div $t0,$t1
mfhi $t3
mflo $t2
beq $t3,0,not
ble $t2,$t1,is
addi $t1,$t1,1

j isprime

not:
li $v0,4
la $a0,mnot
syscall

li $v0,10
syscall

is:
li $v0,4
la $a0,mis
syscall

li $v0,10
syscall
