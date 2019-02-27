/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj6.cpp
Program defines a Class List which is an example of a singly linked list
File tests functions of List class defined in proj6.cpp
To Build: g++ proj6.cpp proj6Tst.cpp
To Execute: ./a.out
*/

#include "proj6.h"
#include <iostream>
using namespace std;

int main(){
  List* myList1 = new List;
  List* myList2 = new List;

  int x = 0;

  //Test 1: populates the list with the letters 0,1,2,3,4 and outputs them in the other of: 4.3.2.1.0
  cout<<"Test 1 -------------------------------------"<<endl;
  while(x <= 4){
    myList1->PutItemH(x);
    x++;
  }
  myList1->Print();

  //Test 2: Causes contents of list to be listed in reverse order by using another list
  cout<<"\nTest 2 -------------------------------------"<<endl;
  while(x > 0){
    myList2->PutItemH(myList1->GetItemH());
    myList1->DeleteItemH();
    x--;
  }
  myList2->Print();

  //Test 3: Deletes 2 items from reverse list and displays list
  cout<<"\nTest 3 -------------------------------------"<<endl;
  myList2->DeleteItemH();
  myList2->DeleteItemH();
  myList2->Print();

  return 0;
}
