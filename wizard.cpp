#include "character.h"
#include "wizard.h"

Wizard::Wizard(std::string name, int level, int hp,     int mp, std::string type, int skill, std::string house, std::string wand, std::string patronum) : Character(name, level, hp, mp, type, skill), _house(house), _wand(wand), _patronum(patronum) {};

Wizard::~Wizard(){}

std::string Wizard::getHouse(){
	return this->_house;
}

std::string Wizard::getWand(){
	return this->_wand;
}

std::string Wizard::getPatronum(){
	return this->_patronum;
}
