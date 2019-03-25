/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: proj9.h
Header file for a doubly linked list with dummy nodes at head and
tail to make insertion and deletion easier
To Build: g++ proj9Tst.cpp proj9.cpp
To Execute: ./a.out
*/



#ifndef LIST4_H
#define LIST4_H

typedef int itemType;

struct doubleNode
{
 doubleNode* prev;
 itemType item;
 doubleNode* next;
};

class List4
{
 public:
   List4();
   ~List4();

   /*
   pre: List exists, pos is in the range [1..length+1].
   post: new node is inserted at postion pos.
   */
   void Insert(itemType item, int pos);

   /*
   pre: List exists, pos is in the range [1..length].
   post: node postion pos is deleted.
   */
   void Delete(int pos);

   /*
   pre: List exists
   post: returns the addres of the item is item is in the list
         returns NULL if the item is not in the list
   */
   doubleNode* Find(itemType item);

   /*
   pre: List exists
   post: deletes every instance of item in the list
         returns the number of deletions
   */
   int DeleteItem(itemType item);

   /*
   pre: List exists.
   post: The item value of each node, from head to tail,
         is displayed on the screen, excluding the dummy nodes.
   */
   void PrintForward();

   /*
   pre: List exists.
   post: The item value of each node, from tail to head,
         is displayed on the screen, excluding dummy nodes.
   */
   void PrintBackwards();


   #Bonus +10
   /*
   pre: List exists.
   post: Nodes in the list are sorted in ascending order using
         selection sort
   */
   void Sort();

 private:
   /*
   pre: List exists, pos is in the range [1..length+1].
   Post: Returns the address of the node in position pos
         This one is tricky because of the dummy nodes.
	 If pos = 1, return the address of the head dummy node
	 if poss length+1, return the address of the node before
	 the tail dummy node
   */
   doubleNode* FindPosition(int pos);
   int length;         //length of the list
   doubleNode* head;   //points to the first dummy node
   doubleNode* tail;   //points to the last dummy node
};
#endif
