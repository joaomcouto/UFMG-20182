#ifndef TORRE_H
#define TORRE_H
#include "peca.h"

class Torre : public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Torre(int x, int y, std::string) ;

    
} ;

#endif