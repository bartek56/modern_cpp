#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
  for (auto it = collection.begin(); it != collection.end(); ++it)
  {
    if (*it != nullptr)
    {
      (*it)->print();
    }
  }
}

void printAreas(const Collection& collection)
{
  for (const auto& it : collection)
  {
    if (it != nullptr)
    {
      cout << (it)->getArea() << std::endl;
    }
  }
}

void findFirstShapeMatchingPredicate(const Collection& collection, std::function<int(shared_ptr<Shape>)> s, std::string info)
{
  Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), s);
  if (*iter != nullptr)
  {
    cout << "First shape matching predicate: " << info << endl;
    (*iter)->print();
  }
  else
  {
    cout << "There is no shape matching predicate " << info << endl;
  }
}

int main()
{
  Collection shapes = {
      make_shared<Circle>(2.0,Colors::BLUE), make_shared<Circle>(3.0), make_shared<Rectangle>(10.0, 5.0),
      make_shared<Square>(3.0), make_shared<Circle>(4.0),
  };

  cout << "align " << alignof(char) << endl;
  cout << "align Circle " << alignof(Circle) << endl;
  printCollectionElements(shapes);

  cout << "Areas before sort: " << std::endl;
  printAreas(shapes);

  std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
    {
      return false;
    }

    return (first->getArea() < second->getArea());

  });

  cout << "Areas after sort: " << std::endl;
  printAreas(shapes);

  shapes.push_back(make_shared<Square>(4.0));

  findFirstShapeMatchingPredicate(shapes,
                                  [](shared_ptr<Shape> s) {
                                    if (s)
                                    {
                                      return (s->getPerimeter() > 20);
                                    }
                                    return false;
                                  },
                                  "perimeter bigger than 20");

  int value = 10;
  findFirstShapeMatchingPredicate(shapes,
                                  [&value](shared_ptr<Shape> s) -> bool {
                                    if (s)
                                    {
                                      return (s->getArea() < value);
                                    }
                                    return false;
                                  },
                                  "area less than " + std::to_string(value));

  return 0;
}
