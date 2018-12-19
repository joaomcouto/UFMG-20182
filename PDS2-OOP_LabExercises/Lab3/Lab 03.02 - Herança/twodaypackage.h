#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"
#include <string>

class TwoDayPackage : public Package {
private:
    double _taxafixa ;
public:
    TwoDayPackage(unsigned int peso, unsigned int custo,double taxafixa, std::string nome, std::string endereco);
    virtual double calculate_cost() ;
    ~TwoDayPackage();
};

#endif