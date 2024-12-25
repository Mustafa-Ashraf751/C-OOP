#ifndef CIRCLE_H
#define CIRCLE_H
#include "Geoshape.h"

class Circle : public Geoshape
{
public:
  Circle(float x) : Geoshape(x)
  {
  }

  void setDim(float num)
  {
    x = y = num;
  }

  float calculateArea()
  {
    return (22.0 / 7) * x * y;
  }
};

#endif