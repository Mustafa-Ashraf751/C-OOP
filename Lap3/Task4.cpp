#include <iostream>

using namespace std;

class ArrayList
{
private:
  int size;
  int capacity;
  int *arr;

public:
  ArrayList()
  {
    this->size = 0;
    this->capacity = 16;
    arr = new int[capacity];
  }

  void push(int num)
  {
    if (size >= capacity)
    {
      int *tempPtr = arr;
      capacity *= 2;
      arr = new int[capacity];
      for (int i = 0; i < capacity; i++)
      {
        arr[i] = tempPtr[i];
      }
      delete[] (tempPtr);
    }
    arr[size++] = num;
  }

  int pop()
  {
    if (size < 0)
    {
      throw runtime_error("Sorry the stack is empty");
    }
    else
    {
      return arr[size--];
    }
  }

  int getSize()
  {
    return this->size;
  }

  void display()
  {
    cout << "Displaying ArrayList elements\n";
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << endl;
    }
  }

  ArrayList operator=(ArrayList a2)
  {
    this->size = a2.size;
    this->capacity = a2.capacity;
    delete[] arr;
    arr = new int[a2.capacity];
    for (int i = 0; i < a2.size; i++)
    {
      arr[i] = a2.arr[i];
    }
    return *this;
  }

  ~ArrayList()
  {
  }
};

int main()
{
  ArrayList a;
  for (int i = 0; i < 25; i++)
  {
    a.push(i);
  }
  ArrayList a2;
  for (int i = 0; i < 10; i++)
  {
    a2.push(i);
  }
  /* cout << a.getSize() << endl;
   a.pop();
   cout << a.getSize() << endl;
   a.display();*/
  a = a2;
  a.display();
  return 0;
}