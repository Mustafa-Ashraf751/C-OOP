#ifndef GEOSHAPE_H
#define GEOSHAPE_H

class Geoshape
{
protected:
  float x;
  float y;

public:
  Geoshape()
  {
    x = y = 0;
  }

  Geoshape(float num)
  {
    x = y = num;
  }

  Geoshape(float num1, float num2)
  {
    x = num1;
    y = num2;
  }

  void setX(float num)
  {
    x = num;
  }

  void setY(float num)
  {
    y = num;
  }

  float getX()
  {
    return x;
  }

  float getY()
  {
    return y;
  }

  virtual float calculateArea() = 0;
};

#endif