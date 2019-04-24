/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: CQueue.cpp
Header file for circular queue implementation with an array
To Build: g++ CQueue.cpp CQueueTst.cpp
To Execute: ./a.out
*/

#ifdef CQUEUE_H
#define CQUEUE_H
typedef int itemType;

class CQueue
{
  public:

  	CQueue(int size); // constructor
  	~CQueue(); // destructor

  	/*
  	pre: instance of CQueue exists
  	post: true is returned if q is empty
  	*/
  	bool IsEmpty();

	/*
 	pre: instance of CQueue exists
 	post: returns true if q is fully populated
 	*/
  	bool IsFull();

  	/*
  	pre: instance of CQueue exists and stores at least one item
  	post: item at the head of the queue is returned
  	*/
  	itemType Peek();

  	/*
  	pre:
  	post:
  	*/
  	void Enqueue(itemType item);

    	/*
    	pre:
    	post:
  	*/
	void Dequeue();

  private:
  	itemType* q; // queue implemented as an array
  	int front; // index of next item to be dequeued
  	int rear; // index of last queued item
};
#endif
