#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>

class Character{
 protected: 
	std::string _name;
 	int _level;
 	int _hp;
 	int _mp;
 	std::string _type;
 	int _skill; //Value that will be incremented in some feature

 public:
	Character(std::string name, int level, int hp, int mp, std::string type,
 int skill);
 	~Character();

	std::string getName();
	int getLevel();
	int getHP();
	int getMP();
	int getSkill();
 	std::string getType();
};
#endif
