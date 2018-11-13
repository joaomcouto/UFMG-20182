#ifndef PDS2_WIZARD_H
#define PDS2_WIZARD_H

#include "character.h"
#include "spells.h"
#include <string>
#include <vector>

class Wizard : public Character{
 protected:
	std::string _house;
	std::string _wand;
	std::string _patronum;
	int _skillPoints ;
 public:
  	Wizard(std::string name, std::string type, int level, int hp, int mp, int str , int cons, int dex, std::string house, std::string wand, std::string patronum);
	~Wizard();
	std::vector<Spell *> spellVector ;
	std::string getHouse();
	std::string getWand();
	std::string getPatronum();
	void incrementSkill(int selection) ;
};
#endif
