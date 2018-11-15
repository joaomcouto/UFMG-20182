#include <iostream>	
#include <time.h>
#include "game.h"

int main (){
	srand (time(NULL));
	std::vector<Spell *> spell = instantiate_spell();
	std::vector<Potions *> potion = instantiate_potions();
	std::vector<Artifacts *> artifact = instantiate_artifacts();
	Wizard *player = initialize_player(spell, potion, artifact);
	
	return 0;
}
