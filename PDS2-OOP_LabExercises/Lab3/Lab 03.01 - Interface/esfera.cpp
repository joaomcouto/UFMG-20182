#include <string.h>
#include "forma.h"
#include "forma3d.h"
#include "esfera.h"
#define PI 3.1415

Esfera::Esfera (std::string cor, double raio){
    this->_nome = "esfera" ;
    this->_cor = cor ;
    this->_raio = raio ;
}


std::string Esfera::get_cor(){return this->_cor ; } 


std::string Esfera::get_nome(){return this->_nome ; } 

double Esfera::get_volume(){return ((4/(double)3)*PI*_raio*_raio*_raio) ; }