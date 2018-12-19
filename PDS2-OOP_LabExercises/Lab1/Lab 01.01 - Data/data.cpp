#include "data.h"
Data::Data(int dia, int mes, int ano){
    _dia = dia ;
    _mes = mes ;
    _ano = ano ;
}

int Data::get_dia(){
    return _dia ;
}

int Data::get_mes(){
    return _mes ;
}

int Data::get_ano(){
    return _ano ;
}

std::string Data::get_data_curto(){
    std::string sdia = std::to_string(this->get_dia()) ;
    std::string smes = std::to_string(this->get_mes()) ;
    std::string sano = std::to_string(this->get_ano()) ;
    
    std::string resultado = sdia + "/" + smes + "/" + sano ;
    // return = << data.get_dia() << "/" << data.get_mes() << "/" << data.get_ano() << std::endl;
    return resultado ;
}
std::string Data::get_data_longo(){
    std::string mes[12] = {"janeiro", "fevereiro", "marco" , "abril" , "maio", "junho" , "julho", "agosto", "setembro", "outubro", "novembro", "dezembro" }; 
    std::string sdia = std::to_string(this->get_dia()) ;
    std::string sano = std::to_string(this->get_ano()) ;
    std::string resultado = sdia + " de " + mes[this->get_mes()-1] + " de " + sano ;
    return resultado ;
}