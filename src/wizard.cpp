#include "character.h"
#include "wizard.h"
#include <iostream>
#include <string>

#define NUMBER_INCREMENT_HP_E_MP 10;
#define NUMBER_INCREMENT_OTHERS 1;

Wizard::Wizard(std::string name, int level, int hp, int mp, int str, int cons, int dex, std::string house, std::string wand, std::string patronum, std::vector<Spell *> _spells, std::vector<Potions *> _potions, std::vector<Artifacts *> _artifacts):
	Character(name, level, hp, mp, str, cons, dex, _spells), _house(house), _wand(wand), _patronum(patronum){
	this->_potionsVector = instantiate_potions(_potions);
	this->_artifactsVector = instantiate_artifacts(_artifacts);
}

Wizard::~Wizard(){}

std::vector<Potions *> Wizard::instantiate_potions(std::vector<Potions *> _potions){
	const int potions_size = _potions.size();

	std::vector<Potions *> Potion;

    for (int i = 0; i < potions_size; i++){
		if(_potions[i]->get_level() == 1)
			Potion.push_back(_potions[i]);
	}
	return Potion;
}

std::vector<Artifacts *> Wizard::instantiate_artifacts(std::vector<Artifacts *> _artifacts){
	const int artifacts_size = _artifacts.size();

	std::vector<Artifacts *> Artifact;

    for (int i = 0; i < artifacts_size; i++){
		if(_artifacts[i]->get_level() == 1)
			Artifact.push_back(_artifacts[i]);
	}
	return Artifact;
}

std::string Wizard::getHouse(){
	return this->_house;
}

std::string Wizard::getWand(){
	return this->_wand;
}

std::string Wizard::getPatronum(){
	return this->_patronum;
}

std::vector<Potions *> Wizard::getPotionsVector(){
	return this->_potionsVector;
}

std::vector<Artifacts *> Wizard::getArtifactsVector(){
	return this->_artifactsVector;
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

void set_quantPotions(std::vector<Potions *> potion, int i, int quant){
	potion[i]->set_quant(quant);
}

void set_existArtifacts(std::vector<Artifacts *> artifact, int i){
	artifact[i]->set_exist();
}

void Wizard::incrementSkill(int selection) {
	switch(selection){
		case 1:
			this->_baseStats.hp += NUMBER_INCREMENT_HP_E_MP;
			break;
		case 2:
			this->_baseStats.mp += NUMBER_INCREMENT_HP_E_MP;
			break;
		case 3:
			this->_baseStats.strenght += NUMBER_INCREMENT_OTHERS;
			break;
		case 4:
			this->_baseStats.constitution += NUMBER_INCREMENT_OTHERS;
			break;
		case 5:
			this->_baseStats.dexterity += NUMBER_INCREMENT_OTHERS;
			break;
	}
}
