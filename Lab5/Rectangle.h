#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <graphics.h>
#include "Shape.h"

#include "Point.h"
class Rect : public Shape
{
private:
  Point ul;
  Point lr;

public:
  Rect(int x1, int y1, int x2, int y2, int color = 15) : ul(x1, y1), lr(x2, y2), Shape(color) {}

  void draw()
  {
    setcolor(Shape::getColor());
    rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
  }
};

#endif