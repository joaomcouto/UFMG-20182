#include "tabuleiro.h"
#include "excecoes.h"
#include <iostream> 

Tabuleiro::Tabuleiro() {
    
    _tabuleiro [Posicao(1,0)] = new Peao(1,0,"Peao");
    _tabuleiro [Posicao(1,1)] = new Peao(1,1,"Peao");
    _tabuleiro [Posicao(1,2)] = new Peao(1,2,"Peao");
    _tabuleiro [Posicao(1,3)] = new Peao(1,3,"Peao");
    _tabuleiro [Posicao(1,4)] = new Peao(1,4,"Peao");
    _tabuleiro [Posicao(1,5)] = new Peao(1,5,"Peao");
    _tabuleiro [Posicao(1,6)] = new Peao(1,6,"Peao");
    _tabuleiro [Posicao(1,7)] = new Peao(1,7,"Peao");
    _tabuleiro [Posicao(0,0)] = new Torre(0,0,"Torre");
    _tabuleiro [Posicao(0,7)] = new Torre(0,7,"Torre");
    _tabuleiro [Posicao(0,1)] = new Cavalo(0,1,"Cavelo");
    _tabuleiro [Posicao(0,6)] = new Cavalo(0,6,"Cavalo");
    _tabuleiro [Posicao(0,2)] = new Bispo(0,2,"Bispo");
    _tabuleiro [Posicao(0,5)] = new Bispo(0,5,"Bispo");
    _tabuleiro [Posicao(0,3)] = new Rainha(0,3,"Rainha");
    _tabuleiro [Posicao(0,4)] = new Rei(0,4,"Rei"); 

    _tabuleiro [Posicao(6,0)] = new Peao(6,0,"Peao");
    _tabuleiro [Posicao(6,1)] = new Peao(6,1,"Peao");
    _tabuleiro [Posicao(6,2)] = new Peao(6,2,"Peao");
    _tabuleiro [Posicao(6,3)] = new Peao(6,3,"Peao");
    _tabuleiro [Posicao(6,4)] = new Peao(6,4,"Peao");
    _tabuleiro [Posicao(6,5)] = new Peao(6,5,"Peao");
    _tabuleiro [Posicao(6,6)] = new Peao(6,6,"Peao");
    _tabuleiro [Posicao(6,7)] = new Peao(6,7,"Peao");
    _tabuleiro [Posicao(7,0)] = new Torre(7,0,"Torre");
    _tabuleiro [Posicao(7,7)] = new Torre(7,7,"Torre");
    _tabuleiro [Posicao(7,1)] = new Cavalo(7,1,"Cavalo");
    _tabuleiro [Posicao(7,6)] = new Cavalo(7,6,"Cavalo");
    _tabuleiro [Posicao(7,2)] = new Bispo(7,2,"Bispo");
    _tabuleiro [Posicao(7,5)] = new Bispo(7,5,"Bispo");
    _tabuleiro [Posicao(7,3)] = new Rainha(7,3,"Rainha");
    _tabuleiro [Posicao(7,4)] = new Rei(7,4,"Rei"); 


}




Tabuleiro::~Tabuleiro() {
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j ++){
            if (_tabuleiro[Posicao(i,j)] != nullptr) {
                delete _tabuleiro[Posicao(i,j)];
            }
        }
    }
    _tabuleiro.clear();
}

void Tabuleiro::move(Posicao origem, Posicao destino) {
    if ( _tabuleiro[origem] == nullptr ) { 
        throw PosicaoSemPecaException();
    } else { 
        if ( _tabuleiro[destino]== nullptr ) { 
            _tabuleiro[origem]->move(destino.get_x(), destino.get_y()); 
            _tabuleiro[destino] = _tabuleiro[origem] ;  
            _tabuleiro.erase(origem);
        } else {
            throw MovimentoInvalidoException();
        }
        
    }

} 

std::map <Posicao, Peca *> Tabuleiro::get_tabuleiro(){
    return _tabuleiro;
}
