#include "bispo.h"

bool Bispo::pode_mover(int x, int y){
    if( abs(getPosicao().get_x() - x) == abs(getPosicao().get_y() - y) ) return true;
    else return false ;

}

Bispo::Bispo(int x, int y, std::string nome) : Peca(x,y,nome) {}