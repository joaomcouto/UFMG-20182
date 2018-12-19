#ifndef PDS2_AQUECEDOR_H
#define PDS2_AQUECEDOR_H

// Nome dos metodos:
// aquecer()
// resfriar()
// get_temperatura()

class Aquecedor{
private:
    double _tempmax ;
    double _tempmin ;
    double _temperatura ;
    double _fator;
public:
    Aquecedor(double inicial) ;
    Aquecedor(double inicial, double fator);
    Aquecedor();
    void aquecer();
    void resfriar();
    double get_temperatura();
};

#endif
