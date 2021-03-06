/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj8Tst.cpp
Test file for a linked list with:
1) The capacity to copy a list with the copy constructor
2) The capacity to manipulate a node in any position
To Build: g++ proj8Tst.cpp proj.cpp
To Execute: ./a.out
*/

#include "proj8.h"
#include <iostream>
using namespace std;

int main(){
  List3* myList = new List3();


  int length = 5;

  for(int i = 0; i< length; i++){
    myList->PutItem(i, i);
  }
  //myList->Print(); // print full list
  cout<<endl<<endl;
  myList->DeleteItem(3); // delete
  cout<<endl<<endl;
  List3* myList2 = new List3(myList);
//  myList2->Print(); // print copied list
  myList2->PutItem(0,5);
  myList2->PutItem(5, 5);
  myList2->Print();



}
