#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
protected:
	std::string _name;
	int level;
	int efect_hp;
 	int efect_mp;
 	int efect_strenght ; 
 	int efect_constitution ;
 	int efect_dexterity ;

public:
	Object(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity);
	virtual ~Object();
	std::string get_name();
	int get_level();
};

#endif