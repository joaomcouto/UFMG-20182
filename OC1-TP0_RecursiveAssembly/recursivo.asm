.data
	#Atividade 1 - OC1 METODO RECURSIVO
	#Aluno: João Marcos Machado Couto 
	virg:             .asciiz ", "
	slashn:            .asciiz "\n"
.text

main:
	li $v0, 5
	syscall
	add $a0, $zero, $v0
	
	addi $t3, $zero, 2
	div $a0, $t3
	mfhi $t3
	beq $t3, $zero, continue
	addi $a0, $a0, -1
	
continue:	
	add $s1, $zero, $a0 #salva o n inicial
	jal recursivesquares
	li $v0, 4
	la $a0, slashn
	syscall
	li $v0, 1       
	move $a0, $s0
	syscall 
	li $v0, 10
	syscall
	
recursivesquares: 
	addi $sp, $sp, -8 #desloca o stack pointer inicialmente a fim de reserva espaco para os primeiros numero e ra
	sw $ra, 4($sp)
	sw $a0, 0($sp)
	sgt $t0, $a0, 1
	bne $t0, $zero, L1
	addi $v0, $zero, 0
	addi $sp, $sp, 8 #no caso de nao causar o branch, movemos o stack pointer para frente novamente em vista de que o espaco nao foi utlizado por novos empilhamentos
	jr $ra
L1:
	addi $a0, $a0, -2 # n= n -2
	jal recursivesquares
	lw $ra, 4($sp)
	lw $a0, 0($sp) 
	add $t2,$zero, $a0 #guarda o valor do a0 atual para fins de saber se deve-se imprimir ou nao a virgula (nao no 
	addi $sp, $sp, 8 #desloca o stack pointer 8 posicoes, possibilitante desempilhar todos os enderecos e numeros empilhados em sequenc
	mul $t1, $a0, $a0 #t1 = quadrado do n atual
	li $v0, 1       #Imprime o quadrado do n atual
	move $a0, $t1
	syscall 
	
	bne $t2,$s1, virgula
	j proximo
virgula:
	li $v0, 4
	la $a0, virg
	syscall
proximo:	
	add $s0, $s0, $t1
	jr $ra
	
	
	
	
	 
		
	
		

	
