#ifndef CACHORRO_H
#define CACHORRO_H

#include <iostream>
#include "Animal.h"

class Cachorro : public Animal {
    public:
        Cachorro(std::string cor);
        Animal* reproduz() override;
        void faz_barulho() override;
        unsigned int get_id() override;
};


#endif