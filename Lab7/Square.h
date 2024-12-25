#ifndef SQUARE_H
#define SQUARE_H
#include "Rect.h"
#include "Geoshape.h"

class Square : public Geoshape
{
public:
  Square(float x) : Geoshape(x, y)
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