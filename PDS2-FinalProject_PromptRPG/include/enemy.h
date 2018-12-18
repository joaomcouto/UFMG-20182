#ifndef PDS2_ENEMY_H
#define PDS2_ENEMY_H

#include "character.h"
#include <string>

typedef struct {
  std::string _name;
	Stats _damageStats ;
} specialAttack;

class Enemy : public Character{
protected:
  std::string _type ;
  specialAttack _attack;
  std::string _intro ; 
public:
  Enemy(std::string name, std::string type, specialAttack attack, int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells, std::string intro);
 	~Enemy();

  virtual std::vector<Spell *> instantiate_spells(std::vector<Spell *> _spells) override;

  void decrementSkill(int i);	
  std::string getType();
  specialAttack getSpecialAttack();
  void printIntro();
};
#endif
