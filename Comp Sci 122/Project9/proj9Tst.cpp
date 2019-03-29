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
  for(int i = 1; i<= 3; i++){
    myList->Insert(i,i);
  }
  myList->PrintForward();
  cout<<endl;
  myList->PrintBackwards();


  return 0;
}
