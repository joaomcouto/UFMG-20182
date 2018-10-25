#include "character.h"
#include <string>

Character::Character(std::string name, int level, int hp, int mp, std::string     type, int skill) : _name(name), _level(level), _hp(hp), _mp(mp), _type(type), _skill(skill) {};

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

int Character::getSkill(){
	return this->_skill;
}

std::string Character::getType(){
	return this->_type; 
}
