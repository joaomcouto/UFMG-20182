#include "character.h"
#include "enemy.h"
#include <iostream>

#define NUMBER_DECREMENT 10;

Enemy::Enemy(std::string name, std::string type, specialAttack attack, int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells , std::string intro):
	Character(name, level, hp, mp, str, cons, dex, _spells), _type(type), _attack(attack), _intro(intro){}

Enemy::~Enemy(){}

void Enemy::decrementSkill(int i){
	switch(i){
		case 1:
			this->_baseStats.hp -= NUMBER_DECREMENT;
			break;
		case 2:
			this->_baseStats.mp -= NUMBER_DECREMENT;
			break;	
	}
}

std::string Enemy::getType(){
	return this->_type;
}

specialAttack Enemy::getSpecialAttack(){
	return this->_attack;
}

void Enemy::printIntro(){
	std::cout << this->_intro << std::endl;
}
