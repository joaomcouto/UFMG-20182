#ifndef PDS2_ENEMY_H
#define PDS2_ENEMY_H

#include "character.h"
#include <string>

class Enemy : public Character{
protected:
  std::string _type ;
  std::string  special_attack;
  std::string _intro ; 
public:
  Enemy(std::string name, std::string type, std::string special, int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells, std::string intro);
 	~Enemy();
  void decrementSkill(int i);	
  std::string getType();
  std::string getSpecialAttack();
  void printIntro();
};
#endif
