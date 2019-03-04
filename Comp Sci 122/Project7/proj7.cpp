/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj6.cpp
Program defines a Class List2 which is an example of a singly linked List2
File defines public functions to be used in proj6Tst.cpp
To Build: g++ proj6.cpp proj6Tst.cpp
To Execute: ./a.out
*/

#include "proj7.h"
#include <iostream>
using namespace std;

List2::List2(){
  length = 0;
  head = NULL;
}

List2::List2(List2* lst){
  length = lst->GetLength();
  //head = lst->GetItemH(); // ??
}

List2::~List2(){

}

bool List2::IsEmpty() const{
  if(head == NULL){
    return true;
  }
  return false;
}

int List2::GetLength() const{
  return length;
}

void List2::PutItemT( itemType newItem){
  //assigning variables to dummy node
  node* cur = new node;
  cur->item = newItem;
  cur->next = NULL;

  //sets tail node's next pointer to cur = to cur node
  tail->next = cur;
  length++;
  cur = NULL;
}

itemType List2::GetItemH() const{
  return head->item; // returns item stored in head node
}

itemType List2::GetItemT(){
  return tail->item;
}

void List2::DeleteItemH(){
  node* cur = new node;
  cur = head->next; // cur = node pointed to by next
  delete head; // head becomes null

  head = cur; // head is set to cur, all pointers start at cur
  cur = NULL;
  length--;
}

void List2::Print(){
  node* cur = new node;
  cur = head;
  while(cur != NULL){
    cout<<cur->item<<endl; // output item stored in cur node
    cur = cur->next; //sets cur equal to the node it points to/ next node
  }
}

bool List2::Find(itemType item, int& pos){}
