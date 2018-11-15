#ifndef POTIONS_H
#define POTIONS_H

#include "objects.h"

class Potions : public Object{
protected:
    int _quant;
private:
    Potions(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity, int quant);
    virtual ~Potions();
    int get_quant();
	void set_quant(int i);
};

#endif