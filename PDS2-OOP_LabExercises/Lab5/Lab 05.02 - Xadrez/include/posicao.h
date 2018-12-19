#ifndef POSICAO_H
#define POSICAO_H

class Posicao {
    protected:
        int _x;
        int _y;
    public:
        int get_x() ;
        int get_y() ;
        Posicao(int x, int y);
        void set_posicao(int x, int y); 
        //bool operator<(const Posicao &segundo) ;
        
    bool operator<(const Posicao& Outro ) const {
        if ( Outro._y <  this->_y ) return true;
        if ( ( Outro._y == this->_y ) && ( Outro._x < this->_x ) ) return true;
        return false;
    }
} ;

#endif