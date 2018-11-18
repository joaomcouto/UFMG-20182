#include "objects.h"

Object::Object(int duration, std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity){
	this->_duration = duration ; 
	this->_name = name;
	this->_effectStats.level = _level;
	this->_effectStats.hp = _hp;
 	this->_effectStats.mp = _mp;
 	this->_effectStats.strenght = _strenght; 
 	this->_effectStats.constitution = _constituion;
 	this->_effectStats.dexterity = _dexterity;
}

Object::~Object(){

}
std::string Object::get_name(){
	return this->_name;

}

int Object::get_level(){
	return this->_effectStats.level;
}

int Object::getDuration(){
	return this->_duration ; 
}

Stats Object::getEffectsStats(){
	return this->_effectStats ;
}

int Object::get_hp_effect(){
	return this->_effectStats.hp;
}