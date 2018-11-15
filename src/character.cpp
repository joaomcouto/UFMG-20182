#include "character.h"
#include <string>

Character::Character(std::string name, int level, int hp, int mp, int str, int cons, int dex) : 
_baseStats{level, hp, mp, str, cons, dex}, _name(name) {} 

Character::~Character(){}

std::string Character::getName(){
	return this->_name;
}

int Character::getLevel(){
	return this->_baseStats.level;
}

int Character::getHP(){
	return this->_baseStats.hp;
}

int Character::getMP(){
	return this->_baseStats.mp;
}


int Character::getStrenght(){
	return this->_baseStats.strenght ; 
}

int Character::getConstitution(){
	return this->_baseStats.constitution ;
}

int Character::getDexterity(){
	return this->_baseStats.dexterity ;
}



