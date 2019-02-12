#include "proj5.h"
#include <iostream> 
using namespace std;

int main()
{
 MyString str1("My String Test");
 str1.MyStrDisplay(); 
 //cout << str1.MyStrlen() << endl;

 MyString* str2 = new MyString("My Second Test");
 str2->MyStrDisplay(); 
 //cout << str2->MyStrlen() << endl;
 return 0;
}
   
  
