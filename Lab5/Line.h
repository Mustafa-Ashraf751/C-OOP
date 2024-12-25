#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include <graphics.h>

#include "Shape.h"
class Line : public Shape
{
private:
  Point start;
  Point end;

public:
  Line(int x1, int y1, int x2, int y2, int color = 15) : start(x1, y1), end(x2, y2), Shape(color) {}

  void draw()
  {
    setcolor(Shape::getColor());
    line(start.getX(), start.getY(), end.getX(), end.getY());
  }
};

#endif