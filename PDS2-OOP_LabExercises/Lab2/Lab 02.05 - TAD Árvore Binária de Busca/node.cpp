#include "node.h"
#include "listaencadeada.h"
#include "BST.h"

Node::Node(int valor){
    this->_elemento = valor ;
    this->_esquerda = nullptr;
    this->_direita = nullptr;
}

Node::~Node(){
    if(this->_esquerda != nullptr) delete this->_esquerda ;
    if(this->_direita != nullptr) delete this->_direita ;
}


bool Node::existe_elemento(int elemento) {
  if (this->_elemento == elemento) {
    return true;
  } else if (elemento < this->_elemento) {
    if (this->_esquerda == nullptr) {
      return false;
    } else {
      return this->_esquerda->existe_elemento(elemento);
    }
  } else {
    if (this->_direita == nullptr) {
      return false;
    } else {
      return this->_direita->existe_elemento(elemento);
    }
  }
}

/*
void Node::inserir_elemento(int valor){
    if (valor > this->_elemento){
        if (this->_direita==nullptr) this->_direita= new Node(valor);
        else  this->_direita->inserir_elemento(valor) ;
    } else if(valor < this->_elemento) {
        if (this->_esquerda==nullptr) this->_esquerda = new Node(valor) ;
        else this->_esquerda->inserir_elemento(valor) ;
    }
}
*/
void Node::inserir_elemento(int elemento) {
  if (elemento < this->_elemento) {
    if (this->_esquerda == nullptr) {
      this->_esquerda = new Node(elemento);
    } else {
      this->_esquerda->inserir_elemento(elemento);
    }
  } else if (elemento > this->_elemento) {
    if (this->_direita == nullptr) {
      this->_direita = new Node(elemento);
    } else {
      this->_direita->inserir_elemento(elemento);
    }
  }
}

ListaEncadeada Node::pre_ordem(){
    ListaEncadeada * l = new ListaEncadeada() ;
    this->pre2(*l);
    return *l ;
}

ListaEncadeada Node::em_ordem(){
    ListaEncadeada * l = new ListaEncadeada() ;
    this->em2(*l) ;
    return *l ;
}

ListaEncadeada Node::pos_ordem(){
    ListaEncadeada * l = new ListaEncadeada() ;
    this->pos2(*l) ;
    return *l ;
}

void Node::pre2(ListaEncadeada &l){
    l.insere_elemento(this->_elemento) ;
    if (this->_esquerda != nullptr) this->_esquerda->pre2(l);
    if (this->_direita != nullptr) this->_direita->pre2(l) ;

}

void Node::em2(ListaEncadeada &l){
    if (this->_esquerda != nullptr)  this->_esquerda->em2(l);
    l.insere_elemento(this->_elemento) ;
    if (this->_direita != nullptr) this->_direita->em2(l);

}


void Node::pos2(ListaEncadeada &l){
    if (this->_esquerda != nullptr) this->_esquerda->pos2(l);
    if (this->_direita != nullptr) this->_direita->pos2(l) ;
    l.insere_elemento(this->_elemento) ;

}
