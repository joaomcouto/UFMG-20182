#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H


#include "package.h"
#include <string>

class OverNightPackage : public Package {
private:
    double _taxaadd ;
public:
    OverNightPackage(unsigned int peso, unsigned int custo, double taxaadd, std::string nome, std::string endereco);
    virtual double calculate_cost() ;
    ~OverNightPackage();
};

#endif