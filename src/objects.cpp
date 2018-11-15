#include "objects.h"

Object::Object(std::string name, std::string efect, int quant){
	this->_name = name;
	this->_efect = efect;
	this->_quant = quant;
}

Object::~Object(){

}
std::string Object::get_name(){
	return this->_name;

}
int Object::get_quant(){
	return this->_quant;
}

void Object::set_quant(){
	this->_quant--;
}
