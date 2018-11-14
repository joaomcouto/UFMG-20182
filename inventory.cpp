#include "inventory.h"
#include "spells.h"
#include <iostream>

Inventory::Inventory(){

}
Inventory::~Inventory(){

}


std::vector<Objeto*> Inventory::instantiate_object(){
    std::vector<Objeto*> object;

    Objeto *ViraTempo = new Objeto("Vira-Tempo", "voltar no tempo", 1);
    Objeto *Capa = new Objeto("Capa da Invisibilidade", "sumir", 1);
    Objeto *Revigora = new Objeto("Pocao Revigorante", "mais vida", 3);

    object.push_back(ViraTempo);
    object.push_back(Capa);
    object.push_back(Revigora);

    return object;

}

void Inventory::print_object(std::vector<Objeto*> object){
    const int object_size = object.size();

    std::cout << "Artefatos e Pocoes:" << std::endl;

    for (int i = 0; i < object_size; i++)
	   std::cout << "[" << i << "] " <<  object[i]->get_name() << " " << object[i]->get_quant() << std::endl;

    std::cout <<std::endl;
}

void Inventory::set_object(std::vector<Objeto*> object, int i){
    object[i]->set_quant();
}
