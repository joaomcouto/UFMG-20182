#include "doctest.h"
#include "bispo.h"


TEST_CASE("Testando o Construtor") {
    Bispo bispo(3, 4, "Bispo"); 
    int x = bispo.getPosicao().get_x();
    int y = bispo.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Nome"){
    Bispo bispo(3, 4, "Bispo");
    std::string temp = bispo.getNome();
    CHECK_EQ(temp, "Bispo");
}

TEST_CASE("Movimentos corretos"){
    Bispo bispo (2,3, "Bispo") ;
    CHECK_EQ(bispo.pode_mover(5,0) , true) ;

}

TEST_CASE("Movimento/Posicao invalidos"){
    Bispo bispo (3,3, "Bispo");
    CHECK_THROWS(bispo.move(4,6)) ; 
    CHECK_THROWS(bispo.move(-1,0)) ;
}


