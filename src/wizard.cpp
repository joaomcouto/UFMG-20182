#include "character.h"
#include "wizard.h"
#include <iostream>
#include <string>

Wizard::Wizard(std::string name, int level, int hp, int mp, int str, int cons, int dex, std::string house, std::string wand, std::string patronum, std::vector<Spell *> _spells, std::vector<Object *> _potions, std::vector<Object *> _artifacts):
	Character(name, level, hp, mp, str, cons, dex, _spells), _house(house), _wand(wand), _patronum(patronum){
	this->_potionsVector = instantiate_potions(_potions);
	this->_artifactsVector = instantiate_artifacts(_artifacts);
}

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


std::vector<Object *> instantiate_potions(std::vector<Object *> _potions){

}

std::vector<Artifacts *> instantiate_artifacts(std::vector<Object *> _artifacts){

}

void Wizard::printPlayerSpells() { 
	int i = 1 ;
	for ( Spell* spell : this->_spellVector){
    	std::cout << "[" << i << "] "<< spell->get_name() << std::endl;
    	i++ ;
    }
} 
void Wizard::printPlayerPotions() {
	const int object_size = this-> _potionsVector.size();

    std::cout << "Potions:" << std::endl;

    for (int i = 0; i < object_size; i++)
	   std::cout << "[" << i << "] " <<  _potionsVector[i]->get_name() << " " << _potionsVector[i]->get_quant() << std::endl;

    std::cout <<std::endl;
}

void Wizard::printPlayerArtifacts(){
	const int object_size = this-> _artifactsVector.size();

    std::cout << "Artifacts:" << std::endl;

    for (int i = 0; i < object_size; i++)
	   std::cout << "[" << i << "] " <<  _artifactsVector[i]->get_name() << " " << _artifactsVector[i]->get_exist() << std::endl;

    std::cout <<std::endl;
}

void set_quantPotions(std::vector<Object*> potion, int i){


}
void Wizard::incrementSkill(int selection) {
	switch(selection){
		case 1:
			this->_baseStats.hp+=10;
			break;
		case 2:
			this->_baseStats.mp+=10;
			break;
		case 3:
			this->_baseStats.strenght+=1;
			break;
		case 4:
			this->_baseStats.constitution+=1;
			break;
		case 5:
			this->_baseStats.dexterity+=1;
			break;
	}
}
