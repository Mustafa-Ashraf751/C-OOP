#include <iostream>
#include <typeinfo>
#include <stdexcept>

using namespace std;

class DynamicList
{
private:
  void **values;
  int *types; // Array to track types and we assume that every type has a number
  int size;
  int capacity;

public:
  DynamicList(int cap)
  {
    this->size = 0;
    this->capacity = cap;
    values = new void *[capacity];
    types = new int[capacity];
  }

  template <typename T>
  void push(T value)
  {
    if (size >= capacity)
    {
      capacity *= 2;
      // We must move the old data before reallocate with new one
      void **tempValues = new void *[capacity];
      int *tempTypes = new int[capacity];

      for (int i = 0; i < size; i++)
      {
        tempValues[i] = values[i];
        tempTypes[i] = types[i];
      }

      delete[] values;
      delete[] types;

      values = tempValues;
      types = tempTypes;
    }

    // We need to dynamically store the value because we don't know which type i will store in memory
    values[size] = new T(value);
    types[size] = getType<T>(); // Store the type of the element
    size++;
  }

  // Function to return types of each data i push to the array
  template <typename T>
  int getType()
  {
    if (typeid(T) == typeid(int))
      return 0;
    if (typeid(T) == typeid(float))
      return 1;
    if (typeid(T) == typeid(double))
      return 2;
    if (typeid(T) == typeid(string))
      return 3;
    return -1;
  }

  void display()
  {
    for (int i = 0; i < size; i++)
    {
      switch (types[i])
      {
      case 0:
        cout << "Int: " << *reinterpret_cast<int *>(values[i]) << endl;
        break;
      case 1:
        cout << "Float: " << *reinterpret_cast<float *>(values[i]) << endl;
        break;
      case 2:
        cout << "Double: " << *reinterpret_cast<double *>(values[i]) << endl;
        break;
      case 3:
        cout << "String: " << *reinterpret_cast<string *>(values[i]) << endl;
        break;
      default:
        cout << "Unknown Type" << endl;
      }
    }
  }

  ~DynamicList()
  {
    for (int i = 0; i < size; i++)
    {
      delete values[i];
    }
    delete[] values;
    delete[] types;
  }
};

int main()
{

  DynamicList list(4);

  list.push(5);
  list.push(3.14f);
  list.push(2.718);
  list.push(string("Hello, world!"));

  list.display();

  return 0;
}
