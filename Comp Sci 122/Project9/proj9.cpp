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
  doubleNode* ins = new doubleNode;
  doubleNode* old = new doubleNode;
  ins->item = item;

  if(length == 0){ // List empty
    head = ins;
    tail = ins;
    ins->next = NULL;
    ins->prev = NULL;
    length++;
    return;
  }

  if(pos == 1){ // Insert at head
    old = head;
    old->prev = ins;
    head = ins;
    ins->prev = NULL;
    length++;
    return;
  }

  if(pos == length+1){ // Insert at head
    old = tail;
    old->next = ins;
    ins->prev = old;
    tail = ins;
    length++;
    return;
  }

  old = FindPosition(pos-1);
  old->next = ins;
  ins->prev = old;
  ins->next = old->next->next;
  length++;

}

void List4::Delete(int pos){
  doubleNode* cur = FindPosition(pos);
  doubleNode* last = cur->prev;
  doubleNode* next = cur->next;

  if(cur = head){
    head = next;
    next->prev = NULL;
    delete cur;
    length--;
    return;
  }

  if(cur = tail){
    tail = last;
    last->next = NULL;
    length--;
    delete cur;
    return;
  }

  last->next = next;
  next->prev = last;
  delete cur;
  length--;
}

int List4::DeleteItem(itemType item){
  int count = 0;
  doubleNode* cur = head;
  doubleNode* temp = new doubleNode;
  while(cur->next != NULL){
    if(cur->item = item){
      if(cur->prev == NULL){ // if item is found in the head node
        temp = cur->next;
        temp->prev = NULL;
        head = temp;
        delete cur;
        length--;
        count++;
      }

      if(cur->next == NULL){ // if item is found in the tail node
        temp = cur->prev;
        temp->next = NULL;
        tail = temp;
        delete cur;
        length--;
        count++;
      }

      else{
        temp = cur->next;
        temp->prev = cur->prev;
        delete cur;
        length--;
        count++;
      }
    }
    cur = cur->next;
  }
  return count;
}

doubleNode* List4::FindPosition(int pos){
  int truePos = pos-1;
  int count = 0;
  doubleNode* cur = head;
  while(count != truePos){
    cur = cur->next;
    count++;
  }

  return cur;
}

void List4::PrintForward(){
  doubleNode* cur = head;
  while(cur->next != NULL){
    cout<<cur->item<<endl;
    cur = cur->next;
  }
  cout<<cur->item<<endl;
}

void List4::PrintBackwards(){
  doubleNode* cur = tail;
  int x = 0;
  while(cur->prev != NULL){
    cout<<cur->item<<endl;
    cur = cur->prev;
  }
  cout<<cur->item<<endl;
}
