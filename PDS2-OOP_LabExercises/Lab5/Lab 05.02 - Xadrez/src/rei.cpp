#include "rei.h"

bool Rei::pode_mover(int x, int y){
    if( abs(getPosicao().get_x() - x) == 1 && getPosicao().get_y() == y) return true;
    if( abs(getPosicao().get_y() - y) == 1 && getPosicao().get_x() == x) return true;
    if( abs(getPosicao().get_x() - x) == 1 && abs(getPosicao().get_y() - y) == 1) return true;
    return false ;

}

Rei::Rei(int x, int y, std::string nome) : Peca(x,y,nome) {}