#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>

class Character{
 protected: 
	std::string _name;
	std::string _type;
 	int _level;
 	int _hp;
 	int _mp;
 	int _strenght ; 
 	int _constitution ;
 	int _dexterity ;
 	

 public:
	Character(std::string name, std::string type, int level, int hp, int mp, int str, int cons, int dex);
 	~Character();

	std::string getName();
	int getLevel();
	int getHP();
	int getMP();
	int getStrenght();
	int getConstitution();
	int getDexterity();
 	std::string getType();
};
#endif
