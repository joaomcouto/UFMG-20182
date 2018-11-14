#include <iostream>	
#include <time.h>
#include "inventory.h"
#include "game.h"

int main (){
	srand (time(NULL));
	choice_of_wand();
	choice_of_house();
	Inventory *inventory = new Inventory();
	std::vector<Objeto*> object = inventory->instantiate_object();
	//std::vector<Spell*> spell = inventory->instantiate_spell();
	inventory->print_object(object);
	inventory->set_object(object, 1);
//	inventory->print_spells(spell);

	for (auto Objeto : object)
		delete Objeto;
	delete inventory;
}
