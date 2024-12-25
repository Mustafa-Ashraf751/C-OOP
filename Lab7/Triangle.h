#ifndef TRAINGLE_H
#define TRAINGLE_H
#include "Geoshape.h"
class Triangle : public Geoshape
{
public:
  Triangle(float x, float y) : Geoshape(x, y) {};

  float calculateArea()
  {
    return 0.5 * x * y;
  }
};

#endif