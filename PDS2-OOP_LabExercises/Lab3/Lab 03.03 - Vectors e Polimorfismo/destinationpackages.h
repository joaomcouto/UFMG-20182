#ifndef DESTINATIONPACKAGES_H
#define DESTINATIONPACKAGES_H

#include "package.h"
#include <string>
#include <map>
#include <vector>

class DestinationPackages {
protected:
    std::map<std::string,std::vector<Package*>> m ;
public:
    DestinationPackages();
    void add_package(Package*g);
    int custo_total();
    double custo_total(std::string nome);
    //~DestinationPackages();
} ;

#endif