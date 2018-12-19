#include "package.h"
#include <string>

Package::Package(unsigned int peso, unsigned int custo, std::string nome, std::string endereco) {
    _peso = peso ;
    _custoporquilo = custo ;
    _nome = nome ;
    _endereco = endereco ;
}

double Package::calculate_cost(){
    return (_peso*_custoporquilo) ;
}

std::string Package::get_nome(){
    return (this->_nome);
}

unsigned int Package::get_peso(){
    return this->_peso ; 
}

unsigned int Package::get_custo_por_quilo(){
    return (this->_custoporquilo) ;
}

Package::~Package(){
}