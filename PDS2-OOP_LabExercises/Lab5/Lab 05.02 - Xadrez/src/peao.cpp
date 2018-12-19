#include "peao.h"

bool Peao::pode_mover(int x, int y){
    if(getPosicao().get_y() == y && (abs(x - getPosicao().get_x() == 1))) return true;
    return false ;

}

Peao::Peao(int x, int y, std::string nome) : Peca(x,y,nome) {}