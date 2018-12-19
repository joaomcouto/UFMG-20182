#ifndef PECA_H
#define PECA_H
#include "posicao.h"
#include <string>


class Peca{
    protected:
        Posicao _posicao ;
        std::string _nome;

    public:
        Peca(int x, int y, std::string nome);
        virtual ~Peca();
        virtual bool pode_mover(int x, int y) = 0 ;
        std::string getNome();
        void move(int x, int y);
        Posicao getPosicao(); 


};

#endif