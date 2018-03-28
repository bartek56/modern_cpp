#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other)=default;
		Circle(double r, Colors c);
    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;
		Circle()=delete; 
private:
   // doesn't allow to call default constructor

    double r_;
};
