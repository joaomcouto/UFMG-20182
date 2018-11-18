#include "wizard.h"
#include "enemy.h"
#include "battle.h"
#include "spells.h"
#include "stats.h"
#include <iostream>
#include <string>

void myBattlePause(){
	{
	    std::cout << "Press any character followed by ENTER to continue" << std::endl ;
	    std::string hold ; 
	    std::cin >> hold ;
    }
}

Battle::Battle(Wizard * player , Enemy * enemy){
    this->_round = 1 ; //Numero do round
    this->_ended = 0 ;  //Booleano de acabou
    this->_player = player ;  //Pointer para a instancia de player
    this->_enemy = enemy; //Pointer para a instancia de enermy
    this->_originalStats = player->getBaseStats() ;
    if (player->getDexterity() > enemy->getDexterity()){ //Define quem vai ter o primeiro turno
        this->_playerturn = 1 ;
    } else {
        this->_playerturn = 0 ;
    }
    Stats filler = {0,0,0,0,0,0} ;
    for ( int i = 0 ; i < 20 ; i ++) {
        _playerDebuffs.push_back(filler);
        _enemyDebuffs.push_back(filler) ;
    }
    this->initializeBattle() ;
}

void Battle::initializeBattle(){
    this->introduction();
    while((this->_player->getHP() > 0) && (this->_enemy->getHP() > 0)){
        this->round() ;
        if(this->_playerturn == 0) {
            _playerturn = 1  ;
        } else {
            _playerturn = 0 ;
        }
    }
    _originalStats.level += 1 ;
    this->_player->setStats(this->_originalStats) ; 
    this->_player->incrementSkillPoints(1);
}

void Battle::spellMove(Spell* spell ){
    if (_playerturn == 1 ){
        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
        std::cout << "Player has used the spell " << spell->get_name() << "!" << std::endl;
        updateDebuffs(spell->getDuration() , spell->getDamageStats() , 0 ) ;
        _enemy->setHP( spell->get_hp_dmg()*(1 + 0.1*getCurrentPlayerStats().strenght)*(1 - 0.1*getCurrentEnemyStats().constitution) ) ;
        std::cout << "The enemy now has the following stats: " << std::endl ;
        getCurrentEnemyStats().printStats() ;
        myBattlePause();
    } else {
        //std::cout << "\033[2J\033[1;1H"; //This line clear the screen
        //std::cout << "Enemy has used the spell " << spell->get_name() << ", for the following damage" << std::endl;
        //_player->setHP( spell->get_hp_dmg()*(1 + 0.1*currentEnemyStats.strenght)*(1 - 0.1*currentPlayerStats.constitution) ) ;
        //updateDebuffs(spell->getDuration() , spell->getDamageStats()) ;
        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
        std::cout << "Enemy has used the spell " << spell->get_name() << "!" << std::endl;
        updateDebuffs(spell->getDuration() , spell->getDamageStats() , 1 ) ;
        _player->setHP( spell->get_hp_dmg()*(1 + 0.1*getCurrentEnemyStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
        std::cout << "The player now has the following stats: " << std::endl ;
        getCurrentPlayerStats().printStats() ;
        myBattlePause();
    }
}

void Battle::specialAttackMove(specialAttack _attack){
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Enemy has used the attack " << _attack._name << "!" << std::endl;
    updateDebuffs(1, _attack._damageStats, 1);
    _player->setHP(_attack._damageStats.hp * (1 + 0.1*getCurrentEnemyStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
    std::cout << "The player now has the following stats: " << std::endl;
    getCurrentPlayerStats().printStats();
    myBattlePause();
}

void Battle::potionMove(Potions* potion){
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Player has used the potion " << potion->get_name() << "!" << std::endl;
    updateDebuffs(potion->getDuration() , potion->getEffectsStats(), 1);
    _player->setHP(potion->get_hp_effect() * (1 + 0.1*getCurrentPlayerStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
    std::cout << "The player now has the following stats: " << std::endl;
    getCurrentPlayerStats().printStats();
    myBattlePause();
}

void Battle::updateDebuffs(int duration, Stats debuff, bool actOnPlayer) {
    if (actOnPlayer == 0 )
        for (int i = _round-1 ; i <= _round+duration-1 ; i++){
            this->_enemyDebuffs[i] += debuff ; 
            this->_enemyDebuffs[i].hp = 0 ;
            this->_enemyDebuffs[i].mp = 0 ; 
            
        }
    else
        for (int i = _round-1 ; i <= _round+duration-1 ; i++){
            this->_playerDebuffs[i] += debuff ; 
            this->_playerDebuffs[i].hp = 0 ;
            this->_playerDebuffs[i].mp = 0 ;
        }
    }

Stats Battle::getCurrentPlayerStats(){
    Stats currentPlayerStats = (this->_playerDebuffs[_round-1] + _player->getBaseStats()) ;
    return currentPlayerStats ;

}

Stats Battle::getCurrentEnemyStats(){
    Stats currentEnemyStats = (this->_enemyDebuffs[_round-1] + _enemy->getBaseStats()) ;
    std::cout << "\n" ;
    return currentEnemyStats ;
}


void Battle::introduction(){
    this->_enemy->printIntro() ;
    std::cout << " " << std::endl; 
    myBattlePause();
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Get ready to battle!\nYour opponent is: " << this->_enemy->getName()  << std::endl ;
    std::cout << "They are of type " << this->_enemy->getType() << std::endl ; 
    std::cout << "Their stats are:\n" ;
    this->_enemy->printStats() ;
    myBattlePause();
}

void Battle::round(){
    if (this->_playerturn == 1){
        unsigned int menuIndex ;
        //int actionIndex; //essa variavel ainda nao foi usada, tire o comentario quando for usar
        unsigned int selectionIndex ;
        while(1){ //Deemed necessary, player might return to menu selection menu
            try {
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                std::cout << "Make a choice:" << std::endl << "[1] Spells" << std::endl << "[2] Inventory" << std::endl ;
                std::cin >> menuIndex ;
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                if (menuIndex == 1 ){
                    //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                    while(1){ //Done
                        try {
                            std::cout << "[0] "<<  "Back to main menu" << std::endl ;
                            _player->printPlayerSpells();
                            std::cin >> selectionIndex ;
                            if ((selectionIndex > 0) && (selectionIndex <= _player->getSpellVector().size())){
                                spellMove(_player->getSpellVector()[selectionIndex-1]) ;
                                return ;
                            } else if (selectionIndex == 0 ) {
                                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                break ;
                            } else throw std::invalid_argument("Invalid spell index, try again ") ;
                        } catch (std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }
                    }
                } else if (menuIndex == 2 ){
                    unsigned int secondaryMenuIndex ;
                    while (1){
                        try{
                            std::cout << "Make a choice:" << std::endl << "[0] Back to main menu" << std::endl << "[1] Potions" << std::endl << "[2] Artifacts" << std::endl;
                            std::cin>> secondaryMenuIndex ;
                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                            if (secondaryMenuIndex == 0){
                                break ;
                            } else if (secondaryMenuIndex == 1){
                                unsigned int potionIndex ;
                                while(1){
                                    try{
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        _player->printPlayerPotions();
                                        std::cin >> potionIndex;
                                        if ((potionIndex > 0) && (potionIndex <= _player->getPotionsVector().size())){
                                            potionMove(_player->getPotionsVector()[potionIndex-1]);
                                            _player->set_quantPotions(potionIndex-1, -1);
                                            if (_player->getPotionsVector()[potionIndex-1]->get_quant() == 0) {
                                                this->_player->erase_Potion(potionIndex-1);
                                            }
                                            break ;
                                        } else if (potionIndex == 0 ) {
                                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                            break ;
                                        } else throw std::invalid_argument("Invalid potion index, try again ") ;
                                    } catch (std::invalid_argument &t) {
                                        std::cout << t.what() << std::endl;
                                    }
                                }
                                break;
                            } else if (secondaryMenuIndex == 2 ){
                                unsigned int artifactsIndex ;
                                while(1){
                                    try{
                                        _player->printPlayerArtifacts();
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        std::cin >> artifactsIndex;
                                        if ((artifactsIndex > 0) && (artifactsIndex <= _player->getArtifactsVector().size())){
                                            //move(_player->getArtifactsVector()[artifactsIndex-1]) ;
                                            
                                            return ;
                                        } else if (artifactsIndex == 0 ) {
                                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                            break ;
                                        } else throw std::invalid_argument("Invalid artifact index, try again ") ;
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
            spellMove(_enemy->getSpellVector()[number_spell]) ;
            return; 
        } else {
            specialAttackMove(_enemy->getSpecialAttack());
            return;
        }
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }

}
