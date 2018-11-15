#include "game.h"
#include <iostream>
#include "spells.h"
#include <vector>


std::vector<Spell *> instantiate_spell(){
    std::vector<Spell *> spell;

    Spell * Expelliarmus = new Spell("Expelliarmus", 1, 30, 40, 50, 20, 10);
    Spell *ExpectroPatronum = new Spell("Expectro Patronum", 3, 50, 20, 20, 30, 40);

    spell.push_back(Expelliarmus);
    spell.push_back(ExpectroPatronum);

    return spell;
}

std::string texts1(){
	std::string name;
	std::cout << "Please, enter your wizard/witch's name " << std::endl;
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Hogwarts School of Witchcraft and Wizardry" << std::endl;
	std::cout << "  Headmaster: Albus Dumbledore" << std::endl;
	std::cout << "Dear" << name << ", " << std::endl;
	std::cout << "It is with great pleasure that we're hereby informing that you've been officialy admitted in the great Hogwarts School of Witchcraft and Wizardry." << std::endl;
	std::cout << "First things first, you must acquire the necessary books and equipments." << std::endl;
	std::cout << "Yours sincerely, " << std::endl;
	std::cout << "Minerva McGonagall" << std::endl;
	std::cout << std::endl;
	return name;
}
std::string choice_of_wand(){
	std::cout << "Welcome to Olivanders, here, you shall acquire your very first wand." << std::endl;
	std::vector<std::string> woods;
	woods.push_back("Holly wood");
	woods.push_back("Willow tree wood");
	woods.push_back("Vine tree wood");
	woods.push_back("Walnut wood");
	woods.push_back("Olmo wood");
	woods.push_back("Cherry tree wood");
	woods.push_back("Colubrina wood");
	woods.push_back("Jacaranda wood");
	woods.push_back("Espinho-Negro");
	woods.push_back("Freixo");
	std::vector<std::string> cores;
	cores.push_back(" Pena de Fenix");
	cores.push_back(" Pelo de Unicornio");
	cores.push_back(" Fibra de Dragao");
	cores.push_back(" Pelo de Testralio");
	cores.push_back(" Chifre de Basilisco");
	cores.push_back(" Cabelo de Veela");
	cores.push_back(" Bigode de Trasgo");
	cores.push_back(" Chifre de Serpente Chifruda");
	int number_wood =  rand() % woods.size();
	int number_core =  rand() % cores.size();
	std::string wand = woods[number_wood] + " and " + cores[number_core];
	std::cout << "Your wand is made out of  " << wand << std::endl;
	std::cout << std::endl;
	return wand;

}
std::string choice_of_house(){
	std::cout << "Welcome to Hogwarts. The sorting hat shall decide what house is best suited for you" << std::endl;
	std::vector<std::string> houses;
	houses.push_back("Gryffindor");
	houses.push_back("Slytherin");
	houses.push_back("Ravenclaw");
	houses.push_back("Hufflepuff");
	int number_house = rand() % houses.size();
	std::string house = houses[number_house];
	std::cout << "Your house is: " << house << std::endl;
	std::cout << std::endl;
	return house;

}

std::string choice_of_patronum(){
	std::vector<std::string> patronuns;
	patronuns.push_back("Rat");
	patronuns.push_back("Phoenix");
	patronuns.push_back("Fox");
	patronuns.push_back("Otter");
	patronuns.push_back("Deer");
	patronuns.push_back("Hare");
	patronuns.push_back("Boar");
	patronuns.push_back("Cat");
	patronuns.push_back("Wolf");
	patronuns.push_back("Horse");
	int number_patronum = rand() % patronuns.size();
	std::string patronum = patronuns[number_patronum];
	std::cout << "Every witch and wizard has their very own patronus, yours shall take the form of a: " << patronum << std::endl;
	std::cout << std::endl;
	return patronum;
}

void initialize_player(){
	std::string name = texts1();
	std::string wand = choice_of_wand();
	std::string house = choice_of_house();
	std::string patronuns = choice_of_patronum();
	//Wizard *player = new Wizard(name,1, 100, 100, 100, 100, 100, house, wand, patronuns);
}
void texts2(){}