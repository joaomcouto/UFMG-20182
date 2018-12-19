#ifndef CAVALO_H
#define CAVALO_H
#include "peca.h"

class Cavalo : public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Cavalo(int x, int y, std::string) ;

    
} ;


#endif