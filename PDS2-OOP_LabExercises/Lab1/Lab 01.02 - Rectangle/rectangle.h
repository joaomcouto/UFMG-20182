#ifndef PDS2_VPL_RECT_H
#define PDS2_VPL_RECT_H

class Rectangle {
private:
    float _height;
    float _width;
public:
    Rectangle();
    Rectangle(float height, float width);
    float get_height();
    float get_width();
    void set_height(float);
    void set_width(float);
    float get_perimeter();
    float get_area();
};
#endif