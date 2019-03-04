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

  cout<<"Test 1: -------------------------------------"<<endl;
  int x = 0;
  while(x <= 4){
    myList->PutItemT(x);
    x++;
  }
  myList->Print();

  return 0;
}
