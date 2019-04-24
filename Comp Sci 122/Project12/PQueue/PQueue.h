/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: PQueue.cpp
Function file for priority queue that inherits from queue
To Build: g++ PQueue.cpp PQueueTst.cpp
To Execute: ./a.out
*/

#ifndef PQUEUE_H
#define PQUEUE_H
#include "list2.h"
#include "queue2.h"

typedef int itemType;

class PQueue : public Queue2
{
  public:
    PQueue(); // constructor

    /*
    pre:  instance of queue exists
    post: item is enqueued in decreasing numarical order
    */
    void EnqueuePty(itemType item);

  private:
    /*
    pre:  instance of queue exists
    post: in queue are sorted in decreasing numarial order
    */
    void SelSort();
};

#endif
