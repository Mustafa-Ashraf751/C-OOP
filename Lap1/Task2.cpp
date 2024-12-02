#include <iostream>

using namespace std;

// Call by value
void swap(int x, int y)
{
  x = x - y;
  y = x + y;
  x = -x + y;
}
// Call by reference
void swapReference(int &x, int &y)
{
  x = x - y;
  y = x + y;
  x = -x + y;
}

// Call by address
void swapAddress(int *x, int *y)
{
  *x = *x - *y;
  *y = *x + *y;
  *x = -*x + *y;
}

int main()
{

  int num1 = 5;
  int num2 = 10;
  // swap(num1, num2);
  // swapReference(num1, num2);
  swapAddress(&num1, &num2);
  cout << num1 << " " << num2;
  return 0;
}