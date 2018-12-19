#include "doctest.h"
#include "peao.h"


TEST_CASE("Testando o Construtor") {
    Peao peao(3, 4, "Peao"); 
    int x = peao.getPosicao().get_x();
    int y = peao.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Nome"){
    Peao peao(3, 4, "Peao");
    std::string temp = peao.getNome();
    CHECK_EQ(temp, "Peao");
}

TEST_CASE("Movimentos corretos"){
    Peao peao (2,3, "Peao") ;
    CHECK_EQ(peao.pode_mover(3,3) , true) ;
}

TEST_CASE("Movimento/Posicao invalidos"){
    Peao peao (3,3, "Peao");
    CHECK_THROWS(peao.move(3,5)) ; 
    CHECK_THROWS(peao.move(9,0)) ; 
}


