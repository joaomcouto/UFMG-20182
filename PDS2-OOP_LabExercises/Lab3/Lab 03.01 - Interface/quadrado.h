#ifndef QUADRADO_H
#define QUADRADO_H

#include <string>
#include "forma.h"
#include "forma2d.h"




class Quadrado : public Forma2D {
private:
    std::string _cor;
    std::string _nome;
    double _lado ;
public: 
    Quadrado(std::string cor, double lado);
    virtual std::string get_cor()  ;
    virtual std::string get_nome() ;
    virtual double get_area() ;
    virtual double get_perimetro() ;
    
    
};

#endif


