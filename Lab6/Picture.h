#ifndef PICTURE_H
#define PICTURE_H
#include "Point.h"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include <graphics.h>
class Picture
{
private:
  int size;
  Shape **items;
  int currentIndex;

public:
  Picture(int size)
  {
    this->size = size;
    items = new Shape *[size];
    currentIndex = -1;
  }

  void add(Shape *s)
  {
    if (currentIndex == size - 1)
    {
      return;
    }
    currentIndex++;
    items[currentIndex] = s;
  }

  void paint()
  {
    for (int i = 0; i <= currentIndex; i++)
    {
      items[i]->draw();
    }
  }
};

#endif