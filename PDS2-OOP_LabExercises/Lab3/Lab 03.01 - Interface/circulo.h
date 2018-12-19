#ifndef CIRCULO_H
#define CIRCULO_H

#include <string>
#include "forma.h"
#include "forma2d.h"


class Circulo : public Forma2D {
private:
    std::string _cor;
    std::string _nome;
    double _raio ;
public: 
    Circulo(std::string cor, double raio);
    virtual std::string get_cor()  ;
    virtual std::string get_nome() ;
    virtual double get_area() override;
    virtual double get_perimetro() override ;
    
};

#endif


