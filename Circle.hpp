#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
 public:
  Circle(double r);
  Circle(const Circle& other) = default;
  Circle(double r, Colors c);
  double getArea()  const noexcept override ;
  double getPerimeter() const noexcept override ;
  double getRadius() const;
  void print() const override;
  Circle() = delete;
  double getPi();

 private:
  // doesn't allow to call default constructor

  double r_;
};
