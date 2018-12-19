#include <string>
#include "triangulo.h"
#include <math.h>



std::string Triangulo::get_cor(){return this->_cor ;} 

std::string Triangulo::get_nome(){return this->_nome ;} 

Triangulo::Triangulo(std::string cor, double aresta1, double aresta2, double aresta3){
    this->_nome = "triangulo" ;
    this-> _cor = cor ;
    this->_aresta1 = aresta1;
    this->_aresta2 = aresta2 ;
    this->_aresta3 = aresta3 ;
}

double Triangulo::get_area(){
    double semi = 0.5*(_aresta1 + _aresta2 + _aresta3) ;
    return (sqrt(semi*(semi - _aresta1)*(semi - _aresta2)*(semi - _aresta3))) ;
    
}


double Triangulo::get_perimetro(){
    return (_aresta1+_aresta2+_aresta3) ;
}