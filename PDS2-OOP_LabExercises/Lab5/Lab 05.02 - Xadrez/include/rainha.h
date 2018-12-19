#ifndef RAINHA_H
#define RAINHA_H

#include "peca.h"



class Rainha: public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Rainha(int x, int y, std::string) ;

    
} ;

#endif

