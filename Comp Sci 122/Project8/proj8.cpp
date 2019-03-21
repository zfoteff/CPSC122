/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj8.cpp
Function file for a linked list with:
1) The capacity to copy a list with the copy constructor
2) The capacity to manipulate a node in any position
To Build: g++ proj8Tst.cpp proj.cpp
To Execute: ./a.out
*/

#include <iostream>
#include "proj8.h"
using namespace std;

List3::List3(){
  length = 0;
  head = NULL;
}

List3::List3(List3* lst){
  node* lstCur = new node; // list object that is being copied into declared list
  lstCur->item = lst->head->item;
  lstCur->next = lst->head->next;

  for(int i = 0; lstCur != NULL; i++){
    PutItem(i, lstCur->item);
    lstCur = lstCur->next;
  }
}

bool List3::IsEmpty() const{
  if(head == NULL){
    return true;
  }
  return false;
}

int List3::GetLength() const{
  return length;
}

void List3::PutItem(int pos, itemType item){
  node* cur = head;
  node* newNext = new node; // pointer to the node that is being shifted
  node* insert = new node; // pointer to new node to be added to the list
  insert->item = item;

  if(pos == 0){ //if it is put at the head
    head = insert;
    length++;
    return;
  }

  int loc = 0;
  while(loc < pos){
    cur = cur->next;
    loc++;

  }

cout<< "test"<<endl;

  if(cur->next->item = 0){ // if the inserted node should be put in the tail position

      cout<<"Tst"<<endl;
    cur->next = insert;
    insert->next = NULL;
    length++;

    cout<<"End"<<endl;
    return;
  }

  cout<<"Test"<<endl;

  newNext = cur->next;
  cur->next = insert;
  insert->next = newNext;
  length++;
}

itemType List3::GetItem(int pos){
  node* cur = head;
  int loc = 0;
  while(loc != pos){
    cur = cur->next;
  }

  return cur->item;
}

void List3::DeleteItem(int pos){
  node* cur = head;
  int loc = 0;
  while(loc != pos){
    cur = cur->next;
  }

}

void List3::Print(){
  node* cur = new node;
  cur = head;
  while(cur != NULL){
    cout<<cur->item<<endl; // output item stored in cur node
    cur = cur->next; //sets cur equal to the node it points to/ next node
  }
}

node* List3::ptrTo(int pos){
  node* cur = head;
  int loc = 0;
  while(loc != pos){
    cur = cur->next;
    loc++;
  }

  return cur;
}
