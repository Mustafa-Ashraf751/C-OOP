#include <iostream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Picture.h"
#include <graphics.h>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  Picture myPic;

  Circle cArr[3] = {Circle(30, 30, 30), Circle(225, 125, 100), Circle(200, 50, 30)};
  Rect rArr[2] = {Rect(20, 50, 150, 120), Rect(320, 30, 450, 250)};
  Line lArr[2] = {Line(320, 40, 200, 200), Line(30, 450, 400, 300)};

  myPic.setCircles(3, cArr);
  myPic.setRects(2, rArr);
  myPic.setLines(2, lArr);

  myPic.paint();

  getch();
  closegraph();
  return 0;
}