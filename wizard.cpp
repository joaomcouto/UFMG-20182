#include "character.h"
#include "wizard.h"

Wizard::Wizard(std::string name, std::string type, int level, int hp, int mp, int str, int cons, int dex, std::string house, std::string wand, std::string patronum) :
 Character(name, type, level, hp, mp, str, cons, dex), _house(house), _wand(wand), _patronum(patronum) {};

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

std::vector<Spell *> Wizard::getSpellVector(){
	return this->_spellVector ;
}

void Wizard::incrementSkill(int selection) {
	switch(selection){
		case 1:
			this->_hp+=10;
			break;
		case 2:
			this->_mp+=10;
			break;
		case 3:
			this->_strenght+=1;
			break;
		case 4:
			this->_constitution+=1;
			break;
		case 5:
			this->_dexterity+=1;
			break;
	}
}
