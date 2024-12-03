#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#include <stdio.h>
#include "conio.h"

#define ARROWUP 65
#define ARROWDOWN 66
#define ENTER 10
#define EXTENDEDKEY 27
#define OPTIONONE 0
#define OPTIONTWO 1
#define OPTIONTHREE 2
#define SIZE 3
#define EMPLOYEESIZE 100
#define NAMESIZE 50

void blue()
{
  printf(" \033[0;34m");
}

void white()
{
  printf("\033[0;37m");
};

void resetColor()
{
  printf("\x1B[0m");
};

void resetCursor()
{
  printf("\033[H\033[J");
}

void clearScreen()
{
  printf("\033[H\033[J");
}

void clearAfterWhile()
{
  // Wait for 10 seconds before clearing the screen
  this_thread::sleep_for(chrono::seconds(5));

  // Clear the screen using ANSI escape codes
  cout << "\033[H\033[J";
}

// Create function to display menu
void displayMenuOPtions(char *option, int isSelected)
{
  if (isSelected)
  {
    blue();
  }
  else
  {
    white();
  }
  printf("%s\n\n\n", option);
  resetColor();
};

// Function to color menu
void ColorMenu(char *menuOptions[], int select)
{
  for (int i = 0; i < SIZE; i++)
  {
    displayMenuOPtions(menuOptions[i], i == select);
  }
}

typedef struct Employee
{
  int id;
  string name;
  int netSalary;

} Employee;

class Stack
{

private:
  int top;
  int size;
  Employee *employees;

public:
  static int count;
  Stack(int size)
  {
    top = -1;
    this->size = size;
    employees = new Employee[size];
    count++;
  }

  int push(Employee e)
  {
    if (top == size - 1)
    {
      return 0;
    }
    else
    {
      top++;
      employees[top].id = e.id;
      employees[top].name = e.name;
      employees[top].netSalary = e.netSalary;
      return 1;
    }
  }

  Employee pop()
  {

    if (top == -1)
    {
      throw exception();
    }
    else
    {
      return employees[top--];
    }
  }

  void display()
  {
    if (top == -1)
    {
      cout << "No Employees to show:\n";
    }
    else
    {
      cout << "Displaying Employees:\n";
      for (int i = 0; i <= top; i++)

      {

        cout << "Employee number " << i + 1 << " id is:" << employees[i].id << endl;
        cout << "Employee number " << i + 1 << " name is:" << employees[i].name << endl;
        cout << "Employee number " << i + 1 << " salary is:" << employees[i].netSalary << endl;
      }
    }
  }

  ~Stack()
  {
    count--;
  }
};

// Intailsize the counter
int Stack::count = 0;

int main()
{
  char input = 0;
  int dontStop = 1;
  int choose = 0;
  int inputFlag = 1;
  char *menuOptions[] = {"push", "pop", "print Stack"};
  int selectedOption = 0;
  // Take size from the user
  while (inputFlag)
  {
    printf("Please enter the number of employee you want to enter ? ");
    cin >> choose;
    input = getch();
    if (cin.fail())
    {
      cout << "Invalid size please try again\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if (choose < 0)
    {
      cout << "Invalid size please try again\n";
    }
    else
    {
      inputFlag = 0;
    }
  }

  Stack employees(choose);

  // Open the menu and keep track input
  while (dontStop)
  {
    clearScreen();
    ColorMenu(menuOptions, selectedOption);
    input = getch();
    // Arrow need 3 times to get the number
    if (input == EXTENDEDKEY)
    {
      input = getch();
      input = getch();
    }

    if (input == ARROWUP)
    {
      if (selectedOption == OPTIONONE)
      {
        selectedOption = 5;
      }
      if (selectedOption > OPTIONONE)
      {
        resetCursor();
        // decrease the cursor
        selectedOption--;
        // show the menu
        ColorMenu(menuOptions, selectedOption);
      }
    }

    if (input == ARROWDOWN)
    {
      if (selectedOption == OPTIONTHREE)
      {
        selectedOption = -1;
      }
      if (selectedOption < OPTIONTHREE)
      {
        resetCursor();
        selectedOption++;
        ColorMenu(menuOptions, selectedOption);
      }
    }

    if (input == ENTER)
    {
      clearScreen();
      // Incase user choose first option
      if (selectedOption == OPTIONONE)
      {
        int id = 0;
        string name;
        int netSalary = 0;
        int flag = 1;
        while (flag)
        {
          cout << "Please enter employee id: ";
          cin >> id;
          if (cin.fail() || id <= 0)
          {
            cout << "Invalid Id please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
          else
          {
            cout << "Please enter employee name: ";
            cin >> name;
            cout << "Please enter employee salary: ";
            cin >> netSalary;
            if (cin.fail())
            {
              cout << "Invalid salary please try again\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (netSalary <= 0)
            {
              cout << "Invalid salary please try again\n";
            }
            else
            {
              flag = 0;
            }
          }
        }
        Employee e;
        e.id = id;
        e.name = name;
        e.netSalary = netSalary;
        employees.push(e);
        cout << "Data inserted successfully";
        input = getch();
        clearAfterWhile();
        ColorMenu(menuOptions, selectedOption);
      }
      else if (selectedOption == OPTIONTWO)
      {
        try
        {
          Employee e = employees.pop();
          cout << "Employee number  id is:" << e.id << endl;
          cout << "Employee number  name is:" << e.name << endl;
          cout << "Employee number  salary is:" << e.netSalary << endl;
          clearAfterWhile();
          ColorMenu(menuOptions, selectedOption);
        }
        catch (const exception &e)
        {
          cout << "Error with message: " << e.what() << endl;
        }
      }
      else if (selectedOption == OPTIONTHREE)
      {
        employees.display();
        clearAfterWhile();
        ColorMenu(menuOptions, selectedOption);
      }
    }
  };
  return 0;
}
