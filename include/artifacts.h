#ifndef ARTIFACTS_H
#define ARTIFACTS_H

#include "objects.h"

class Artifacts : public Object{
protected:
    int _rounds;
    bool _exist;
    std::string special_effect;

public:
    Artifacts(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity, int round, bool exist, std::string effect);
    virtual ~Artifacts();
    std::string getSpecialEffect();
    bool get_exist();
    void set_exist();

};

#endif