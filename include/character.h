#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>
#include <vector>
#include "spells.h"
#include "stats.h"



class Character{
 protected: 
	std::string _name;
	Stats _baseStats ; 
	std::vector<Spell *> _spellVector ;

 public:
	Character(std::string name,int level, int hp, int mp, int str, int cons, int dex);
 	virtual ~Character();

	virtual std::vector<Spell *> instantiate_spells(std::vector<Spell *> _spells) = 0;

	std::string getName();
	int getLevel();
	int getHP();
	int getMP();
	int getStrenght();
	int getConstitution();
	int getDexterity();
	void printStats();
	std::vector<Spell *> getSpellVector();  
	Spell* getSpell(int i);
	Stats getBaseStats();
	void setStats(Stats st) ;

	void setSpellVector(std::vector<Spell *> _spells);
	void setLevel();
	void setHP(int i);
	void setMP(int i);
	void setStrenght(int i);
	void setConstitution(int i);
	void setDexterity(int i);
};
#endif
