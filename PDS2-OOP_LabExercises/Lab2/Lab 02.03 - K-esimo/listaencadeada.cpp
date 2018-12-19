#include "listaencadeada.h"
#include <iostream>

void ListaEncadeada::insere_elemento(int n) {
    node_t * novo = new node_t() ;
    //node_t * novo = new node_t ;
    novo->elemento = n ;
    novo->prox = nullptr;
    novo->ant = nullptr;
    if(this->_inicio == nullptr){
        this->_inicio = novo ;
        this->_fim = novo ;
    } else{
        this->_fim->prox = novo ;
        novo->ant = this->_fim ;
        this->_fim = novo ;
    }
    this->_numinseridos += 1 ;
}


void ListaEncadeada::insere_primeiro(int n) {
    node_t * novo = new node_t() ;
    //node_t * novo = new node_t ;
    novo->elemento = n ;
    novo->prox = nullptr;
    novo->ant = nullptr;
    if(this->_inicio == nullptr){
        this->_inicio = novo ;
        this->_fim = novo ;
    } else {
    novo->prox = this->_inicio ;
    this->_inicio->ant = novo ;
    this->_inicio = novo ;
    }
}

int ListaEncadeada::get_iesimo(int i) {
    if(i >= _numinseridos ){
        return 0 ;
    }
    node_t * current = this->_inicio ;
    int j ;
    for (j = 0 ; j < i ; j++ ){
        current = current->prox ;
    }
    return current->elemento ;

}

void ListaEncadeada::remover_elemento() { //Remove o ultimo
    if (this->_fim == nullptr){
        return ;
    }
    if (this->_fim == this->_inicio){
        delete this->_fim ;
        this->_fim = nullptr;
        this->_inicio = nullptr;
        this->_numinseridos-- ;
        return ;
    }
    node_t * temp ;
    this->_fim->ant->prox = nullptr ;
    temp = this->_fim ;
    this->_fim = this->_fim->ant ;
    delete temp ;
}

void ListaEncadeada::remover_primeiro() { //Remove o primeiro
    if (this->_inicio == nullptr){
        return ;
    }
    if (this->_fim == this->_inicio){
        delete this->_inicio ;
        this->_fim = nullptr;
        this->_inicio = nullptr;
        this->_numinseridos-- ;
        return ;
    }
    node_t * temp ;
    this->_inicio->prox->ant = nullptr ;
    temp = this->_inicio ;
    this->_inicio = this->_inicio->prox ;
    delete temp ;

}

void ListaEncadeada::inserir_iesimo(int n , int i) {
    if (i >= this->_numinseridos){
        return ;
    }

    node_t * current = this->_inicio ;
    int j ;

    for (j = 0 ; j < i ; j++){
        current = current->prox ;
    }

    node_t * novo = new node_t() ;
    novo->elemento = n ;
    if (current->ant != nullptr){
        current->ant->prox = novo ;
        novo->ant = current->ant ;
        novo->prox = current ;
        current->ant = novo ;
    } else {
        novo->prox = current;
        novo->ant = nullptr ;
        this->_inicio = novo ;

    }
}

void ListaEncadeada::remover_iesimo(int i ) {
    if (i >= this->_numinseridos) {
        return;
  }
    node_t *current = this->_inicio;
    for (int j = 0; j < i; j++){
        current = current->prox;
    }

    if (current->prox != nullptr){
        current->prox->ant = current->ant;
    } else {
        this->_fim = current->ant;
    }

    if (current->ant != nullptr){
        current->ant->prox = current->prox;
    } else {
        this->_inicio = current->prox ;
    }
    this->_numinseridos--;
    delete current;

}

int ListaEncadeada::tamanho(){
    return this->_numinseridos ;
}

ListaEncadeada::ListaEncadeada(){
    this->_inicio = nullptr ;
    this->_fim = nullptr ;
    this->_numinseridos = 0 ;
}
ListaEncadeada::~ListaEncadeada(){
  node_t *prev = nullptr;
  node_t *current = this->_inicio;
  while (current != nullptr) {
    prev = current;
    current = current->prox;
    delete prev ;
  }
}
void ListaEncadeada::remove_consecutivos(){
    node_t * current = this->_inicio ;
    int i ;
    int aux ;
    int num = 0 ;
    aux  = this->_numinseridos -1 ;
    for ( i = 0 ; i < aux -1 ; i++ ){
        this->imprimir() ;
        std::cout << std::endl ;
        //std::cout << std::endl ;
        //std::cout << "CURRENT ELEMENTO: " <<current->elemento << " " ;
        //std::cout << "PREV ELEMENT: "<< current->ant->elemento << std::endl ;
        if (current->elemento == current->prox->elemento){
            this->remover_iesimo(i + 1 - num) ;
            num++ ;
        }
        current = current->prox ;
    }

}



void ListaEncadeada::imprimir(){
    node_t * current = this->_inicio;
    int i ;
    for ( i = 0 ; i < this->_numinseridos ; i++ ){
        std::cout << current->elemento  << " " ;
        current = current->prox ;
    }
}

int ListaEncadeada::k_esimo(bool direcao, int k) {
    if(k >= _numinseridos || k <0){
        return 0 ;
    }
    node_t * current ;
    int j ;
    if (direcao == true){
        current = this->_inicio ;
        for (j = 0 ; j < k ; j++ ){
            current = current->prox ;
        }
    } else {
        current = this->_fim ;
        for (j = 0 ; j < k ; j++){
            current = current->ant ;
        }
    }
    return current->elemento ;
}


