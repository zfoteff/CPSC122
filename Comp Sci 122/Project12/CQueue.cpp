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
  q = new itemType[size];
  front = 0;
  rear = size-1;
}

bool CQueue::IsEmpty()
{

}

bool CQueue::IsFull()
{}

itemType CQueue::Peek()
{}

void CQueue::Enqueue(itemType item)
{}

void CQueue::Dequeue()
{}
