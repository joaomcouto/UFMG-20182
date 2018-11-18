#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "stats.h"

class Object {
protected:
	std::string _name;
	Stats _effectStats ;
	int _duration ;
	

public:
	Object(int duration,std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity);
	virtual ~Object();
	std::string get_name();
	int get_level();
};

#endif