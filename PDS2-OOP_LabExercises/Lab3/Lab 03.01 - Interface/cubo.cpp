#include <string.h>
#include "forma.h"
#include "forma3d.h"
#include "cubo.h"


Cubo::Cubo (std::string cor, double aresta){
    this->_nome = "cubo" ;
    this->_cor = cor ;
    this->_aresta = aresta ;
}


std::string Cubo::get_cor(){return this->_cor ; } 


std::string Cubo::get_nome(){return this->_nome ; } 

double Cubo::get_volume(){return (_aresta*_aresta*_aresta) ; }