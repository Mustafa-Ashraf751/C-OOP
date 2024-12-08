#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
private:
  int color;

public:
  Shape(int color)
  {
    this->color = color;
  }
  void setColor(int num)
  {
    this->color = num;
  }
  int getColor()
  {
    return this->color;
  }
  virtual void draw() = 0;
};

#endif