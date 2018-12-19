#include "doctest.h"
#include "rei.h"


TEST_CASE("Testando o Construtor") {
    Rei rei(3, 4, "Rei"); 
    int x = rei.getPosicao().get_x();
    int y = rei.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Nome"){
    Rei rei(3, 4, "Rei");
    std::string temp = rei.getNome();
    CHECK_EQ(temp, "Rei");
}

TEST_CASE("Movimentos corretos"){
    Rei rei (2,3, "Rei") ;
    CHECK_EQ(rei.pode_mover(2,4) , true) ;
    CHECK_EQ(rei.pode_mover(3,3), true);
    CHECK_EQ(rei.pode_mover(1,4), true) ;
}

TEST_CASE("Movimento/Posicao invalidos"){
    Rei rei (3,3, "Rei");
    CHECK_THROWS(rei.move(5,3)) ; 
    CHECK_THROWS(rei.move(0,-5)) ; 
}


