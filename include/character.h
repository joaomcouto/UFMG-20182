#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>
#include <vector>
#include "spells.h"

typedef struct {
	int level;
 	int hp;
 	int mp;
 	int strenght; 
 	int constitution;
 	int dexterity;
} Stats ;

class Character{
 protected: 
	std::string _name;
	Stats _baseStats ; 
	std::vector<Spell *> _spellVector ;

 public:
	Character(std::string name,int level, int hp, int mp, int str, int cons, int dex, std::vector<Spell *> _spells);
 	virtual ~Character();

	std::vector<Spell *> instantiate_spells(std::vector<Spell *> _spells);

	std::string getName();
	int getLevel();
	int getHP();
	int getMP();
	int getStrenght();
	int getConstitution();
	int getDexterity();
	std::vector<Spell *> getSpellVector();  
	Spell* getSpell(int i);
	
	void setLevel();
	void setHP(int i);
	void setMP(int i);
	void setStrenght(int i);
	void setConstitution(int i);
	void setDexterity(int i);
};
#endif
