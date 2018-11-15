#include "objects.h"

Object::Object(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity){
	this->_name = name;
	this->level = _level;
	this->efect_hp = _hp;
 	this->efect_mp = _mp;
 	this->efect_strenght = _strenght; 
 	this->efect_constitution = _constituion;
 	this->efect_dexterity = _dexterity;
}

Object::~Object(){

}
std::string Object::get_name(){
	return this->_name;

}

int Object::get_level(){
	return this->level;
}
