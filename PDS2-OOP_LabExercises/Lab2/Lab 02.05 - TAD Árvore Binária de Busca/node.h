#ifndef PDS2_NODE_H
#define PDS2_NODE_H
#include "listaencadeada.h"

class Node {
private:
    Node * _esquerda;
    Node * _direita;
    int _elemento;
    
public:
    
    Node(int valor);
    ~Node();
    void inserir_elemento(int elemento);
    bool existe_elemento(int elemento);
    ListaEncadeada pre_ordem();
    ListaEncadeada em_ordem();
    ListaEncadeada pos_ordem() ;
    void pos2(ListaEncadeada &l) ;
    void em2(ListaEncadeada &l) ;
    void pre2(ListaEncadeada &l) ;
};
#endif
