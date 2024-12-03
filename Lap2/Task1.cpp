#include <iostream>

using namespace std;

class Complex
{
  double real;
  double imagine;

public:
  Complex()
  {
  }

  Complex(double real, double imagine)
  {
    this->real = real;
    this->imagine = imagine;
  }
  Complex add(Complex c)
  {
    Complex newComplex;
    newComplex.setReal(this->real + c.real);
    newComplex.setImagine(this->imagine + c.imagine);
    return newComplex;
  }

  Complex substract(Complex c)
  {
    Complex newComplex;
    newComplex.setReal(this->real - c.real);
    newComplex.setImagine(this->imagine - c.imagine);
    return newComplex;
  }

  void display()
  {
    if (this->real == 0 && this->imagine == 0)
    {
      cout << "No data to show it" << endl;
    }
    else if (this->real == 0)
    {
      cout << this->imagine << " Img" << endl;
    }
    else if (this->imagine == 0)
    {
      cout << this->real << " Real" << endl;
    }
    else
    {
      imagine < 0 ? cout << this->real << " Real" << " - " << this->imagine * -1 << " Img" << endl : cout << this->real << " Real" << " + " << this->imagine << " Img" << endl;
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

  ~Complex()
  {
    cout << "Object cleared from the memory";
  }

  void setComplex(double real, double imagine)
  {
    this->real = real;
    this->imagine = imagine;
  }
};

int main()
{
  Complex result, complex1, complex2;
  complex1.setReal(15);
  complex1.setImagine(25);
  complex2.setReal(10);
  complex2.setImagine(50);

  result = complex1.add(complex2);
  result.display();

  result = complex1.substract(complex2);
  result.display();
}