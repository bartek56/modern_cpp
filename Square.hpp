#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other)=default;

    double getArea() const ;
    double getPerimeter() const;
    void print() const;

};
