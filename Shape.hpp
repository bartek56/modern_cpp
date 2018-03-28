#pragma once

enum class Colors
{
  RED,
  BLUE,
  GREEN,
  PINK
};

class Shape
{
 public:
  virtual ~Shape() {}
  Shape(Colors c);
  Shape() = default;
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;
  virtual void print() const;
  Colors color = Colors::BLUE;
};
