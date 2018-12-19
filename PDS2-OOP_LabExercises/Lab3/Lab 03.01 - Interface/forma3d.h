#ifndef FORMA3D_H
#define FORMA3D_H

#include <string>
#include "forma.h"

class Forma3D : public Forma{
public:     
    virtual double get_volume() = 0 ;
};


#endif
