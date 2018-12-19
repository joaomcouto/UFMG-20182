#ifndef TRIANGULO_H
#define TRIANGULO_H


#include <string>
#include "forma2d.h"
#include "forma.h"



class Triangulo : public Forma2D {
private:
    std::string _cor;
    std::string _nome;
    double _aresta1;
    double _aresta2;
    double _aresta3;
public: 
    Triangulo(std::string nome, double aresta1, double aresta2, double aresta3);
    virtual std::string get_cor() ;
    virtual std::string get_nome() ;
    virtual double get_area() ;
    virtual double get_perimetro()  ;
    
};

#endif


