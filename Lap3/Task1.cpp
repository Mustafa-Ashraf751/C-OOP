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

  Stack(Stack &a)
  {
    this->top = a.top;
    this->size = a.size;
    items = new int[size];
    for (int i = 0; i <= top; i++)
    {
      items[i] = a.items[i];
    }
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

  ~Stack()
  {
    cout << "The object has been cleared\n";
    count--;
  }
};
// Just one object will be created
void viewContent(Stack &s)
{
  s.display();
}
// Two object will be created
void viewContentByValue(Stack s)
{
  s.display();
}
// Intailsize the counter
int Stack::count = 0;
int main()
{
  Stack s(5);
  s.push(50);
  s.push(60);
  s.push(70);
  s.push(80);
  s.push(90);

  // viewContent(s);
  viewContentByValue(s);
  return 0;
}