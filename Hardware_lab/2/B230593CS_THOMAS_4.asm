.data
msg1: .asciiz "Enter string: "
pal: .asciiz "Is Palindrome"
npal: .asciiz "Not Palindrome"
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
li $t1,0

count:
lb $t2,string($t0)
beq $t2,10,change
addi $t0,$t0,1
j count

change:
addi $t0,$t0,-1

check:

bge $t1,$t0, exiteq
lb $t2,string($t0)
lb $t3,string($t1)
bne $t2,$t3,exitneq
addi $t1,$t1,1
addi $t0,$t0,-1
j check

exiteq:

li $v0,4
la $a0,pal
syscall

li $v0,10
syscall

exitneq:
li $v0,4
la $a0,npal
syscall

li $v0,10
syscall