/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: PQueue.cpp
Function file for priority queue implementation with an array
To Build: g++ PQueue.cpp PQueueTst.cpp
To Execute: ./a.out
*/

#include "PQueue.h"
#include "queue2.h"
#include "list2.h"
#include <iostream>
using namespace std;

PQueue::PQueue() : Queue2()
{}

void PQueue::EnqueuePty(itemType item)
{
  node* cur = new node;
  cur->item = item;
  node* last = FindPos(item);

  if(last == head) //node should be placed in head
  {
    head = last;
    tail = last;
    return;
  }

  //node reassignment
  last->next = cur;
  cur->next = last->next->next;
}

node* PQueue::FindPos(itemType item)
{
  if(IsEmpty())
    return head;

  node* cur = head;
  for(int i = 0; cur->next != NULL; i++)
  {
    if(cur->item <= item) //orders them from least to greatest
      return cur;

    cur = cur->next;
  }
  return tail;
}
