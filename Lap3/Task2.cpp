#include <iostream>

using namespace std;

class Stack
{

private:
  int top;
  int size;
  int *items;

public:
  static int count;
  Stack(int size)
  {
    top = -1;
    this->size = size;
    items = new int[size];
    count++;
  }

  int push(int num)
  {
    if (top == size - 1)
    {
      return 0;
    }
    else
    {
      top++;
      items[top] = num;
      return 1;
    }
  }

  int pop()
  {

    if (top == -1)
    {
      throw runtime_error("Stack is empty can't pop element");
    }
    else
    {
      return items[top--];
    }
  }

  void display()
  {
    if (top == -1)
    {
      cout << "No Numbers to show:\n";
    }
    else
    {
      cout << "Displaying Numbers:\n";
      for (int i = 0; i <= top; i++)

      {

        cout << items[i] << endl;
      }
    }
  }

  Stack operator=(Stack &s1)
  {
    this->top = s1.top;
    this->size = s1.size;
    delete[] items;
    items = new int[s1.size];
    for (int i = 0; i < size; i++)
    {
      items[i] = s1.items[i];
    }
    return *this;
  }

  ~Stack()
  {
    count--;
  }
};

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

  Complex operator+(Complex c)
  {
    Complex c1;
    c1.real = c.real + this->real;
    c1.imagine = c.imagine + this->imagine;
    return c1;
  }

  Complex operator-(Complex c2)
  {
    Complex c;
    c.real = this->real - c2.real;
    c.imagine = this->imagine - c2.imagine;
    return c;
  }

  Complex operator+(int num)
  {
    Complex c;
    c.real = this->real + num;
    c.imagine = this->imagine + num;
    return c;
  }

  Complex operator-(int num)
  {
    Complex c;
    c.real = this->real - num;
    c.imagine = this->imagine - num;
    return c;
  }

  bool operator==(Complex c2)
  {
    return (this->real == c2.real && this->imagine == c2.imagine) ? true : false;
  }

  Complex operator+=(Complex c2)
  {
    this->real += c2.real;
    this->imagine += c2.imagine;
    return *this;
  }

  // This for pre
  Complex operator++()
  {
    real++;
    return *this;
  }
  Complex operator--()
  {
    real--;
    return *this;
  }

  // This for post
  Complex operator++(int num)
  {
    Complex c = *this;
    real++;
    return c;
  }

  Complex operator--(int num)
  {
    Complex c = *this;
    real--;
    return c;
  }

  operator float()
  {
    return real;
  }

  ~Complex()
  {
    // cout << "Object cleared from the memory";
  }

  void setComplex(double real, double imagine)
  {
    this->real = real;
    this->imagine = imagine;
  }
};

// For integer calls functions
Complex operator+(int num, Complex c1)
{
  Complex c;
  c.setReal(c1.getReal() + num);
  c.setImagine(c1.getImagine() + num);
  return c;
}

Complex operator-(int num, Complex c1)
{
  Complex c;
  c.setReal(num - c1.getReal());
  c.setImagine(num - c1.getImagine());
  return c;
}

// Intailsize the counter
int Stack::count = 0;

int main()
{

  Complex c1(10, 20);
  Complex c2(5, 5);
  Complex c3;
  /*c3 = c1 + c2;
  c3.display();
  c3 = c1 - c2;
  c3.display();
  c3 = c1 + 5;
  c3.display();
  c3 = c1 - 5;
  c3.display();
  c3 = 5 + c1;
  c3.display();
  c3 = 5 - c1;
  c3.display();
   (c1 == c2) ? cout << "True" : cout << "False";
  c1 += c2;
  c1.display();
  ++c1;
  c1.display();
  --c1;
  c1.display();
  c1++;
  c1.display();
  c1--;
  c1.display();*/
  cout << (float)c1;

  return 0;
}