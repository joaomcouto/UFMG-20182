#ifndef PEAO_H
#define PEAO_H

#include "peca.h"

class Peao: public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Peao(int x, int y, std::string) ;

    
} ;




#endif
