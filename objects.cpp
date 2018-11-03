#include "objects.h"

Objeto::Objeto(std::string name, std::string efect, int quant){
	this->_name = name;
	this->_efect = efect;
	this->_quant = quant;
}

Objeto::~Objeto(){

}
std::string Objeto::get_name(){
	return this->_name;

}
int Objeto::get_quant(){
	return this->_quant;
}

void Objeto::set_quant(){
	this->_quant--;
}
