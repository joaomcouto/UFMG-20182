#include "character.h"
#include "wizard.h"
#include "battle.h"
#include "spells.h"
#include <iostream>
#include <string>

Battle::Battle(Wizard * player , Character * enemy){
    this->_round = 1 ;
    this->_ended = 0 ; 
    this->_player = player ; 
    this->_enemy = enemy;
    if (player->getDexterity() > enemy->getDexterity()){
        this->_playerturn = 1 ; 
    } else {
        this->_playerturn = 0 ;
    }
}

void Battle::round(){
    if (this->_playerturn == 1){
        int menuIndex ; 
        int actionIndex;
        int selectionIndex ; 
        while(1){ //Deemed necessary, player might return to menu selection menu
            try { 
                std::cout << "Escolha:" << std::endl << "[1] Feitiços" << std::endl << "[2] Poções" << std::endl ; 
                std::cin >> menuIndex ; 
                if (menuIndex == 1 ){ 
                    //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                    while(1){ //Done
                        try {
                            std::cout << "[0] "<<  "Voltar" << std::endl ;
                            _player->printPlayerSpells() ;
                             std::cin >> selectionIndex ; 
                            if ((selectionIndex > 0) && (selectionIndex <= _player->getSpellVector().size())){
           /*Fix it!!*/      // move(_player->getSpellVector()[selectionIndex-1]) ; 
                                return ;
                            } else if (selectionIndex == 0 ) {
                                break ;
                            } else throw std::invalid_argument("Seleção de feitiço invalida ") ;
                        } catch (std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }
                    }
                } else if (menuIndex == 2 ){ 
                        //idem pra pocoes
                } else { 
                    throw std::invalid_argument("Seleção de menu invalida") ; 
                }
                    
            } catch(std::invalid_argument &t) {
                std::cout << t.what() << std::endl;
            }

        }


    } else {
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }

}
