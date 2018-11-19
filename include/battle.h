#include "enemy.h"
#include "wizard.h"
#include "spells.h"
#include "stats.h"
#include <map>

class Battle {
protected:
    int _round ; 
    bool _ended ; 
    bool _playerturn ; 
    Stats _originalStats ;
    std::vector<Stats> _playerDebuffs ; //cada posicao i se refere a um round
    std::vector<Stats> _enemyDebuffs ;
    int _olderHP;
    Wizard * _player ; 
    Enemy * _enemy ; 

public:
    Battle(Wizard * player , Enemy * enemy) ;
    virtual ~Battle();
    void spellMove(Spell * spell);
    void specialAttackMove(specialAttack _attack);
    void potionMove(Potions * potion) ;
    bool artifactsMove(Artifacts * artifact);
    void round() ; 
    void updateDebuffs(int duration, Stats debuff, bool actOnPlayer);
    void initializeBattle() ;
    void introduction() ; 
    Stats getCurrentPlayerStats() ;
    Stats getCurrentEnemyStats() ;
    Stats getOlderPlayerStats(int olderHP);



};