#include "character.h"
#include "wizard.h"

class Battle {
protected:
    int _round ; 
    bool _ended ; 
    bool _playerturn ; 
    Wizard * _player ; 
    Enemy * _enemy ; 

public:
    Battle(Wizard * player , Enemy * enemy) ;
    void round() ; 



};