#ifndef ARTIFACTS_H
#define ARTIFACTS_H

#include "objects.h"

class Artifacts : public Object{
protected:
    int _rounds;
    bool _exist;
private:
    Artifacts(std::string name, int _level, int _hp, int _mp,  int _strenght, int _constituion, int _dexterity, int round, bool exist);
    virtual ~Artifacts();

};

#endif