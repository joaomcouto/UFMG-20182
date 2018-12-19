#include <iostream>
#include "listaencadeada.h"


int main(){


    std::cout << "Use o main para testar seu código" << std::endl;
    ListaEncadeada l;
    l.insere_elemento(20);
    std::cout<<l.get_iesimo(0) << std::endl ;


    return 0;
}
