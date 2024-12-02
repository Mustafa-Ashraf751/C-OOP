#include <iostream>

using namespace std;

class Complex
{
  double real;
  double imagine;

public:
  Complex add(Complex c)
  {
    this->real += c.real;
    this->imagine += c.imagine;
    return *this;
  }

  Complex substract(Complex c)
  {
    this->real -= c.real;
    this->imagine -= c.imagine;
    return *this;
  }

  void display()
  {
    if (this->real == 0)
    {
      cout << this->imagine << "Img" << endl;
    }
    else if (this->imagine == 0)
    {
      cout << this->real << "Real" << endl;
    }
    else if (this->real == 0 && this->imagine == 0)
    {
      cout << "No data to show it" << endl;
    }
    else
    {
      cout << this->real << " Real " << " + " << this->imagine << " Img" << endl;
    }
  }

  void setReal(double real)
  {
    this->real = real;
  }

  void setImagine(double imagine)
  {
    this->imagine = imagine;
  }

  double getReal()
  {
    return this->real;
  }

  double getImagine()
  {
    return this->imagine;
  }
};

int main()
{
  Complex result, complex1, complex2;
  complex1.setReal(15);
  complex1.setImagine(25);
  complex2.setReal(10);
  complex2.setImagine(15);

  result = complex1.add(complex2);
  result.display();

  result = complex1.substract(complex2);
  result.display();
}