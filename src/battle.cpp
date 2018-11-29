#include "wizard.h"
#include "enemy.h"
#include "battle.h"
#include "spells.h"
#include "stats.h"
#include <iostream>
#include <string>

#define MAX_ROUNDS 20
#define MAX_HP 100

void myBattlePause(){
	do{
      std::cout << "Press ENTER  to continue!" << std::endl;
      std::cin.get();
    }while(std::cin.get() != '\n');
}

Battle::Battle(Wizard * player , Enemy * enemy){
    this->_round = 1; //Numero do round
    this->_ended = 0 ;  //Booleano de acabou
    this->_player = player ;  //Pointer para a instancia de player
    this->_enemy = enemy; //Pointer para a instancia de enermy
    this->_originalStats = player->getBaseStats();
    this->_originalStatsEnemy = enemy->getBaseStats();
    this->_olderHP = player->getHP();
    if (player->getDexterity() > enemy->getDexterity()){ //Define quem vai ter o primeiro turno
        this->_playerturn = 1 ;
    } else {
        this->_playerturn = 0 ;
    }
    Stats filler = {0,0,0,0,0,0} ;
    for ( int i = 0 ; i < MAX_ROUNDS ; i ++) {
        _playerDebuffs.push_back(filler);
        _enemyDebuffs.push_back(filler) ;
        _StatsPlayer.push_back(filler);
    }
    this->_StatsPlayer[_round-1] = player->getBaseStats();
    this->initializeBattle();
}

Battle::~Battle(){
    
}

void Battle::initializeBattle(){
    this->introduction();
    int _turn;
    int _turnOld;
    while((this->_player->getHP() > 0) && (this->_enemy->getHP() > 0)){
        _turn = this->round();
        _turn += _turnOld;
        this->_round+=1;
        if(this->_playerturn == 0) {
            _playerturn = 1  ;
        } else {
            _playerturn = 0 ;
        }
        if (_turn > 0)
            _playerturn = 1;
        _turnOld = _turn-1;
        if (_turnOld < 0)
            _turnOld = 0;
    }
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    if (this->_enemy->getHP() <= 0){
        std::cout << "You have won this battle! " << std::endl;
        if(_player->getLevel() < 6)
            _originalStats.level += 1 ;
    } else 
        std::cout << "You lost this battle! " << std::endl;
    myBattlePause();
    this->_player->setStats(this->_originalStats) ; 
    this->_player->incrementSkillPoints(1);
    this->_enemy->setStats(this->_originalStatsEnemy);
}

void Battle::spellMove(Spell* spell ){
    if (_playerturn == 1 ){
        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
        std::cout << "Player has used the spell " << spell->get_name() << "!" << std::endl;
        if ((_enemy->getName() == "Dementor")&&(spell->get_name() != "Expectro Patronum"))
            std::cout << "Spell wasn't effective, your enemy is a Dementor!" << std::endl;
        else{
            updateDebuffs(spell->getDuration() , spell->getDamageStats() , 0 ) ;
            _enemy->setHP( spell->get_hp_dmg()*(1 + 0.1*getCurrentPlayerStats().strenght)*(1 - 0.1*getCurrentEnemyStats().constitution) ) ;
            std::cout << "The enemy now has the following stats: " << std::endl ;
        }
        getCurrentEnemyStats().printStats() ;
        myBattlePause();
    } else {
        std::cout << "\033[2J\033[1;1H"; //This line clears the screen
        std::cout << "Enemy has used the spell " << spell->get_name() << "!" << std::endl;
        this->_StatsPlayer[_round-1] = getCurrentPlayerStats();
        updateDebuffs(spell->getDuration() , spell->getDamageStats() , 1 );
        _player->setHP( spell->get_hp_dmg()*(1 + 0.1*getCurrentEnemyStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
        std::cout << "The player now has the following stats: " << std::endl ;
        getCurrentPlayerStats().printStats();
        myBattlePause();
    }
}

void Battle::specialAttackMove(specialAttack _attack){
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Enemy has used the attack " << _attack._name << "!" << std::endl;
    this->_StatsPlayer[_round-1] = getCurrentPlayerStats();
    updateDebuffs(1, _attack._damageStats, 1);
    _player->setHP(_attack._damageStats.hp * (1 + 0.1*getCurrentEnemyStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
    std::cout << "The player now has the following stats: " << std::endl;
    getCurrentPlayerStats().printStats();
    myBattlePause();
}

void Battle::potionMove(Potions* potion){
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Player has used the potion " << potion->get_name() << "!" << std::endl;
    if ((potion->get_name() == "Antidote to spider poison")&&(_enemy->getType() != "spider")){
        std::cout << "Potion wasn't effective, your enemy is not a spider!" << std::endl;
        _round-=1;
    }
    else if ((potion->get_name() == "Antidote to serpent poison")&&(_enemy->getType() != "serpent")){
        std::cout << "Potion wasn't effective, your enemy is not a serpent!" << std::endl;
        _round-=1;
    }
    else {
        this->_StatsPlayer[_round-1] = getCurrentPlayerStats();
        updateDebuffs(potion->getDuration() , potion->getEffectsStats(), 1);
        _player->setHP(potion->get_hp_effect() * (1 + 0.1*getCurrentPlayerStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) ) ;
        std::cout << "The player now has the following stats: " << std::endl;
        getCurrentPlayerStats().printStats();
    }
    myBattlePause();
}

int Battle::artifactsMove(Artifacts * artifact){
    int i = 0;
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Player has used the artifact " << artifact->get_name() << "!" << std::endl;
    std::cout << "The player now has the following stats: " << std::endl;
    if (artifact->getSpecialEffect() == "return"){
        (this->_StatsPlayer[_round-2]).printStats();
        _player->setHP(_StatsPlayer[_round-2].hp-_player->getHP());
        setDebuffs(_StatsPlayer[_round-2]);
    } else {
        updateDebuffs(artifact->getDuration() , artifact->getEffectsStats(), 1);
        if (artifact->getSpecialEffect() == "life"){
            _player->setHP(MAX_HP -_player->getHP());
        } else {
            _player->setHP(artifact->get_hp_effect() * (1 + 0.1*getCurrentPlayerStats().strenght)*(1 - 0.1*getCurrentPlayerStats().constitution) );
        }
        getCurrentPlayerStats().printStats();
        if (artifact->getSpecialEffect() == "cloak"){
            i = 2;
            std::cout << std::endl;
            std::cout << "Voce sumiu para o inimigo, escolha sua proxima jogada" << std::endl;
        }
    }
    if (artifact->getSpecialEffect() == "damage"){
        std::cout << std::endl;
        std::cout << "Voce esta usando a varinha das varinhas, escolha a proxima jogada:" << std::endl;
        i = 1;
    }
    myBattlePause();
    return i;
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

void Battle::setDebuffs(Stats debuff){
    this->_playerDebuffs[_round-1] = debuff ; 
    this->_playerDebuffs[_round-1].hp = 0 ;
    this->_playerDebuffs[_round-1].mp = 0 ;
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
	if(this->_enemy == nullptr){
		throw NULL_Pointer_Exception();
	}
		
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

int Battle::round(){
    int aux = 0;
    if (this->_playerturn == 1){
        char menuIndex;
        //int actionIndex; //essa variavel ainda nao foi usada, tire o comentario quando for usar
        char selectionIndex ;
        while(1){ //Deemed necessary, player might return to menu selection menu
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                while(1){
                    try{
                        std::cout << "Make a choice:" << std::endl << "[1] Spells" << std::endl << "[2] Inventory" << std::endl ;
                        std::cin >> menuIndex ;
                        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                        if ((menuIndex == '1')||(menuIndex == '2'))
                            break;
                        else throw std::invalid_argument("Invalid menu index, try again ");
                    } catch(std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                    }
                }
                if (menuIndex == '1' ){
                    //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                    while(1){ 
                        try {
                            std::cout << "[0] "<<  "Back to main menu" << std::endl ;
                            _player->printPlayerSpells();
                            std::cin >> selectionIndex;
                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                            for (unsigned int i = 0; i <= _player->getSpellVector().size(); i ++){
                                if (selectionIndex == (char)(i+48)){
                                    spellMove(_player->getSpellVector()[i-1]) ;
                                    return aux;
                                }
                            }
                            if (selectionIndex == '0') 
                                break ;
                            else throw std::invalid_argument("Invalid spell index, try again ") ;
                        } catch (std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }
                    }
                } else if (menuIndex == '2'){
                    char secondaryMenuIndex ;
                    bool cond1 = 1;
                    while (cond1){
                        while(cond1){
                            try{
                                std::cout << "Make a choice:" << std::endl << "[0] Back to main menu" << std::endl << "[1] Potions" << std::endl << "[2] Artifacts" << std::endl;
                                std::cin>> secondaryMenuIndex ;
                                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                if ((secondaryMenuIndex == '1')||(secondaryMenuIndex == '2'))
                                    break;
                                else if ((secondaryMenuIndex == '0'))
                                    cond1 = 0;
                                else throw std::invalid_argument("Invalid spell index, try again ");
                            } catch (std::invalid_argument &t) {
                                std::cout << t.what() << std::endl;
                            }
                        }
                        if (secondaryMenuIndex == '1'){
                            char potionIndex ;
                            while(1){
                                try{
                                    std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                    _player->printPlayerPotions();
                                    std::cin >> potionIndex;
                                    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                    for (unsigned int i = 1; i <= _player->getPotionsVector().size(); i ++){
                                        if (potionIndex == (char)(i+48)){
                                            potionMove(_player->getPotionsVector()[i-1]);
                                            _player->set_quantPotions(i-1, -1);
                                            return 1;
                                        }
                                    }
                                        if (potionIndex == '0' ) 
                                            break ;
                                        else throw std::invalid_argument("Invalid potion index, try again ") ;

                                    } catch (std::invalid_argument &t) {
                                        std::cout << t.what() << std::endl;
                                    }
                                }
                            } else if (secondaryMenuIndex == '2' ){
                                char artifactsIndex ;
                                while(1){
                                    try{
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl;
                                        _player->printPlayerArtifacts();
                                        std::cin >> artifactsIndex;
                                        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                        for (unsigned int i = 1; i <= _player->getArtifactsVector().size(); i ++){
                                            if (artifactsIndex == (char)(i+48)){
                                                if((_player->getArtifactsVector()[i-1]->get_name() == "Time-Turner")&&(_round==1))
                                                    throw TimeTurnerException();
                                                aux = artifactsMove(_player->getArtifactsVector()[i - 1]);
                                                _player->set_existArtifacts(i - 1);
                                                if(_player->getArtifactsVector()[i-1]->get_exist() == 0){
                                                    this->_player->erase_Artifact(i-1);
                                                }
                                                return aux;
                                            }
                                        }
                                        if (artifactsIndex == '0' )
                                            break ;
                                        else throw std::invalid_argument("Invalid artifact index, try again ") ;
                                    } catch(std::exception &t){
                                        std::cout << t.what() << std::endl ;
                                    }
                                }
                            }
                    }
            }
        }
    } else {
        if (this->_enemy->getType() == "human"){
            int number_spell = rand() % this->_enemy->getSpellVector().size();
            spellMove(_enemy->getSpellVector()[number_spell]) ;
            return aux; 
        } else {
            specialAttackMove(_enemy->getSpecialAttack());
            return aux;
        }
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }
    return aux;
}
