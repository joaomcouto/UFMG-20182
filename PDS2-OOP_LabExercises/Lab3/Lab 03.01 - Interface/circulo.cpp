#include <string>

#include "forma.h"
#include "forma2d.h"
#include "circulo.h"

#define PI 3.1415

std::string Circulo::get_cor(){return this->_cor ;} 

std::string Circulo::get_nome(){return this->_nome ;} 

Circulo::Circulo(std::string cor, double raio){
    this->_nome = "circulo" ;
    this->_cor = cor ;
    this->_raio = raio ;
}

double Circulo::get_area(){
    return (PI*_raio*_raio) ;
}


double Circulo::get_perimetro(){
    return (2* PI * _raio) ;
}