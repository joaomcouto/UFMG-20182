#include "enemy.h"
#include "wizard.h"
#include "spells.h"
#include "stats.h"
#include <map>

class Battle {
protected:
    int _round ; //contador de rodadas
    bool _ended ; //se acabou a batalha
    bool _playerturn ; //se é vez do jogador
    Stats _originalStats ;
    Stats _originalStatsEnemy ;
    std::vector<Stats> _playerDebuffs ; //cada posicao i se refere a um round
    std::vector<Stats> _enemyDebuffs ;
    std::vector<Stats> _StatsPlayer;
    int _olderHP;
    Wizard * _player ; 
    Enemy * _enemy ; 

public:
    Battle(Wizard * player , Enemy * enemy) ;
    virtual ~Battle();
    void spellMove(Spell * spell);
    void specialAttackMove(specialAttack _attack);
    void potionMove(Potions * potion) ;
    int artifactsMove(Artifacts * artifact);
    int round() ; 
    void updateDebuffs(int duration, Stats debuff, bool actOnPlayer);
    void setDebuffs(Stats debuff);
    void initializeBattle() ;
    void introduction() ; 
    Stats getCurrentPlayerStats() ;
    Stats getCurrentEnemyStats() ;


};
