#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>

typedef struct {
	int level;
 	int hp;
 	int mp;
 	int strenght ; 
 	int constitution ;
 	int dexterity ;
} Stats ;

class Character{
 protected: 
	std::string _name;
	std::string _type;
	Stats _baseStats ; 
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
