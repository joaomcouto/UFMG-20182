#include <string>
#include "quadrado.h"


std::string Quadrado::get_cor(){
    return this->_cor ;
} 

std::string Quadrado::get_nome(){
    return this->_nome ;
} 

Quadrado::Quadrado(std::string cor, double lado){
    this->_nome = "quadrado" ;
    this->_cor = cor ;
    this->_lado = lado ;
}

double Quadrado::get_area(){
    return (this->_lado * this->_lado) ;
}


double Quadrado::get_perimetro(){
    return (this->_lado * 4) ;
}