#ifndef POINT_H
#define POINT_H

class Point
{
private:
  int x, y;

public:
  Point(int x1, int y1) : x(x1), y(y1) {}

  int getX() { return x; }
  int getY() { return y; }
};

#endif