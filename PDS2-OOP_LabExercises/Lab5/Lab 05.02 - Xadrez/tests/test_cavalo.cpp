#include "doctest.h"
#include "cavalo.h"


TEST_CASE("Testando o Construtor") {
    Cavalo cavalo(3, 4, "Cavalo"); 
    int x = cavalo.getPosicao().get_x();
    int y = cavalo.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Nome"){
    Cavalo cavalo(3, 4, "Cavalo");
    std::string temp = cavalo.getNome();
    CHECK_EQ(temp, "Cavalo");
}

TEST_CASE("Movimentos corretos"){
    Cavalo cavalo (2,3, "Cavalo") ;
    CHECK_EQ(cavalo.pode_mover(3,1) , true) ;

}

TEST_CASE("Movimento/Posicao invalidos"){
    Cavalo cavalo (3,3, "Cavalo");
    CHECK_THROWS(cavalo.move(4,7)) ; 
    CHECK_THROWS(cavalo.move(9,0)) ; 
}


