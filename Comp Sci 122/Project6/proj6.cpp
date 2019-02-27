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
/*
int List::GetLength() const{

}
*/
<<<<<<< HEAD
void List::PutItemH(const itemType newItem){
=======
void List::PutItemH(const itemtype newItem){
>>>>>>> 8325fcadd949b9ac217f8260b9ca3602d4a62df4
  //assigning variables to dummy node
  node* cur = new node;
  cur->item = newItem;
  cur->next = head;

  head = cur; //sets head node = to cur node. Cur points to previous head
  length++;
  cur = NULL;
}
/*
void List::GetItemH() const{

}

void List::DeleteItemH(){

}

void List::Print() const{

}
*/
