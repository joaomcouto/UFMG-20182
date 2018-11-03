#include <iostream>	
#include "inventory.h"


int main (){
	Inventory *inventory = new Inventory();
	std::vector<Objeto*> object = inventory->instantiate_object();
	std::vector<Feiticos*> spell = inventory->instantiate_spell();
	inventory->print_object(object);
	inventory->set_object(object, 1);
	inventory->print_spells(spell);
	
	for (auto Objeto : object)
		delete Objeto;
	delete inventory;
}