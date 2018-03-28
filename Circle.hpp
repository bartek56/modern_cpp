#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
 public:
  Circle(double r);
  Circle(const Circle& other) = default;
  Circle(double r, Colors c);
  double getArea() const override;
  double getPerimeter() const override;
  double getRadius() const;
  void print() const override;
  Circle() = delete;

 private:
  // doesn't allow to call default constructor

  double r_;
};
