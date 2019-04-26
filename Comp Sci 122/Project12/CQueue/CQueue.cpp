/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: CQueue.cpp
Function file for circular queue implementation with an array
To Build: g++ CQueue.cpp CQueueTst.cpp
To Execute: ./a.out
*/

#include <iostream>
#include "CQueue.h"
using namespace std;

CQueue::CQueue(int size)
{
  max_size = size;
  q = new itemType[size];
  front = 0;
  rear = size-1;
}

CQueue::~CQueue()
{
  delete q;
}

bool CQueue::IsEmpty()
{
  if(q[front] == 0)
    return true;
  return false;
}

bool CQueue::IsFull()
{
  if(q[rear] != 0)
    return true;
  return false;
}

itemType CQueue::Peek()
{
  return q[front];
}

void CQueue::Enqueue(itemType item)
{
  if(!IsFull())
  {
    if(IsEmpty())
    {
      q[front] = item;
      return;
    }

    rear = (rear+1) % max_size;
    q[rear] = item;
  }

  else
  {
    cout<<"Full"<<endl;
    return 0;
  }
}

void CQueue::Dequeue()
{
  if(!IsFull())
  {
    item
  }

  else
  {
    cout<<"Empty"<<endl;
    return;
  }
}
