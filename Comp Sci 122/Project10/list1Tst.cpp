#include <iostream>
using namespace std;

#include "list1.h"


int main()
{
 List lst;

 for (int i = 0; i < 5; i++)
   lst.PutItemH(i);

 lst.Print();

 cout << lst.GetItemH() << endl; 
 lst.DeleteItemH(); 
 cout << lst.GetItemH() << endl; 
 cout << lst.GetLength() << endl;
 return 0;
}
