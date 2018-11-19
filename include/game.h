#ifndef GAME_H
#define GAME_H

#include "wizard.h"
#include "enemy.h"
#include "spells.h"
#include "potions.h"
#include "artifacts.h"

#include <string>
#include <vector>

void myPause() ;

std::string texts1();
std::string choice_of_wand();
std::string choice_of_house();
std::string choice_of_patronum();
Wizard* initialize_player(std::vector<Spell *> _spells, std::vector<Potions *> _potions, std::vector<Artifacts *> _artifacts);
void texts2();
std::vector<Spell *> instantiate_spell();
std::vector<Artifacts *> instantiate_artifacts();
std::vector<Potions *> instantiate_potions();
std::vector<specialAttack > instantiate_attack();
std::vector<Enemy *> initialize_enemy(std::vector<Spell *> _spells, std::vector<specialAttack> attack);
void initialize_game();
#endif
