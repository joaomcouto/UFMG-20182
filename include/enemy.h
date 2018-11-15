#ifndef PDS2_ENEMY_H
#define PDS2_ENEMY_H

#include "character.h"
#include <string>

class Enemy : public Character{
protected:
  std::string _type ;
public:
   Enemy(std::string name, std::string type, int level, int hp, int mp, int str, int cons, int dex);
 	~Enemy();
   void decrementSkill(int i);	
   
 
};
#endif
