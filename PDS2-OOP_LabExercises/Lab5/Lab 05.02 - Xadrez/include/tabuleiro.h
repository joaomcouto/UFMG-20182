#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <map>
#include "peca.h"
#include "rainha.h"
#include "peao.h"
#include "bispo.h"
#include "rei.h"
#include "torre.h"
#include "cavalo.h"
#include "posicao.h"

class Tabuleiro {
private:
    std::map < Posicao, Peca * > _tabuleiro;
public:
    Tabuleiro();
    ~Tabuleiro();
    void move(Posicao, Posicao);
    std::map < Posicao, Peca * > get_tabuleiro();
};


#endif
