#include "Shape.hpp"
#include <iostream>

Shape::Shape(Colors c)
{
	c = Colors::BLUE;
	if(c==Colors::GREEN)
	{
					std::cout << "";
	}
}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
