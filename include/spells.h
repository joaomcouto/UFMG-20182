#ifndef SPELLS_H
#define SPELLS_H

#include <string>

class Spell {
protected:
	std::string _name;
	int _level;
	int hp_dmg;
	int mp_dmg;
	int strenght_dmg;
	int constituion_dmg;
	int dexterity_dmg;

public:	
	Spell(std::string name, int level, int hp, int mp, int strenght, int constituion, int dexterity);
	virtual ~Spell();
	std::string get_name();
	int get_level();
	int get_hp_dmg();
	int get_mp_dmg();
	int get_strenght_dmg();
	int get_constituion_dmg();
	int get_dexterity_dmg();

};

#endif