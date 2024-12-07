#include <iostream>
#include "Base.h"
#include "Derived.h"
#include "SecondDerived.h"

using namespace std;

int main()
{
  // By usign set functions
  /*Base object1;
  Derived object2;
  SecondDerived object3;
  object1.setA(25);
  object1.setB(50);
  object2.setA(object1.getA());
  object2.setB(object1.getB());
  object2.setC(75);
  object3.setA(object2.getA());
  object3.setB(object2.getB());
  object3.setC(object2.getC());
  object3.setD(100);
  cout << object1.product() << endl;
  cout << object2.product() << endl;
  cout << object3.product() << endl;*/
  // ***********************************************************
  // By using constructor
  /*Base object4(5, 10);
  Derived object5(20, 80, 120);
  SecondDerived object6(25, 50, 75, 100);
  cout << object4.product() << endl;
  cout << object5.product() << endl;
  cout << object6.product() << endl;*/
  //*********************************************************
  // Testing overriden
  Derived object2(20, 80, 120);
  Base *ptr = &object2;
  cout << object2.product() << endl;
  cout << object2.Base::product() << endl;
  cout << ptr->product() << endl;

  return 0;
}