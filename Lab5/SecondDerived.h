#ifndef SECONDDERIVED_H
#define SECONDDERIVED_H
#include "Derived.h"
#include <iostream>
using namespace std;
class SecondDerived : public Derived
{
private:
  int d;

public:
  SecondDerived() : Derived()
  {
    cout << "SecondDerived default constructor called" << endl;
    d = 0;
  }
  SecondDerived(int num) : Derived(num)
  {
    cout << "SecondDerived one constructor called" << endl;
    d = num;
  }
  SecondDerived(int a, int b, int c, int d) : Derived(a, b, c)
  {
    cout << "SecondDerived two constructor called" << endl;
    this->d = d;
  }

  void setD(int d)
  {
    this->d = d;
  }

  int getD()
  {
    return this->d;
  }

  int product()
  {
    return Derived::product() * this->d;
  }

  ~SecondDerived()
  {
    cout << "SecondDerived destructor called" << endl;
  }
};
#endif