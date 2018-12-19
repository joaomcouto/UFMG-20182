#ifndef EXCECOES_H
#define EXCECOES_H
#include <stdexcept>

class PosicaoInvalidaException: public std::exception{
    public:
    virtual const char* what() const noexcept override ;
};

class MovimentoInvalidoException : public std::exception{
    public:
    virtual const char* what() const noexcept override ;
};

class PosicaoSemPecaException: public std::exception{
    public:
    virtual const char* what() const noexcept override ;
};


#endif