#include "character.h"
#include <string>

Character::Character(std::string name, int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells): 
	_baseStats{level, hp, mp, str, cons, dex}, _name(name), _spellVector(instantiate_spells(_spells)){}


Character::~Character(){}

std::vector<Spell *> Character::instantiate_spells(std::vector<Spell *> _spells){
	const int spells_size = _spells.size();

	std::vector<Spell *> Spells;

    for (int i = 0; i < spells_size; i++){
		if(_spells[i]->get_level() <= getLevel())
			Spells.push_back(_spells[i]);
	}
	return Spells;

}

std::string Character::getName(){
	return this->_name;
}

Stats Character::getBaseStats(){
	return this->_baseStats;
}

void Character::setStats(Stats st){
	this->_baseStats = st ;
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

std::vector<Spell *> Character::getSpellVector(){
	return this->_spellVector ;
}

Spell* Character::getSpell(int i){
	return this->_spellVector[i];
}

void Character::setLevel(){
	 _baseStats.level++;
}

void Character::setHP(int i){
	 _baseStats.hp += i;
}

void Character::setMP(int i){
	 _baseStats.mp += i;
}

void Character::setStrenght(int i){
	 _baseStats.strenght += i;
}

void Character::setConstitution(int i){
	 _baseStats.constitution += i;
}

void Character::setDexterity(int i){
	 _baseStats.dexterity += i;
}



