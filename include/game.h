#ifndef GAME_H
#define GAME_H

//#include "character.h"
//#include "wizard.h"
#include "spells.h"
#include "potions.h"
#include "artifacts.h"

#include <string>
#include <vector>

std::string texts1();
std::string choice_of_wand();
std::string choice_of_house();
std::string choice_of_patronum();
void initialize_player();
void texts2();
std::vector<Spell *> instantiate_spell();
std::vector<Artifacts *> instantiate_artifacts();
std::vector<Potions *> instantiate_potions();
#endif
