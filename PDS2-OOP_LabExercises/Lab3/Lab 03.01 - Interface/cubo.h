#ifndef CUBO_H
#define CUBO_H

#include <string> 
#include "forma.h"
#include "forma3d.h"




class Cubo : public Forma3D {
private:
    double _aresta ;
    std::string _nome ;
    std::string _cor;
public:
    Cubo(std::string cor , double aresta) ; 
    virtual std::string get_cor() ;
    virtual std::string get_nome() ;
    virtual double get_volume() ;
    
    
} ;


#endif