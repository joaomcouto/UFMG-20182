#include "artifacts.h"

Artifacts::Artifacts(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity, int round, bool exist, std::string effect):
    Object(name, _level, _hp, _mp, _strenght, _constituion, _dexterity), _rounds(round), _exist(exist), special_effect(effect){}

Artifacts::~Artifacts(){

}

bool Artifacts::get_exist(){
    return _exist;
}