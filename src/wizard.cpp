#include "character.h"
#include "wizard.h"
#include <iostream>
#include <string>

#define NUMBER_INCREMENT_HP_E_MP 10;
#define NUMBER_INCREMENT_OTHERS 1;

Wizard::Wizard(std::string name, int level, int hp, int mp, int str, int cons, int dex, std::string house, std::string wand, std::string patronum, std::vector<Spell *> _spells, std::vector<Potions *> _potions, std::vector<Artifacts *> _artifacts) throw (InvalidCharacterException) :
	Character(name, level, hp, mp, str, cons, dex), _house(house), _wand(wand), _patronum(patronum){
	setSpellVector(instantiate_spells(_spells));
	this->_potionsVector = instantiate_potions(_potions);
	this->_artifactsVector = instantiate_artifacts(_artifacts);
	this->_skillPoints = 3 ; 
}

Wizard::~Wizard(){}

void Wizard::incrementSkillPoints(int points){
	this->_skillPoints += points ;
}

std::vector<Spell *> Wizard::instantiate_spells(std::vector<Spell *> _spells){
	const int spells_size = _spells.size();

	std::vector<Spell *> Spells;

    for (int i = 0; i < spells_size; i++){
		if(_spells[i]->get_level() <= getLevel())
			Spells.push_back(_spells[i]);
	}
	return Spells;
}

std::vector<Potions *> Wizard::instantiate_potions(std::vector<Potions *> _potions){
	const int potions_size = _potions.size();

	std::vector<Potions *> Potion;

    for (int i = 0; i < potions_size; i++){
		if(_potions[i]->get_level() <= getLevel())
			Potion.push_back(_potions[i]);
	}
	return Potion;
}

std::vector<Artifacts *> Wizard::instantiate_artifacts(std::vector<Artifacts *> _artifacts){
	const int artifacts_size = _artifacts.size();

	std::vector<Artifacts *> Artifact;

    for (int i = 0; i < artifacts_size; i++){
		if(_artifacts[i]->get_level() <= getLevel())
			Artifact.push_back(_artifacts[i]);
	}
	return Artifact;
}

int Wizard::getSkillPoints(){
	return this->_skillPoints ;
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

    for (int i = 0; i < object_size; i++)
		std::cout << "[" << i+1 << "] " <<  _potionsVector[i]->get_name() << " " << _potionsVector[i]->get_quant() << std::endl;

    std::cout <<std::endl;
}

void Wizard::printPlayerArtifacts(){
	const int object_size = this-> _artifactsVector.size();

    for (int i = 0; i < object_size; i++)
	   std::cout << "[" << i+1 << "] " <<  _artifactsVector[i]->get_name() << std::endl;

    std::cout <<std::endl;
}

void Wizard::setPotionsVector(std::vector<Potions *> potions){
	std::vector<Potions *> new_potions = this->instantiate_potions(potions);
	this->_potionsVector = new_potions;
	std::cout << _potionsVector[1]->get_quant() << std::endl;
	std::cout << new_potions[1]->get_quant() << std::endl;
}

void Wizard::setArtifactsVector(std::vector<Artifacts *> artifacts){
	std::vector<Artifacts *> new_artifacts = instantiate_artifacts(artifacts);
	this->_artifactsVector = new_artifacts;
}

void Wizard::set_quantPotions(int i, int quant){
	this->_potionsVector[i]->set_quant(quant);
	if (this->_potionsVector[i]->get_quant() == 0)
		erase_Potion(i);
}

void Wizard::erase_Potion(int i){
	this->_potionsVector.erase(_potionsVector.begin() + i);
}

void Wizard::set_existArtifacts(int i){
	this->_artifactsVector[i]->set_exist();
}

void Wizard::erase_Artifact(int i){
	this->_artifactsVector.erase(_artifactsVector.begin() + i);
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
	this->_skillPoints -= 1 ;
}
