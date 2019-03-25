/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: proj9.h
Function file for a doubly linked list with dummy nodes at head and
tail to make insertion and deletion easier
To Build: g++ proj9Tst.cpp proj9.cpp
To Execute: ./a.out
*/

#include "proj9.h"
#include <iostream>
using namespace std;

List4::List4(){
  length = 0;
  head = NULL;
  tail = NULL;
}

List4::~List4(){
  doubleNode* cur = head;
  while(cur->next->item > 0){
    cur = cur->next;
    delete head;
    head = cur;
  }
  delete cur;
}

void List4::Insert(itemType item, int pos){
  
}
