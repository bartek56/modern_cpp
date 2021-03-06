#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r):Circle(r, Colors::BLUE)
{
  r_ = std::move(r);
}

Circle::Circle(double r, Colors c)
				 : Shape(c), r_(r)
{}

double Circle::getArea() const noexcept
{
  return M_PI * r_ * r_;
}
double Circle::getPerimeter() const noexcept
{
  return 2 * M_PI * r_;
}
double Circle::getRadius() const
{
  return r_;
}
[[deprecated("Please use M_PI")]] double Circle::getPi()
{
  return 3.14;
}
void Circle::print() const
{
  std::cout << "Circle: radius: " << getRadius() << std::endl
            << "          area: " << getArea() << std::endl
            << "     perimeter: " << getPerimeter() << std::endl;
}
