#include "destinationpackages.h"
#include "package.h"
#include <string>
#include <map>
#include <vector>

void DestinationPackages::add_package(Package * g){
    this->m[g->get_nome()].push_back(g) ;
    
}

int DestinationPackages::custo_total(){
    std::map<std::string,std::vector<Package*>>::iterator it ;
    double custototal ;
    double custo = 0 ;
    for (it = m.begin() ; it != m.end() ; it++){
        custo = 0 ;
        for (Package* n: it->second){
            custo += n->calculate_cost();
        }
        custototal += custo ;
    }
    return custototal ; 
    
}


double DestinationPackages::custo_total(std::string nome){
    int custo = 0;
    for (Package* n : m[nome]){
        custo += n->calculate_cost() ;
    }
    return custo;
}

DestinationPackages::DestinationPackages(){
    m.clear() ; 
}

/*DestinationPackages::~DestinationPackages(){
    std::map<std::string,std::vector<Package*>>::iterator it ;
    for (it = m.begin() ; it != m.end() ; it++){
        for (Package* n: it->second){
            delete n ;
        }
    }
}*/