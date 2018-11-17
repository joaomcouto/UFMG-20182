#include "wizard.h"
#include "enemy.h"
#include "battle.h"
#include "spells.h"
#include <iostream>
#include <string>

Battle::Battle(Wizard * player , Enemy * enemy){
    this->_round = 1 ; //Numero do round
    this->_ended = 0 ;  //Booleano de acabou
    this->_player = player ;  //Pointer para a instancia de player
    this->_enemy = enemy; //Pointer para a instancia de enermy
    if (player->getDexterity() > enemy->getDexterity()){ //Define quem vai ter o primeiro turno
        this->_playerturn = 1 ;
    } else {
        this->_playerturn = 0 ;
    }
}


void Battle::round(){
    if (this->_playerturn == 1){
        int menuIndex ;
        //int actionIndex; //essa variavel ainda nao foi usada, tire o comentario quando for usar
        unsigned int selectionIndex ;
        while(1){ //Deemed necessary, player might return to menu selection menu
            try {
                std::cout << "Make a choice:" << std::endl << "[1] Spells" << std::endl << "[2] Inventory" << std::endl ;
                std::cin >> menuIndex ;
                if (menuIndex == 1 ){
                    //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                    while(1){ //Done
                        try {
                            std::cout << "[0] "<<  "Back to main menu" << std::endl ;
                            _player->printPlayerSpells() ;
                            std::cin >> selectionIndex ;
                            if ((selectionIndex > 0) && (selectionIndex <= _player->getSpellVector().size())){
<<<<<<< HEAD
                                //move(_player->getSpellVector()[selectionIndex-1]) ;
=======
                                //move(_player->getSpellVector()[selectionIndex-1]) ; 
                                this->_playerturn = 0 ;
>>>>>>> 9b107c9c87dec918594996e7da4f8bfb41ca9e48
                                return ;
                            } else if (selectionIndex == 0 ) {
                                break ;
                            } else throw std::invalid_argument("Invalid spell index, try again ") ;
                        } catch (std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }
                    }
                } else if (menuIndex == 2 ){
                    int secondaryMenuIndex ;
                    while (1){
                        try{
<<<<<<< HEAD
                            std::cout << "[0] "<<  "Back to main menu" << std::endl ;
                            std::cout << "Make a choice:" << std::endl << "[1] Potions" << std::endl << "[2] Artifacts" << std::endl ;
=======
                            std::cout << "Make a choice:" << std::endl << "[0] Back to main menu" << std::endl << "[1] Potions" << std::endl << "[2] Artifacts" << std::endl ; 
>>>>>>> 9b107c9c87dec918594996e7da4f8bfb41ca9e48
                            std::cin>> secondaryMenuIndex ;
                            if (secondaryMenuIndex == 0){
                                break ;
                            } else if (secondaryMenuIndex == 1){
                                unsigned int potionIndex ;
                                while(1){
                                    try{
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        _player->printPlayerPotions();
                                        std::cin >> potionIndex ;
                                        if ((potionIndex > 0) && (potionIndex <= _player->getPotionsVector().size())){
<<<<<<< HEAD
                                            //move(_player->getPOtionsVector()[potionsIndex-1]) ;
=======
                                            //move(_player->getPotionsVector()[potionsIndex-1]) ; 
                                            this->_playerturn = 0 ;
>>>>>>> 9b107c9c87dec918594996e7da4f8bfb41ca9e48
                                            return ;
                                        } else if (potionIndex == 0 ) {
                                            break ;
                                        } else throw std::invalid_argument("Invalid potion index, try again ") ;
                                    } catch (std::invalid_argument &t) {
                                        std::cout << t.what() << std::endl;
                                        }
                                }
                            } else if (secondaryMenuIndex == 2 ){
                                unsigned int artifactsIndex ;
                                while(1){
                                    try{
                                        _player->printPlayerArtifacts();
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        std::cin >> artifactsIndex;
                                        if ((artifactsIndex > 0) && (artifactsIndex <= _player->getArtifactsVector().size())){
<<<<<<< HEAD
                                            //move(_player->getArtifactsVector()[artifactsIndex-1]) ;
=======
                                            //move(_player->getArtifactsVector()[artifactsIndex-1]) ; 
                                            this->_playerturn = 0 ;
>>>>>>> 9b107c9c87dec918594996e7da4f8bfb41ca9e48
                                            return ;
                                        } else if (artifactsIndex == 0 ) {
                                            break ;
                                        } else throw std::invalid_argument("Invalid potion index, try again ") ;
                                    } catch(std::invalid_argument &t){
                                        std::cout << t.what() << std::endl ;
                                    }
                                }
                            } else {
                                throw std::invalid_argument("Invalid secondary menu index, try again") ;
                            }
                        } catch(std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }

                    }
                } else {
                    throw std::invalid_argument("Invalid menu index, try again") ;
                }
            } catch(std::invalid_argument &t) {
                std::cout << t.what() << std::endl;
            }
        }


    } else {
        if (this->_enemy->getType() == "human"){
            int number_spell = rand() % this->_enemy->getSpellVector().size();
            std::cout << _enemy->getSpell(number_spell)->get_name() << std::endl; //imprimir o nome do feitico do inimigo na tela
        } else {
            std::cout << _enemy->getSpecialAttack()<< std::endl;
        }
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }

}
