#include "spells.h"


Spell::Spell(std::string name, int level, int hp, int mp, int strenght, int constituion, int dexterity){
	this->_name = name;
	this->_level = level;
	this->hp_dmg = hp;
	this->mp_dmg = mp;
	this->strenght_dmg = strenght;
	this->constituion_dmg = constituion;
	this->dexterity_dmg = dexterity;
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
	return this->hp_dmg;
}

int Spell::get_mp_dmg(){
	return this->mp_dmg;
}

int Spell::get_strenght_dmg(){
	return this->strenght_dmg;
}

int Spell::get_constituion_dmg(){
	return this->constituion_dmg;
}

int Spell::get_dexterity_dmg(){
	return this->dexterity_dmg;
}