#include "excecoes.h"
#include <string>

const char* PosicaoInvalidaException::what() const noexcept{
    return "Coordenadas invalidas" ; 
    }

const char* MovimentoInvalidoException::what() const noexcept{
    return "Movimento invalido";
     } 

const char* PosicaoSemPecaException::what() const noexcept{
    return "Posicao origem selecionada nao tem uma peca" ;
}
