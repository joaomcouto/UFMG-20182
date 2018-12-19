#include "posicao.h"

int Posicao::get_x() {
    return this->_x ;
}

int Posicao::get_y() {
    return this->_y ;
}

void Posicao::set_posicao(int x, int y){
    this->_x =  x;
    this->_y = y ;
}

Posicao::Posicao(int x, int y){
    this->_x = x ;
    this->_y = y ;
}


