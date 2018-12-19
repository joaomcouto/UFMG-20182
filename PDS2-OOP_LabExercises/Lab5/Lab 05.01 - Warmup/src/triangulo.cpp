#include "triangulo.h"
#include <stdexcept>
#include "excecoes.h"

Triangulo::Triangulo(double x, double y, double z){
    if (x <= 0 || y <= 0 || z <= 0 ) throw TrianguloInvalidoException();
    if (x+y <= z || x+z <= y || z+y <= x) throw TrianguloInvalidoException();
    if (_x < 0 || _y <0 || _z <0 ) throw TrianguloInvalidoException();
    this->_x = x ;
    this->_y = y ;
    this->_z = z ; 
}

Tipo Triangulo::determinar_tipo(){
    if ((_x == _y) && (_y == _z)) return EQUILATERO ;
    else if ( (_x != _y) && (_x != _z) && (_z != _y)) return ESCALENO ;
    else return ISOSCELES ;
   
}