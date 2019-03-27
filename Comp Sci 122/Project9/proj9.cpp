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

  if(length == 0){
    head = ins;
    tail = ins;
    ins->next = NULL;
    ins->prev = NULL;
    length++;
    return;
  }

  if(pos == 1){
    old = head;
    old->prev = ins;
    head = ins;
    length++;
  }

  if(pos == length+1){
    old = tail;
    old->next = ins;
    tail = ins;
    length++;
  }

  old = FindPos(pos-1);
  old->next = ins;
  ins->prev = old;
  ins->next = old->next->next;
  length++;

}

void List4::Delete(int pos){
  doubleNode* cur = FindPosition(pos);
  doubleNode* last = cur->prev;
  doubleNode* next = cur->next;
  next->prev = last;
  last->next = next;

  delete cur;
  delete last;
  delete next;
  length--;
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
