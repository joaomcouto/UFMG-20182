#include "character.h"
#include "battle.h"

Battle::Battle(Character * player , Character * enemy){
    this->_round = 1 ;
    this->_ended = 0 ; 
    if (player->getDexterity() > enemy->getDexterity()){
        this->_playerturn = 1 ; 
    } else {
        this->_playerturn = 0 ;
    }
}

void Battle::round(){
    if (this->_playerturn == 1){
        //printa opcoes do player, chama funcao Action, modifica stats de um dos Character de acordo com _playerturn

    } else {
        //escolhe uma ação aleatoria, chama funcao Action para esta acao, modifica stats de um dos Character de acordo com _playerturn
    }

}