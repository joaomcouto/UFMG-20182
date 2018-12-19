#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

/*
  usem a struct 'node_t' para criar o atributo nó da lista. Notem que ela possui um campo inteiro
  e um ponteiro para o próximo nó. A lista deve conter referências para o primeiro
  e último nós. A lista deve conter métodos para:
   (a) insere_elemento(int). Insere um elemento no fim da lista.
   (b) insere_primeiro(int). Insere um elemento no inicio da lista.
   (c) get_iesimo(int). Retorna um elemento na posição i.
   (d) remover_elemento(). Remove um elemento no fim da lista.
   (e) remover_primeiro(). Remove o primeiro elemento da lista.
   (f) inserir_iesimo(int, int). Insere um elemento na posicão i.
   (g) remover_iesimo(int). Remove um elemento na posição i
   (h) tamanho(). Retorna o tamanho da lista.
*/

struct node_t {
	int elemento;
	node_t * prox;
	node_t * ant;
};

class ListaEncadeada {
    private:
        node_t * _inicio ;
        node_t * _fim ;
    public:
        int _numinseridos ;
        ListaEncadeada();
        ~ListaEncadeada();
        void insere_elemento(int n) ;//Insere um elemento no fim da lista.
        void insere_primeiro(int n) ; //Insere um elemento no inicio da lista.
        int get_iesimo(int i) ; //Retorna um elemento na posicao i.
        void remover_elemento() ; // Remove um elemento no fim da lista.
        void remover_primeiro() ; //Remove o primeiro elemento da lista.
        void inserir_iesimo(int n , int i) ; //Insere um elemento na posicao i.
        void remover_iesimo(int i ) ; //Remove um elemento na posicao i.
        void remove_consecutivos();
        int tamanho() ;
        void imprimir();
        int k_esimo(bool direcao, int k) ;



};

#endif /* LISTAENCADEADA_H_ */
