#ifndef SQUARE_H
#define SQUARE_H
#include "Rect.h"
#include "Geoshape.h"

class Square : protected Rectangle
{
public:
  Square(float x) : Rectangle(x, y)
  {
  }

  void setDim(float num)
  {
    x = y = num;
  }

  float calculateArea()
  {
    return x * y;
  }
};

#endif