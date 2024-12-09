#include <iostream>

using namespace std;

template <class T>
class Stack
{

private:
  int top;
  int size;
  T *items;

public:
  static int count;
  Stack(int size)
  {
    top = -1;
    this->size = size;
    items = new T[size];
    count++;
  }

  int push(T num)
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

  T pop()
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
    items = new T[s1.size];
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

// Intailsize the counter
template <class T>
int Stack<T>::count = 0;

int main()
{
  Stack<int> s1(5);
  Stack<float> s2(5);

  s1.push(5);
  s1.push(6);
  s1.push(7);
  s1.push(8);
  s1.push(9);

  cout << s1.pop() << endl;

  s2.push(5.98756);
  cout << s2.pop();

  return 0;
}