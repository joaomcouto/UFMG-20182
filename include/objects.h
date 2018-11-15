#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
protected:
	std::string _name;
	std::string _efect;
	int _quant;

public:
	Object(std::string name, std::string efect, int quant);
	virtual ~Object();
	std::string get_name();
	int get_quant();
	void set_quant();
};

#endif