#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
protected:
    std::string _nome ;
    std::string _endereco ;
    unsigned int _peso ;
    unsigned int _custoporquilo ;
public:
    Package(unsigned int peso, unsigned int custo, std::string nome, std::string endereco) ;
    virtual double calculate_cost();
    std::string get_nome();
    unsigned int get_peso();
    unsigned int get_custo_por_quilo();
    virtual ~Package(); 
    
};

#endif