#ifndef PDS2_WIZARD_H
#define PDS2_WIZARD_H

#include "character.h"
#include <string>

class Wizard : public Character{
 protected:
	std::string _house;
	std::string _wand;
	std::string _patronum;
 public:
  Wizard(std::string name, int level, int hp, int mp,     std::string type, int skill, std::string house, std::string wand, std::string patronum);
	~Wizard();

	std::string getHouse();
	std::string getWand();
	std::string getPatronum();
};
#endif
