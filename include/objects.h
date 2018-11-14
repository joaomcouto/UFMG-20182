#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Objeto {
protected:
	std::string _name;
	std::string _efect;
	int _quant;

public:
	Objeto(std::string name, std::string efect, int quant);
	virtual ~Objeto();
	std::string get_name();
	int get_quant();
	void set_quant();
};

#endif