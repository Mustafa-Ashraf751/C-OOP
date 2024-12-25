#include <iostream>
#include "Rect.h"
#include "CircleGeo.h"
#include "Triangle.h"
#include "Square.h"
#include "Geoshape.h"

using namespace std;

int main()
{

  Rectangle r(20, 30);
  Circle c(25);
  Triangle t(30, 60);
  Square sq(40);
  // Incase of public inheritance between square and geoshape
  //  sq.x -> cant access the element protected element in geoshape;
  // sq.y -> error
  // c.r -> cant access the element protected element in geoshape;
  // c.y -> error
  // public inheritance will cause square to access the x and y setter and this will cause error in the area of the square and circle
  /* sq.setX(60);
   sq.setY(10);
   cout << sq.calculateArea();
   c.setX(25);
   c.setY(10);
   cout << c.calculateArea();*/
  // Incase of protected inheritance
  // This will prevent using of setX and setY from being used outside the c and sq and their children
  /*sq.setX(60); // Compiler error
  cout << sq.calculateArea();
  c.setX(25);
  c.setY(10);
  cout << c.calculateArea();*/
  return 0;
}