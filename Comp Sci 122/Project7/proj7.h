/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj7.cpp
Header file for a linked list with:
1) The capacity to manipulate the tail
2) The limited capacity to manipulate the head
3) The capacity to make a copy of a list with a the copy constructor
4) The capacity to search a list
To Build: g++ projTst7.cpp proj7.cpp
To Execute: ./a.out
*/


#ifndef LIST2_H
#define LIST2_H

typedef int itemType;

struct node
{
 itemType item;
 node* next;
};

class List2
{
 public:
   List2();

   /*
   pre: an instance of what lst points to exists
   post: the list created with the constructor contains the contents of
         what lst points to
   */
   List2(List2* lst);

   /*
   pre: an instance of List2 exists
   post: memory for all nodes in List have been returned to the heap
   */
   ~List2();

   /*
   pre: an instance of list2 exists
   post: returns true if list is empty, false otherwise
   */
   bool IsEmpty() const;

   /*
   pre: an instance of List exists
   post: returns length of the list
   */
   int GetLength() const;

   /*
   pre: an instance of List2 exists and is not empty
   post: Returns the contents of the head of the list.
   */
   itemType GetItemH() const;

   /*
   pre: an instance of List2 exists and is not empty
   post: head of the list is deleted, memory is returned to the heap
   */
   void DeleteItemH();

   /*
   pre: an instance of the list exists
   post: newItem is at the tail of the list
   */
   void PutItemT(itemType newItem);

   /*
   pre: an instance of the list exists and is not empty
   post: Returns the contents of the tail of the list.
   */
   itemType GetItemT();

   /*
   pre: an instance of the list exists and is not empty
   post: tail of the list is deleted and memory is returned to the heap
   */
   void DeleteItemT();

   /*
   pre: an instance of the list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines
   */
   void Print();

   /*
   pre: an instance of the list exists and is not empty
   post: If item is in the list
         returns true and pos holds the position in the list, counting from 0
         if item is not in the list, returns false and pos holds -1
   */
   bool Find(itemType item, int& pos);


 private:
   int length; //length of the list
   node* head; //points to the first node on the list
   node* tail; //points to the last node on the list
};
#endif
