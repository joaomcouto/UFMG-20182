#include "character.h"
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
    Wizard * _player ; 
    Enemy * _enemy ; 

public:
    Battle(Wizard * player , Enemy * enemy) ;
    void spellMove(Spell * spell);
    void round() ; 
    void initializeBattle() ;
    void introduction() ; 



};