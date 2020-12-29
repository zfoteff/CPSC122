#include <iostream>
using namespace std;

#include "list1.h"

void found(bool found, itemType);

int main()
{
 List* lst = new List;
 bool result;
 itemType x, y;
 x = 3;
 y = 15;

 result = lst->Find(x);
 found(result,x);

 for (int i = 0; i < 5; i++)
   lst->PutItemH(i);

 result = lst->Find(x);
 found(result,x);

 result = lst->Find(y);
 found(result,y);

 return 0;
}

void found(bool result, itemType item)
{
 if (result)
  cout << item << " was found" << endl;
 else
  cout << item << " was not found" << endl;
 cout << endl;
}
