#include "peca.h"
#include "excecoes.h"

Peca::Peca(int x, int y, std::string nome) : _posicao(x,y){ 
    _nome = nome ;
}

Peca::~Peca(){} 

std::string Peca::getNome(){
    return this->_nome ; 
}

Posicao Peca::getPosicao(){
    return this->_posicao ;

}

void Peca::move(int x, int y){
    if(x > 7 || x < 0 || y > 7 || y<0) throw PosicaoInvalidaException();

    if(this->pode_mover(x,y)){
        this->_posicao.set_posicao(x,y) ; 
    } else {
        throw MovimentoInvalidoException() ;
    }
}