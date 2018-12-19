#include "doctest.h"
#include "tabuleiro.h"
#include "excecoes.h"
#include <string>


TEST_CASE("Construtor") {
    Tabuleiro *a = new Tabuleiro();
    Peca *b = a->get_tabuleiro()[Posicao(7,0)];
    int x = b->getPosicao().get_x()  ;
    int y = b->getPosicao().get_y()  ;
    std::string nome = b->getNome()  ;
    CHECK_EQ(x, 7);
    CHECK_EQ(y, 0);
    CHECK_EQ(nome, "Torre");
    a->~Tabuleiro(); 
    delete a;
} 

TEST_CASE("Mover de posicao sem peca") {
    Tabuleiro *a = new Tabuleiro();
    CHECK_THROWS(a->move(Posicao(5,5), Posicao(0,5))); 
    a->~Tabuleiro();
}

TEST_CASE("Mover de posicao vazia") {
    Tabuleiro *a = new Tabuleiro();
    CHECK_THROWS(a->move(Posicao(3,2), Posicao(1,0)));
    a->~Tabuleiro();
} 

TEST_CASE("Mover para posicao vazia") {
    Tabuleiro *a = new Tabuleiro();
    CHECK_NOTHROW(a->move(Posicao(1,0), Posicao(2,0)));
    a->~Tabuleiro();
} 




TEST_CASE("Mover peca de forma errada") {
    Tabuleiro *a = new Tabuleiro();
    CHECK_THROWS(a->move(Posicao(0,0), Posicao(0,5))); 
    CHECK_THROWS(a->move(Posicao(0,0), Posicao(0,2)));
    a->~Tabuleiro();
}

TEST_CASE("Testando outputs das excessoes (eu só queria pegar 100% coverage, foi mal)"){
    PosicaoInvalidaException a ; 
    MovimentoInvalidoException b ;
    PosicaoSemPecaException c ; 
    std::string a_out  = a.what() ; 
    std::string b_out  = b.what() ; 
    std::string c_out  = c.what() ;
    
    CHECK_EQ(a_out, "Coordenadas invalidas") ;
    CHECK_EQ(b_out, "Movimento invalido") ;
    CHECK_EQ(c_out, "Posicao origem selecionada nao tem uma peca") ;
}





