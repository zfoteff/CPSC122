/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj8.cpp
Header file for a linked list with:
1) The capacity to copy a list with the copy constructor
2) The capacity to manipulate a node in any position
To Build: g++ proj8Tst.cpp proj.cpp
To Execute: ./a.out
*/


#ifndef LIST3_H
#define LIST3_H

typedef int itemType;

struct node
{
 itemType item;
 node* next;
};

class List3
{
 public:
   List3();

   /*
   pre: an instance of what lst points to exists
   post: the list created with the constructor contains the contents of
         what lst points to
   */
   List3(List3* lst);

   /*
   pre: an instance of List exists
   post: memory for all nodes in List have been returned to the heap
   */
   ~List3();

   /*
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */
   bool IsEmpty() const;

   /*
   pre: an instance of list exists
   post: returns length of the list
   */
   int GetLength() const;

   /*
   pre: an instance of list exists,pos >= 0
   post: item is at posiiton pos of the list
   */
   void PutItem(int pos, itemType item);

   /*
   pre: an instance of list exist, is not empty, pos >= 0
   post: returns the contents of the list at positon pos
   */
   itemType GetItem(int pos);

   /*
   pre: an instance of list exists, is not empty, pos >= 0
   post: item at position, pos, is deleted, memory is returned to the heap
   */
   void DeleteItem(int pos);


   /*
   use: displays the contents of the list on the screen
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines
   */
   void Print();


 private:
   /*
   pre: an instance of list exists, pos >= 0
   post: Returns the address of the node in position pos
   */
   node* ptrTo(int pos);

   int length; //length of the list
   node* head; //points to the first node on the list
};
#endif
