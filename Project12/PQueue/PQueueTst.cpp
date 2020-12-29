/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: PQueueTst.cpp
Test file for priority queue implementation with an array
To Build: g++ PQueue.cpp PQueueTst.cpp
To Execute: ./a.out
*/

#include "PQueue.h"
#include "queue2.h"
#include "list2.h"
#include <iostream>
using namespace std;

int main()
{
  PQueue* myQueue = new PQueue;
  myQueue->EnqueuePty(10);
  myQueue->EnqueuePty(5);
  cout<<endl;
  myQueue->Print();

  return 0;
}
