//This programs shows how pointers can be used with classes to quickly access information stored in the class


#include <iostream>
using namespace std;

class SimpleItem {
public:
   void PrintNums(); //native functions to the object 
   SimpleItem(int initVal1 = -1, int initVal2 = -1); //default values of native variables in object, defaualt constructors
private:
   int num1;
   int num2; //native variables
};

SimpleItem::SimpleItem(int initVal1, int initVal2) { //custom constructor, creates object with user define arguements
   num1 = initVal1;
   num2 = initVal2;
}

void SimpleItem::PrintNums() { // definition of native functions for the object. Users native variables
   cout << "num1: " << num1 << endl;
   cout << "num2: " << num2 << endl;
}

int main() {
   SimpleItem* myItemPtr1 = 0; 
   cout<<"myItemPtr1 = "<<myItemPtr1<<endl;
   SimpleItem* myItemPtr2 = 0;
   cout<<"myItemPtr2 = "<<myItemPtr2<<endl;
   
   myItemPtr1 = new SimpleItem; //creates an object stored in referance location myItemPtr1
   cout<< "myItemPtr1: "<<myItemPtr1<<endl;
   (*myItemPtr1).PrintNums();
   cout << endl;
   
   myItemPtr2 = new SimpleItem(8, 9); // creates custom object and stores in in the referance location myItemPtr2
   cout<< "myItemPtr2: "<<myItemPtr2<<endl;
   (*myItemPtr2).PrintNums();
   
   return 0;
}