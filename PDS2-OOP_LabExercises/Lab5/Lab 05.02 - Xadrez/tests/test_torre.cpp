#include "doctest.h"
#include "torre.h"


TEST_CASE("Testando o Construtor") {
    Torre torre(3, 4, "Torre"); 
    int x = torre.getPosicao().get_x();
    int y = torre.getPosicao().get_y();
    CHECK_EQ(x,3) ;
    CHECK_EQ(y,4);
}

TEST_CASE("Nome"){
    Torre torre(3, 4, "Torre");
    std::string temp = torre.getNome();
    CHECK_EQ(temp, "Torre");
}

TEST_CASE("Movimentos corretos"){
    Torre torre (2,3, "Torre") ;
    CHECK_EQ(torre.pode_mover(2,7) , true) ;
}

TEST_CASE("Movimento/Posicao invalidos"){
    Torre torre (3,3, "Torre");
    CHECK_THROWS(torre.move(4,5)) ; 
    CHECK_THROWS(torre.move(0,9)) ; 
}


