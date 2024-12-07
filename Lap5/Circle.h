#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include <graphics.h>
#include "Shape.h"
class Circle : public Shape
{
private:
  Point center;
  int radius;

public:
  Circle(int m, int n, int r, int color = 15) : center(m, n), radius(r), Shape(color) {}

  void draw()
  {
    setcolor(Shape::getColor());
    circle(center.getX(), center.getY(), radius);
  }
};

#endif