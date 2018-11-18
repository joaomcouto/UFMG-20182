#include "spells.h"


Spell::Spell(std::string name, int level, int hp, int mp, int strenght, int constituion, int dexterity){
	this->_name = name;
	this->_level = level;
	this->_damageStats.hp= hp;
	this->_damageStats.mp = mp;
	this->_damageStats.strenght = strenght;
	this->_damageStats.constitution = constituion;
	this->_damageStats.dexterity = dexterity;
}

Spell::~Spell(){

}

int Spell::get_level(){
	return this->_level;
}

std::string Spell::get_name(){
	return this->_name;
}

int Spell::get_hp_dmg(){
	return this->_damageStats.hp ;
}

int Spell::get_mp_dmg(){
	return this->_damageStats.mp ;
}

int Spell::get_strenght_dmg(){
	return this->_damageStats.strenght ;
}

int Spell::get_constituion_dmg(){
	return this->_damageStats.constitution ;
}

int Spell::get_dexterity_dmg(){
	return this->_damageStats.dexterity ;
}