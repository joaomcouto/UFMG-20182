#include "inventory.h"
#include "spells.h"
#include <iostream>

Inventory::Inventory(){

}
Inventory::~Inventory(){

}

<<<<<<< HEAD
=======
std::vector<Spell*> Inventory::instantiate_spell(){
    std::vector<Spell*> spell;

    Spell *Expelliarmus = new Spell("Expelliarmus", 1, 30, 40, 50, 20, 10);
    Spell *ExpectroPatronum = new Spell("Expectro Patronum", 3, 50, 20, 20, 30, 40);

    spell.push_back(Expelliarmus);
    spell.push_back(ExpectroPatronum);

    return spell;
}

void Inventory::print_spells(std::vector<Spell*> spell){
    const int spell_size = spell.size();

    std::cout << "Spell:" << std::endl;

    for (int i = 0; i < spell_size; i++)
        std::cout << "[" << i << "] " << spell[i]->get_name() << std::endl;
    std::cout <<std::endl;
}

>>>>>>> 2a5f382c570d7a30be838e6e15554ad781921212
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
