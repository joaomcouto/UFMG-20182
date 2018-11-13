#include "character.h"

class Battle {
protected:
    int _round ; 
    bool _ended ; 
    bool _playerturn ; 
    Character * player ; 
    Character * enemy ; 

public:
    Battle(Character * player , Character * enemy) ;
    void round() ; 



};