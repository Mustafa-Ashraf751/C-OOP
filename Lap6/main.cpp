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

  Picture myPic(5);

  myPic.add(new Circle(30, 30, 30, 1));
  myPic.add(new Circle(225, 125, 100, 1));
  myPic.add(new Rect(20, 50, 150, 2, 2));
  myPic.add(new Line(320, 40, 200, 200, 4));
  myPic.add(new Line(30, 450, 400, 300, 4));
  myPic.paint();

  getch();
  closegraph();
  return 0;
}