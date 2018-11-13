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
        while(1){ //necessario pois jogador pode decidir voltar para o menu de menus
            int menuIndex ; 
            int actionIndex;
            int selectionIndex ; 
            std::cout << "Mostrar:" << std::endl << "[1] Feitiços" << std::endl << "[2] Poções" << std::endl ; 
            std::cin >> menuIndex ; 
            if (menuIndex == 1 ){ 
                //printa opcoes de feiticos e opcao de voltar pro menu de menus, caso o jogador escolha um feitico, chamar action() com aquele feitico e acabar o round
                int i ;
                i = 0 ;
                for ( Spell spell : _player->spellVector){

                }

            
                std::cin >> selectionIndex ; 

            }
            if (menuIndex == 2 ){ //idem pra pocoes
            }
        }


    } else {
        //escolhe uma ação aleatoria, chama funcao Action para esta acao, modifica stats de um dos Character de acordo com _playerturn
    }

}