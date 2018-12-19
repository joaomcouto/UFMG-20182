#ifndef VACA_H
#define VACA_H

#include <iostream>
#include "Animal.h"

class Vaca : public Animal {
    private:
        float _producao_leite;
    public:
        Vaca(std::string cor,float producao_leite);
        Animal* reproduz() override;
        void faz_barulho() override;
        unsigned int get_id() override;
};


#endif