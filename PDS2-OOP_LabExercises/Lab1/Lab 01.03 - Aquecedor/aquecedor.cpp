#include "aquecedor.h"

Aquecedor::Aquecedor(){
    _temperatura = 20 ;
}

void Aquecedor::aquecer(){
    this->_temperatura += 5 ;
}
    
void Aquecedor::resfriar(){
    this->_temperatura  -= 5 ;
}
    
    
    
double Aquecedor::get_temperatura(){
    return this->_temperatura ;
}

    