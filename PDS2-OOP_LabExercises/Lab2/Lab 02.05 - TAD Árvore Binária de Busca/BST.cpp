
#include "node.h"
#include "listaencadeada.h"
#include "BST.h"

 BST::BST(){
    this->_raiz = nullptr;
    this->ListaVazia = nullptr ;
    this->_num_elementos_inseridos = 0;
}

BST::~BST(){
    if (this->_raiz != nullptr) delete this->_raiz;
    if (this->ListaVazia != nullptr) delete this->ListaVazia ;
}

void BST::inserir_elemento(int elemento){
    if (this->_raiz == nullptr) {
        this->_raiz = new Node(elemento);
        this->_num_elementos_inseridos++;
    } else if (!this->_raiz->existe_elemento(elemento)) {
        this->_raiz->inserir_elemento(elemento);
        this->_num_elementos_inseridos++;
    }
}

bool BST::existe_elemento(int elemento){
    if (this->_raiz == nullptr) return false;
    return this->_raiz->existe_elemento(elemento) ;
}

ListaEncadeada BST::pre_ordem(){
    if (this->_raiz != nullptr)
    return this->_raiz->pre_ordem()  ;
    else {
        this->ListaVazia = new ListaEncadeada ;
        return *(this->ListaVazia) ;
    }
}

ListaEncadeada BST::em_ordem(){
    if (this->_raiz != nullptr)
    return this->_raiz->em_ordem();
    else {
        this->ListaVazia = new ListaEncadeada ;
        return *(this->ListaVazia) ;
    }
}

ListaEncadeada BST::pos_ordem(){
    if (this->_raiz != nullptr)
    return this->_raiz->pos_ordem();
    else {
        this->ListaVazia = new ListaEncadeada ;
        return *(this->ListaVazia) ;
    }
    //else return *(new ListaEncadeada) ;
}
