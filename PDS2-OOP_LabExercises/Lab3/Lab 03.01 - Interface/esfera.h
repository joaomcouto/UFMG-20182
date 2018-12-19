#ifndef ESFERA_H
#define ESFERA_H

#include <string>
#include "forma.h"
#include "forma3d.h"


class Esfera : public Forma3D {
private:
    double _raio ;
    std::string _nome ;
    std::string _cor;
public:
    Esfera(std::string cor , double raio) ; 
    virtual std::string get_cor() ;
    virtual std::string get_nome() ;
    virtual double get_volume() ;
    
    
} ;


#endif