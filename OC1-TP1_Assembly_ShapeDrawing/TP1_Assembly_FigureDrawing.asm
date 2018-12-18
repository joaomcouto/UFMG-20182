# O quadrado terá lado igual a 80
# O triângulo terá base igual a 80 e altura igual a 40
# O losango será composto de dois triângulos tais quais descritos anteriormente
# As formas serão desenhadas como se fossem inscritos em um quadrado, ou seja, o ponto (x0, y0) se refere ao canto superior esquerdo desse quadrado
# Os valores de x0 devem estar contidos no intervalo [0, 432], por conta da largura das formas
# Os valores de y0 devem estar contidos no intervalo [0. 176], por conta da altura das formas

.data
     mensagemForma: .asciiz "Por favor escolha:\n0 - Sair\n1 - Quadrado\n2 - Triângulo\n3 - Losango\n"
     mensagemXY:    .asciiz "Agora indique o X e o Y de início da figura:\n"
     mensagemCor:   .asciiz "Agora indique a cor:\n"
     mensagemErro:  .asciiz "\nValor Inválido\n"
     
.text
 main: 
     # Solicitando a forma a ser plotada (salvando em $t0)
     li $v0, 4
     la $a0, mensagemForma
     syscall
     
     li $v0, 5
     syscall
     add $s0, $zero, $v0
     
     # Caso o usuário digite 0, o programa acaba
     beq $s0, $zero, fimPrograma
     
     # Aqui teremos um loop caso os valores de x0 e y0 não estejam no intervalo correto do display
     loop_XY:
          # Solicitando o X e Y (salvando em $a1 e $a2, respectivamente)
          li $v0, 4
          la $a0, mensagemXY
          syscall
     
          li $v0, 5
          syscall
          add $a1, $zero, $v0
     
          li $v0, 5
          syscall
          add $a2, $zero, $v0
          
          # Verificando se os valores de x0 são válidos, ou seja, se x0 pertence ao intervalo [0, 432], pois será 512 - 80 (largura das figuras)
          slti $t0, $a1, 0
          bne $t0, $zero, displayErro
          
          sgtu $t0, $a1, 432
          bne $t0, $zero, displayErro
          
          # Verificando se os valores de y0 são válidos, ou seja, se y pertence ao intervalo [0, 176], pois será 256 - 80 (altura das figuras)
          slti $t0, $a2, 0
          bne $t0, $zero, displayErro
          
          sgtu $t0, $a2, 176
          bne $t0, $zero, displayErro
     
     # Solicitando a cor (salvando em $a3)
     li $v0, 4
     la $a0, mensagemCor
     syscall
     
     li $v0, 5
     syscall
     add $a3, $zero, $v0
     
     # Guardando em $a0, o endereço que o BitmapDisplay
     lui $a0, 0x1001
     
     # "Switch" para desenhar as formas
     beq $s0, 1, quadrado
     beq $s0, 2, triangulo
     beq $s0, 3, losango
     
# Printando um erro na tela
displayErro:
     la $a0, mensagemErro
     li $v0, 4
     syscall
     
     j main
     
# Chamada da função que desenha um quadrado
quadrado:
     jal desenhaQuadrado
     j main  
     
# Chamada da função que desenha um triângulo
triangulo:
     jal desenhaTrianguloNormal
     j main
     
# Chamada da função que desenha um losango
losango:
     jal desenhaLosango
     j main
     
# Fim do programa
fimPrograma:
     # Terminando nosso programa
     li $v0, 10
     syscall
     
# ----- ÁREA DOS PROCEDIMENTOS DE DESENHO ----- #
##### QUADRADO #####
# $a0 := endereço do BitmapDisplay; $a1 := x0; $a2 := y0; $a3 := cor
desenhaQuadrado:
     # Passando os valores de $a0, $a1 e $a2 para os registradores temporários $t0, $t1 e $t2
     move $t0, $a0
     move $t1, $a1
     move $t2, $a2
     
     # Definindo o tamanho do lado do nosso quadrado
     li $t3, 80

     # Multiplicando o valor de x0 por 4 (para quando somarmos com nosso ponteiro, sempre acessarmos valores múltiplos de 4)
     sll $t1, $t1, 2
     
     # Multiplicando o valor de y0 por 512*4 (mesma explicação do x0, mas dessa vez, cada linha possui 512 unidades)
     sll $t2, $t2, 11
     
     # Contador de linhas desenhadas
     li $t4, 0
     
loop_quadradoY:
     # Definindo um ponteiro para qual valor em Y estamos, começando no canto esquerdo
     move $t5, $t0
     
     # Movendo nosso ponteiro pela tela para desenharmos
     add $t5, $t5, $t1
     add $t5, $t5, $t2
     
     # Contador de pixels desenhados na linha
     li $t6, 0

# Procedimento que itera sobre as linhas
loop_desenhaQuadradoLinha:
     # Salvando o valor da cor na posição apontada pelo ponteiro
     sw $a3, 0($t5)
     
     # Movendo nosso ponteiro para a próxima posição e incrementando nosso contador 
     addi $t5, $t5, 4
     addi $t6, $t6, 1
     
     # Condicional que diz se chegamos no final da linha
     bne $t6, $t3, loop_desenhaQuadradoLinha
     
     # Passamos para a próxima linha e incrementamos nosso contador de linhas desenhadas
     addi $t0, $t0, 0x800
     addi $t4, $t4, 1
     
     # Condicional que diz se chegamos na última linha
     bne $t4, $t3, loop_quadradoY
     
     # Retornando para o procedimento que chamou desenhaQuadrado
     jr $ra
     

##### TRIÂNGULO NORMAL #####
# $a0 := endereço do BitmapDisplay; $a1 := x0; $a2 := y0; $a3 := cor
desenhaTrianguloNormal:
     # Passando os valores de $a0, $a1 e $a2 para os registradores temporários $t0, $t1 e $t2
     move $t0, $a0
     move $t1, $a1
     move $t2, $a2
     
     # Fazemos isso para termos um triângulo inscrito em um quadrado, onde os pontos dados pelo usuário será o canto superior esquerdo
     addi $t2, $t2, 80
     
     # Definindo o tamanho da base do nosso triângulo
     addi $t3, $a1, 80

     # Multiplicando o valor de x0 por 4 (para quando somarmos com nosso ponteiro, sempre acessarmos valores múltiplos de 4)
     sll $t1, $t1, 2
     
     # Multiplicando o valor de y0 por 512*4 (mesma explicação do x0, mas dessa vez, cada linha possui 512 unidades)
     sll $t2, $t2, 11
     
     # Multiplicando o valor da base por 4 (usaremos isso ao nosso favor para desenhar um triângulo)
     sll $t3, $t3, 2
     
loop_trianguloNormalY:
     # Definindo um ponteiro para qual valor em Y estamos, começando no canto esquerdo
     move $t4, $t0
     
     # Movendo nosso ponteiro pela tela para desenharmos
     add $t4, $t4, $t1
     add $t4, $t4, $t2
     
     # Contador de pixels desenhados na linha (começaremos com o valor de $a1)
     move $t5, $t1

# Procedimento que itera sobre as linhas
loop_desenhaTrianguloNormalLinha:
     # Salvando o valor da cor na posição apontada pelo ponteiro
     sw $a3, 0($t4)
     
     # Movendo nosso ponteiro para a próxima posição e incrementando nosso contador 
     addi $t4, $t4, 4
     addi $t5, $t5, 4
     
     # Condicional que diz se chegamos no final da linha
     bne $t5, $t3, loop_desenhaTrianguloNormalLinha
     
     # Passamos para a próxima linha, incrementamos $a1 em 4 unidades e decrementamos $t0 em 4 unidades (desenhando assim um triângulo aos poucos)
     subi $t0, $t0, 0x800
     addi $t1, $t1, 4
     subi $t3, $t3, 4
     
     # Condicional que diz se terminamos de desenhar o triângulo (no caso, se $a1 não for menor do que $t0)
     slt $t6, $t1, $t3
     bne $t6, $zero, loop_trianguloNormalY
     
     # Retornando para o procedimento que chamou desenhaQuadrado
     jr $ra
     

##### TRIÂNGULO INVERTIDO #####
# $a0 := endereço do BitmapDisplay; $a1 := x0; $a2 := y0; $a3 := cor
desenhaTrianguloInvertido:     
     # Passando os valores de $a0, $a1 e $a2 para os registradores temporários $t0, $t1 e $t2
     move $t0, $a0
     move $t1, $a1
     move $t2, $a2
     
     # Fazemos isso para termos um triângulo inscrito em um quadrado, onde os pontos dados pelo usuário será o canto superior esquerdo
     addi $t2, $t2, 80
     
     # Definindo o tamanho da base do nosso triângulo
     addi $t3, $a1, 80

     # Multiplicando o valor de x0 por 4 (para quando somarmos com nosso ponteiro, sempre acessarmos valores múltiplos de 4)
     sll $t1, $t1, 2
     
     # Multiplicando o valor de y0 por 512*4 (mesma explicação do x0, mas dessa vez, cada linha possui 512 unidades)
     sll $t2, $t2, 11
     
     # Multiplicando o valor da base por 4 (usaremos isso ao nosso favor para desenhar um triângulo)
     sll $t3, $t3, 2
     
loop_trianguloInvertidoY:
     # Definindo um ponteiro para qual valor em Y estamos, começando no canto esquerdo
     move $t4, $t0
     
     # Movendo nosso ponteiro pela tela para desenharmos
     add $t4, $t4, $t1
     add $t4, $t4, $t2
     
     # Contador de pixels desenhados na linha (começaremos com o valor de $a1)
     move $t5, $t1

# Procedimento que itera sobre as linhas
loop_desenhaTrianguloInvertidoLinha:
     # Salvando o valor da cor na posição apontada pelo ponteiro
     sw $a3, 0($t4)
     
     # Movendo nosso ponteiro para a próxima posição e incrementando nosso contador 
     addi $t4, $t4, 4
     addi $t5, $t5, 4
     
     # Condicional que diz se chegamos no final da linha
     bne $t5, $t3, loop_desenhaTrianguloInvertidoLinha
     
     # Passamos para a próxima linha, incrementamos $a1 em 4 unidades e decrementamos $t0 em 4 unidades (desenhando assim um triângulo aos poucos)
     addi $t0, $t0, 0x800
     addi $t1, $t1, 4
     subi $t3, $t3, 4
     
     # Condicional que diz se terminamos de desenhar o triângulo (no caso, se $a1 não for menor do que $t0)
     slt $t6, $t1, $t3
     bne $t6, $zero, loop_trianguloInvertidoY
     
     # Retornando para o procedimento que chamou desenhaQuadrado
     jr $ra
     

##### LOSANGO #####
# $a0 := endereço do BitmapDisplay; $a1 := x0; $a2 := y0; $a3 := cor
desenhaLosango:
     # Salvando o valor do endereço de retorno na pilha
     sw $ra, 0($sp)
     
     # Linha espercífica para o desenho de um losango (desenhar dois triângulo no meio do quadrado)
     subi $a2, $a2, 40     
     
     # Chamada dos procedimentos que desenham os triângulos para formar o losango
     jal desenhaTrianguloNormal     
     jal desenhaTrianguloInvertido
     
     # Recuperando o valor de retorno e retornando
     lw $ra, 0($sp)
     jr $ra
