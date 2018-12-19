#include "rainha.h"

bool Rainha::pode_mover(int x, int y){
    if(this->getPosicao().get_x() == x || this->getPosicao().get_y() == y) return true;
    else if(abs(getPosicao().get_x() - x) == abs(getPosicao().get_y() - y)) return true;
    else return false;

}

Rainha::Rainha(int x, int y, std::string nome) : Peca(x,y,nome) {}