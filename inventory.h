#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "objects.h"
#include "spells.h"
#include <string>
#include <vector>

class Inventory{
	public:
		std::vector<Feiticos*> instantiate_spell();
		void print_spells(std::vector<Feiticos*> spell);
		std::vector<Objeto*> instantiate_object();
		void print_object(std::vector<Objeto*> object);
		void set_object(std::vector<Objeto*> object, int i);
		Inventory();
		virtual ~Inventory();

};

#endif