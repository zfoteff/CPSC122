/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj7.cpp
Program defines a Class List2 which is an example of a singly linked List2
File defines public functions to be used in proj7Tst.cpp
To Build: g++ proj7.cpp proj7Tst.cpp
To Execute: ./a.out
*/

#include "proj7.h"
#include <iostream>
using namespace std;

List2::List2(){
  length = 0;
  head = NULL;
  tail = NULL;
}

List2::List2(List2* lst){
  node* lstCur = new node; // list object that is being copied into declared list
  lstCur->item = lst->head->item;
  lstCur->next = lst->head->next;

  while(lstCur != NULL){
    PutItemT(lstCur->item);
    lstCur = lstCur->next;
  }
}

List2::~List2(){
  node* cur = head;
  while (cur->next > 0){
    cur = cur->next;
    delete head;
    head = cur;
  }
  delete cur;
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

void List2::PutItemT(itemType newItem){
  //assigning variables to dummy node
  node* cur = new node;
  node* oldT = tail;
  cur->item = newItem;
  cur->next = NULL;

  if(length == 0){
    head = cur;
    tail = cur;
    length++;
    return;
  }

  oldT->next = cur;
  tail = cur;
  length++;
}

itemType List2::GetItemH() const{
  return head->item; // returns item stored in head node
}

itemType List2::GetItemT(){
  return tail->item;
}

void List2::DeleteItemH(){
  node* cur = head->next;
  delete head;
  head = cur;
  length--;
}

void List2::DeleteItemT(){
  node* cur = head;
  while(cur->next != tail){
    cur = cur->next;
  }

  delete tail;
  cur->next = NULL;
  tail = cur;
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

bool List2::Find(itemType item, int& pos){
  node* cur = head;
  int x = 0;
  while(cur != NULL){
    if(cur->item == item){
      pos = x;
      return true;
    }
    cur = cur->next;
    x++;
  }
  pos = -1;
  return false;
}
