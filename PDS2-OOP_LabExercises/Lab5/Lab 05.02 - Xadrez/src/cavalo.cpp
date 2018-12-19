#include "cavalo.h"

bool Cavalo::pode_mover(int x, int y){
    if( (abs(getPosicao().get_x() -x) == 1) && (abs(getPosicao().get_y()-y) ==2) ) return true ;

    if( (abs(getPosicao().get_x() == 2)) && (abs(getPosicao().get_y()-y) == 1)  ) return true;
    return false ; 
}

Cavalo::Cavalo(int x, int y, std::string nome) : Peca(x,y,nome) {}