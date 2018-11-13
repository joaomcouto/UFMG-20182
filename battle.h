#include "character.h"
#include "wizard.h"

class Battle {
protected:
    int _round ; 
    bool _ended ; 
    bool _playerturn ; 
    Character * player ; 
    Character * enemy ; 

public:
    Battle(Wizard * player , Character * enemy) ;
    void round() ; 



};