#ifndef BISPO_H
#define BISPO_H
#include "peca.h"

class Bispo : public Peca{
    public: 
    bool pode_mover(int x, int y) override ;
    Bispo(int x, int y, std::string nome);

    
} ;


#endif