#include "doctest.h"
#include "rainha.h"


TEST_CASE("Testando o Construtor") {
    Rainha rainha(3, 4, "Rainha"); 
    int x = rainha.getPosicao().get_x();
    int y = rainha.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Movimentos corretos"){
    Rainha rainha (2,3, "Rainha") ;
    CHECK_EQ(rainha.pode_mover(5,3) , true) ;
    CHECK_EQ(rainha.pode_mover(5,0), true);
    CHECK_EQ(rainha.pode_mover(2,6), true) ;
}

TEST_CASE("Movimento/Posicao invalidos"){
    Rainha rainha (3,3, "Rainha");
    CHECK_THROWS(rainha.move(4,6)) ; 
    CHECK_THROWS(rainha.move(8,0)) ; 
}

TEST_CASE("Nome"){
    Rainha rainha(3, 4, "Rainha");
    std::string temp = rainha.getNome();
    CHECK_EQ(temp, "Rainha");
}
