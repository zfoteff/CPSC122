/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj7.cpp
Program defines a Class List2 which is an example of a linked list
File tests functions of List2 class defined in proj7.cpp
To Build: g++ proj7.cpp proj7Tst.cpp
To Execute: ./a.out
*/

#include <iostream>
#include "proj7.h"
using namespace std;

int main(){
  List2* myList = new List2;

  //Adds integers 0,1,2,3,4,5 to tail of list
  cout<<"Test 1: -------------------------------------"<<endl;
  int x = 0;
  while(x <= 4){
    myList->PutItemT(x);
    x++;
  }
  myList->Print();

  // Deletes Elements at head and tail of object
  cout<<"Test 2: -------------------------------------"<<endl;
  myList->DeleteItemH();
  myList->DeleteItemT();
  myList->Print();

  // Copies myList into myList2, the adds 4,5 to end of List2 object
  cout<<"Test 3: -------------------------------------"<<endl;
  List2* myList2 = new List2(myList);
  myList2->PutItemT(4);
  myList2->PutItemT(5);
  myList2->Print();

  return 0;
}
