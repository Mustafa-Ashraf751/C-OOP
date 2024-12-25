#include <iostream>
#include "mustafa_string.h"
using namespace std;
// For fix linker error
int stringLen(char source[])
{
  unsigned int i = 0;
  while (source[i] != '\0')
  {
    i++;
  }
  return i;
}
int stringCompare(char str1[], char str2[])
{
  int sumStr1 = 0;
  int sumStr2 = 0;
  for (int i = 0; i < stringLen(str1); i++)
  {
    sumStr1 += str1[i];
  }
  for (int i = 0; i < stringLen(str2); i++)
  {
    sumStr2 += str2[i];
  }
  if (sumStr1 == sumStr2)
  {
    return 0;
  }
  else if (sumStr1 > sumStr2)
  {
    return sumStr1 - sumStr2;
  }
  else
  {
    return sumStr1 - sumStr2;
  }
};

class String
{
private:
  char *str;

public:
  String(char *input)
  {
    int length = stringLen(input);
    str = new char[length];
    for (int i = 0; i < length; i++)
    {
      str[i] = input[i];
    }
    str[length] = '\0';
  }

  void print()
  {
    int i = 0;
    while (str[i] != '\0')
    {
      cout << str[i];
      i++;
    }
  }

  int getSize()
  {
    return stringLen(str);
  }

  bool operator==(char *str2)
  {

    return stringCompare(str, str2) == 0 ? true : false;
  }

  bool operator>=(char *str2)
  {
    return stringLen(str) >= stringLen(str2) ? true : false;
  }

  bool operator<=(char *str2)
  {
    return stringLen(str) <= stringLen(str2) ? true : false;
  }

  char *concat(char *str2)
  {
    int len1 = stringLen(str);
    int len2 = stringLen(str2);
    char *newArr = new char[len1 + len2];
    for (int i = 0; i < len1; i++)
    {
      newArr[i] = str[i];
    }

    for (int j = 0; j < len2; j++)
    {
      newArr[len1 + j] = str2[j];
    }
    newArr[len1 + len2] = '\0';
    return newArr;
  }

  char *operator+(char *str2)
  {
    return concat(str2);
  }

  ~String()
  {
    delete[] str;
  }
};

int main()
{
  String s1 = "mohammed ahmed";
  // s1.print();
  cout << s1.concat(" mustafa") << endl;
  cout << (s1 + " mustafa");
  String s2 = "mustafa";
  cout << (s2 == "mustafa");
  //   cout << s1.getSize();
  return 0;
}