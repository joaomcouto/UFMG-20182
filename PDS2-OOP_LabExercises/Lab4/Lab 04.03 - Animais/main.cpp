#include "Vaca.h"
#include "Cachorro.h"
#include <iostream>
#include <vector>

int main(void) {
    std::vector <Animal*> fazenda;
   // std::cout << "1" ;
    fazenda.push_back(new Vaca("marrom",10));
    // std::cout << "2" ;
    fazenda.push_back(new Cachorro("branco"));
    //std::cout << "3" ;
    //work

    fazenda[0]->faz_barulho();
    //std::cout << "444444 \n" ;
    popula(fazenda,fazenda[0],10);
    //std::cout << "5555555555555555555 \n" ;
    for(unsigned int i=0;i<fazenda.size();i++){
        std::cout<<fazenda[i]->get_id()<<std::endl;
    }
    
    /*Deve imprimir
    Muuu
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    */

}