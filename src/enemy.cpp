#include "character.h"
#include "enemy.h"

#define NUMBER_DECREMENT 10;

Enemy::Enemy(std::string name, std::string type, std::string special,  int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells):
	Character(name, level, hp, mp, str, cons, dex, _spells), _type(type), special_attack(special){}

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

std::string Enemy::getSpecialAttack(){
	return this->special_attack;
}
