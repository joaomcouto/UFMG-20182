#include "aquecedor.h"

Aquecedor::Aquecedor(){
    _temperatura = 20 ;
    _tempmax = 40;
    _tempmin = 10;
    _fator = 5 ;
}


Aquecedor::Aquecedor(double inicial) {
    this->_temperatura = inicial ;
}


Aquecedor::Aquecedor(double inicial, double fator){
    this->_temperatura = inicial ;
    this->_fator = fator;
}

void Aquecedor::aquecer(){
    if(     (_temperatura + this->_fator) <= (_tempmax)     ){
        this->_temperatura += _fator ;
    }
}
    
void Aquecedor::resfriar(){
    if(      (_temperatura - this->_fator)  >= _tempmin      ){
         this->_temperatura  -= this->_fator ;
    }
   
}


    
    
double Aquecedor::get_temperatura(){
    return this->_temperatura ;
}

