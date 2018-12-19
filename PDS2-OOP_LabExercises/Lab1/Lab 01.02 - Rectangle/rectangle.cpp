#include "rectangle.h"

Rectangle::Rectangle(float width,float height){
    this ->_height = height ;
    this ->_width = width ;
    
}

Rectangle::Rectangle(){
    this ->_height = 1;
    this ->_width = 1;
    
}

float Rectangle::get_height(){
    return _height ;
      
}
    
float Rectangle::get_width(){
   return _width ; 
}

void Rectangle::set_height( float height){
    this -> _height = height;
}

void Rectangle::set_width(float width){
    this -> _width = width;
}

float Rectangle::get_perimeter(){
    float perim ;
    perim = 2*(this ->_width) + 2*(this ->_height) ;
    return perim ;
}

float Rectangle::get_area(){
    float A ;
    A = (this ->_width)* (this ->_height) ;
    return A ;
    
}