/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj6.cpp
Program defines a Class named MyString.
Defines public functions to be used in proj6Tst.cpp
To Build: g++ proj6.cpp proj6Tst.cpp
To Execute: ./a.out
*/

#include "proj6.h"
#include <iostream>
using namespace std;

List::List(){
  length = 0;
  head = NULL;
}

List::~List(){

}

bool List::IsEmpty() const{
  if(head == NULL){
    return true;
  }
  return false;
}

int List::GetLength() const{
  return length;
}

void List::PutItemH(const itemType newItem){
  //assigning variables to dummy node
  node* cur = new node;
  cur->item = newItem;
  cur->next = head;

  head = cur; //sets head node = to cur node. Cur points to previous head
  length++;
  cur = NULL;
}

itemType List::GetItemH() const{
  return head->item; // returns item stored in head node
}

void List::DeleteItemH(){
  node* cur = new node;
  cur = head->next; // cur = node pointed to by next
  delete head; // head becomes null
  head = cur; // head is set to cur, all pointers start at cur
  cur = NULL;
  length--;
}

void List::Print() const{
  node* cur = new node;
  cur = head;
  while(cur != NULL){
    cout<<cur->item<<endl; // output item stored in cur node
    cur = cur->next; //sets cur equal to the node it points to/ next node
  }
}
