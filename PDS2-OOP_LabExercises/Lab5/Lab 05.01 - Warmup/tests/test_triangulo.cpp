#include "doctest.h"
#include "triangulo.h"


TEST_CASE("Teste VPL - Equilatero") {
    Triangulo t(5, 5, 5);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::EQUILATERO);
}

TEST_CASE("Teste VPL - Isosceles"){
    Triangulo t1(3,5,5);
    Tipo tipo = t1.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ISOSCELES); 
}

TEST_CASE("Teste VPL - Escaleno"){
    Triangulo t2(5,7,8);
    Tipo tipo = t2.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ESCALENO) ;
}

TEST_CASE("Teste VPL - Excecao Negativo") {
    CHECK_THROWS(new Triangulo(5, -5, 5));
}


