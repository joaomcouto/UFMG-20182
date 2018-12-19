
#include "twodaypackage.h"
#include <string>

TwoDayPackage::TwoDayPackage(unsigned int peso, unsigned int custo,double taxafixa, std::string nome, std::string endereco) : 
    Package(peso, custo, nome, endereco) , _taxafixa(taxafixa) {}

double TwoDayPackage::calculate_cost(){
    return (this->Package::calculate_cost() + _taxafixa) ;
}

TwoDayPackage::~TwoDayPackage(){
}