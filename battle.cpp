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
        //selecao inter-menus
        while(1){ //Deemed necessary, player might return to menu selection menu
            int menuIndex ; 
            int actionIndex;
            int selectionIndex ; 
            std::cout << "Mostrar:" << std::endl << "[1] Feitiços" << std::endl << "[2] Poções" << std::endl ; 
            std::cin >> menuIndex ; 
            if (menuIndex == 1 ){ 
                //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                int i = 0 ;
                std::cout << "[" << i << "] "<<  "Voltar" << std::endl ;
                i++ ;
                for ( Spell* spell : _player->getSpellVector()){
                    std::cout << "[" << i << "] "<< spell->get_name() << std::endl;
                    i++ ;
                }
                std::cin >> selectionIndex ; 
                if (selectionIndex > 0 && selectionIndex < _player->getSpellVector().size()) move(_player->getSpellVector()[selectionIndex-1]) ; //Move() implementation is still undone
            }
            if (menuIndex == 2 ){ //idem pra pocoes

            }
        }


    } else {
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }

}