#include "character.h"
#include "wizard.h"
#include "spells.h"
#include "stats.h"

class Battle {
protected:
    int _round ; 
    bool _ended ; 
    bool _playerturn ; 
    Stats _originalStats ;
    Wizard * _player ; 
    Enemy * _enemy ; 

public:
    Battle(Wizard * player , Enemy * enemy) ;
    void spellMove(Spell * spell);
    void round() ; 
    void initializeBattle() ;
    void introduction() ; 



};