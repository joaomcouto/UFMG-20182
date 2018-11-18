#ifndef SPELLS_H
#define SPELLS_H

#include <string>
#include "stats.h"

class Spell {
protected:
	std::string _name;
	Stats _damageStats ;
	int _duration ; 
	int _level;
//	int _hp ;
//	int _mp ;
	

public:	
	Spell(int duration , std::string name, int level, int hp, int mp, int strenght, int constituion, int dexterity);
	virtual ~Spell();
	int getDuration(); 
	Stats getDamageStats() ;
	std::string get_name();
	int get_level();
	int get_hp_dmg();
	int get_mp_dmg();
	int get_strenght_dmg();
	int get_constituion_dmg();
	int get_dexterity_dmg();

};

#endif