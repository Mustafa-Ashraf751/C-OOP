#include <iostream>

using namespace std;

template <class T>

class ArrayList
{
private:
  int size;
  int capacity;
  T *arr;

public:
  ArrayList()
  {
    this->size = 0;
    this->capacity = 16;
    arr = new T[capacity];
  }

  void push(T num)
  {
    if (size >= capacity)
    {
      T *tempPtr = arr;
      capacity *= 2;
      arr = new T[capacity];
      for (int i = 0; i < capacity; i++)
      {
        arr[i] = tempPtr[i];
      }
      delete[] (tempPtr);
    }
    arr[size++] = num;
  }

  T pop()
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
    arr = new T[a2.capacity];
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
  /*ArrayList<int> a;
  for (int i = 0; i < 25; i++)
  {
    a.push(i);
  }
  ArrayList<int> a2;
  for (int i = 0; i < 10; i++)
  {
    a2.push(i);
  }
  /* cout << a.getSize() << endl;
   a.pop();
   cout << a.getSize() << endl;
   a.display();*/
  /* a = a2;
   a.display();*/
  ArrayList<float> a;
  for (float i = 0; i < 25; i++)
  {
    a.push(i + 0.5);
  }
  ArrayList<float> a2;
  for (float i = 0; i < 10; i++)
  {
    a2.push(i);
  }
  /* cout << a.getSize() << endl;
   a.pop();
   cout << a.getSize() << endl;
   a.display();*/
  // a = a2;
  a.display();
  return 0;
}