#include "game.h"
#include <iostream>

void texts1(){
	std::string name;
	std::cout << "Escreva o seu nome bruxo: " << std::endl;
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Escola de Magia e Bruxaria de Hogwarts" << std::endl;
	std::cout << "  Diretor: Alvo Dumbledore" << std::endl;
	std::cout << "Prezado " << name << std::endl;
	std::cout << "Temos o prazer de informar que voce tem uma vaga na Escola de Magia e Bruxaria de Hogwats." << std::endl;
	std::cout << "Primeiramente voce precisa adquirir seus livros e equipamentos necessarios." << std::endl;
	std::cout << "Atenciosamente," << std::endl;
	std::cout << "Minerva McGonagall" << std::endl;
}
std::string choice_of_wand(){
	std::cout << "Bem-vindo a Olivaras, e aqui que voce ira adquirir sua primeira varinha." << std::endl;
	std::vector<std::string> woods;
	woods.push_back("Azevinho");
	woods.push_back("Salgueiro");
	woods.push_back("Videira");
	woods.push_back("Nogueira");
	woods.push_back("Olmo");
	woods.push_back("Cerejeira");
	woods.push_back("Colubrina");
	woods.push_back("Jacaranda");
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
	std::string wand = woods[number_wood] + cores[number_core];
	std::cout << "Sua varinha é: " << wand << std::endl;
	return wand;

}
std::string choice_of_house(){
	std::vector<std::string> houses;
	houses.push_back("Grifinoria");
	houses.push_back("Sonserina");
	houses.push_back("Corvinal");
	houses.push_back("Lufa-Lufa");
	int number_house = rand() % houses.size();
	std::string house = houses[number_house];
	std::cout << "Sua casa e: " << house << std::endl;
	return house;
}
void initialize_player(std::string wand, std::string house){

}
void texts2();
