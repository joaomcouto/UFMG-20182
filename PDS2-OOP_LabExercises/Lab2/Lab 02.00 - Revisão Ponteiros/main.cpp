#include <iostream>
#define SIZE 5


int main(){
    long value1=200000;
    long value2;
    long * long_ptr ;
    long_ptr = &value1;
    std::cout<<*long_ptr<< " ";

    value2 = *long_ptr ;
    std::cout<<value2<< " " ;


    std::cout<<long_ptr<< " " ;
    std::cout<<&value1<< " " ;
    std::cout<<((&value1) == (long_ptr))<< " " ;



    unsigned int values[SIZE] = {2,4,6,8,10} ;
    unsigned int * v_ptr ;
    int i ;
    for (i = 0 ; i < SIZE ; i++){
        std::cout<<values[i]<<" " ;
    }
    v_ptr = values ;
    v_ptr = &values[0] ;

    for ( ; *v_ptr <= 10 ; v_ptr += 1){
        std::cout<<*v_ptr<<" " ;
    }

  //  for ( ; *values <= 10 ; values = *(values + 1){
    //    std::cout<<*values<<std::endl ;

    //}


    for ( i = 0 ; i < SIZE; i++ ){
        std::cout<<*(values + i)<< " ";
    }
    v_ptr = values ;

    for ( i = 0 ; i < SIZE ; i++ ){
        std::cout<<v_ptr[i]<<" " ;
    }
    //15
    std::cout<<values[4]<<" " ;
    std::cout<<*(values+ 4) <<" " ;
    std::cout<<v_ptr[4] <<" " ;
    std::cout<<*(v_ptr+ 4) <<" " ;
    //14
    v_ptr = v_ptr + 3 ;
    std::cout<<&(v_ptr) <<" " ;
    v_ptr = values ;
    std::cout<<*(v_ptr+ 3) <<" " ;

    //15
    v_ptr = v_ptr - 4 ;
    std::cout<<&(v_ptr) <<" " ;
    v_ptr = &values[4] ;
    std::cout<<*(v_ptr -4 ) <<" " ;


    //imprima o valor do objeto apontado por long_ptr

    //Imprima o valor de value2

    //Imprima o endereço de value1

    //Imprima o endereço armazenado em long_ptr

    //Imprima a comparação entre o endereço de value1 com o endereço armazenado em long_ptr

    //imprimir os elementos do array values usando notação de array subscrito.

    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento.

    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento com o nome de array como o ponteiro.

    //imprimir os elementos do array values utilizando subscritos no ponteiro para o array.

    //imprimir o quinto elemento de values utilizando a notação de subscrito de array,

    //a notação de ponteiro/deslocamento com o nome de array como o ponteiro,

    //a notação de subscrito de ponteiro,

    //a notação de ponteiro/deslocamento.

    //imprimir a comparação entre o valor armazenado em (v_ptr-4) e values[0]

    return 0;
}
