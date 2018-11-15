#include "potions.h"

Potions::Potions(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity, int quant):
    Object(name, _level, _hp, _mp, _strenght, _constituion, _dexterity), _quant(quant) {}


Potions::~Potions(){

}

int Potions::get_quant(){
	return this->_quant;
}

void Potions::set_quant(int i){
	this->_quant += i;
}