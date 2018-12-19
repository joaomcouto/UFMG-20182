
#include "overnightpackage.h"
#include <string>

OverNightPackage::OverNightPackage(unsigned int peso, unsigned int custo,double taxaadd, std::string nome, std::string endereco) : 
    Package(peso, custo, nome, endereco) , _taxaadd(taxaadd) {}

double OverNightPackage::calculate_cost(){
  //  return (this->Package::calculate_cost() + _taxaadd) ;
  return (_peso*(_custoporquilo +_taxaadd));
}


OverNightPackage::~OverNightPackage(){
}