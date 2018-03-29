#include "Shape.hpp"
#include <iostream>

Shape::Shape(Colors c)
{
	color=c;
}

void Shape::print() const { std::cout << "Unknown Shape" << std::endl; }
