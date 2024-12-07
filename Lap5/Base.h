#ifndef BASE_H
#define BASE_H
#include <iostream>
using namespace std;

class Base
{
private:
  int a;
  int b;

public:
  Base()
  {
    cout << "Base default constructor called" << endl;
    a = b = 0;
  }
  Base(int n)
  {
    cout << "Base one constructor called" << endl;
    a = b = n;
  }

  Base(int a, int b)
  {
    cout << "Base two constructor called" << endl;
    this->a = a;
    this->b = b;
  }

  void setA(int a)
  {
    this->a = a;
  }

  void setB(int b)
  {
    this->b = b;
  }

  int getA()
  {
    return this->a;
  }

  int getB()
  {
    return this->b;
  }

  int product()
  {
    return this->a * this->b;
  }

  ~Base()
  {
    cout << "Base destructor called" << endl;
  }
};

#endif