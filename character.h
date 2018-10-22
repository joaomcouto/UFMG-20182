#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

#include <string>

class Character{
private: 
 std::string _name;
 int _level;
 int _hp;
 int _mp;
 std::string _type;
 int _skill;

public:
 Character();
 ~Character();

 std::string getName();
 int getLevel();
 int getHP();
 int getMP();
 std::string getType();
};
#endif
