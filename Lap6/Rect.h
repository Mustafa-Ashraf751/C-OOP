#ifndef RECT_H
#define RECT_H
#include "Geoshape.h"

class Rectangle : public Geoshape
{
public:
  Rectangle(float x, float y) : Geoshape(x, y)
  {
  }

  float calculateArea()
  {
    return x * y;
  }
};

#endif