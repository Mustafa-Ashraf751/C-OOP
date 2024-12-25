#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"
#include <iostream>
using namespace std;
class Derived : public Base
{
private:
  int c;

public:
  Derived() : Base()
  {
    cout << "Derived default constructor called" << endl;
    c = 0;
  }
  Derived(int num) : Base(num)
  {
    cout << "Derived one constructor called" << endl;
    c = num;
  }
  Derived(int a, int b, int c) : Base(a, b)
  {
    cout << "Derived two constructor called" << endl;
    this->c = c;
  }

  void setC(int c)
  {
    this->c = c;
  }

  int getC()
  {
    return this->c;
  }

  int product()
  {
    return Base::product() * this->c;
  }

  ~Derived()
  {
    cout << "Derived destructor called" << endl;
  }
};

#endif