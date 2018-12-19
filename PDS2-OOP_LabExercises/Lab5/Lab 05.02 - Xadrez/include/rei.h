#ifndef REI_H
#define REI_H
#include "peca.h"

class Rei : public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Rei(int x, int y, std::string) ;

    
} ;


#endif