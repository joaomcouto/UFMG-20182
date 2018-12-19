#include "torre.h"

bool Torre::pode_mover(int x, int y){
    if(getPosicao().get_x() == x || getPosicao().get_y() == y) return true ;
    else return false;
}

Torre::Torre(int x, int y, std::string nome) : Peca(x,y,nome) {}