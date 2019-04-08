/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: proj9.h
Test file for a doubly linked list with dummy nodes at head and
tail to make insertion and deletion easier
To Build: g++ proj9Tst.cpp proj9.cpp
To Execute: ./a.out
*/

#include "proj9.h"
#include <iostream>
using namespace std;

int main(){
  List4* myList = new List4();
  for(int i = 1; i<= 7; i++){
    myList->Insert(i,i);
  }
  //myList->Insert(1, 4);
  myList->PrintForward();
  cout<<endl;
  myList->PrintBackwards();
  cout<<endl;
  myList->Delete(4);
  cout<<endl;
  myList->PrintForward();


  return 0;
}
