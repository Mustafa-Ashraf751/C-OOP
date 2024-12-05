#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <graphics.h>

#include "Point.h"
class Rect
{
private:
  Point ul;
  Point lr;

public:
  Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}

  void draw()
  {

    rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
  }
};

#endif