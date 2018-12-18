.data 
	#Atividade 1 - OC1 METODO ITERATIVO
	#Aluno: João Marcos Machado Couto 
	space:             .asciiz " "
	slashn:            .asciiz "\n"
.text	
	li $v0, 5
	syscall
	add $s0, $zero, $v0 #s0 = n
	addi $t1, $zero, 2 #t1 = i
loop:
	bgt $t1,$s0,printing
	mul $t2,$t1,$t1 #t2 = quadrado de i
	add $s1,$s1,$t2 #s1 = soma dos quadrados
	li $v0, 1       #Imprime o quadrado do i atual
	move $a0, $t2
	syscall         
	li $v0, 4	
	la $a0, space
	syscall
	addi $t1, $t1, 2 #incrementa o i em 2
	j loop	
printing:
	li $v0, 4
	la $a0, slashn
	syscall
	li $v0, 1
	move $a0, $s1
	syscall
	
