#include "character.h"
#include <string>

Character::Character(std::string name, std::string type, int level, int hp, int mp, int str, int cons, int dex) : 
_name(name),_type(type), _level(level), _hp(hp), _mp(mp),  _strenght(str), _constitution(cons), _dexterity(dex) {};

Character::~Character(){}

std::string Character::getName(){
	return this->_name;
}

int Character::getLevel(){
	return this->_level;
}

int Character::getHP(){
	return this->_hp;
}

int Character::getMP(){
	return this->_mp;
}


int Character::getStrenght(){
	return this->_strenght ; 
}

int Character::getConstitution(){
	return this->_constitution ;
}

int Character::getDexterity(){
	return this->_dexterity ;
}

std::string Character::getType(){
	return this->_type; 
}

