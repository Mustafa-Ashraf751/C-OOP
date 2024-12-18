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
  int cNum, rNum, lNum;
  Circle *pCircles;
  Rect *pRects;
  Line *pLines;

public:
  Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

  void setCircles(int cn, Circle *pC)
  {
    cNum = cn;
    pCircles = pC;
  }

  void setRects(int rn, Rect *pR)
  {
    rNum = rn;
    pRects = pR;
  }

  void setLines(int ln, Line *pL)
  {
    lNum = ln;
    pLines = pL;
  }

  void paint()
  {
    for (int i = 0; i < cNum; i++)
    {
      pCircles[i].draw();
    }
    for (int i = 0; i < rNum; i++)
    {
      pRects[i].draw();
    }
    for (int i = 0; i < lNum; i++)
    {
      pLines[i].draw();
    }
  }
};

#endif