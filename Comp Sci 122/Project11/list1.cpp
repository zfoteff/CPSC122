#include <iostream>
using namespace std;

#include "list1.h"

List::List()
{
 head = NULL;
 length = 0;
}

List::~List()
{
 while (!IsEmpty())
 {
  DeleteItemH();
 }
}

bool List::IsEmpty() const
{
 if (length == 0)
  return true;
 return false;
}


int List::GetLength() const
{
 return length;
}

void List::PutItemH(const itemType newItem)
{
 node* tmp = new node;
 tmp->item = newItem;
 tmp->next = head;
 head = tmp;
 length++;
 tmp = NULL;
}

itemType List::GetItemH() const
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* tmp = head->next;
 delete head;
 head = tmp;
 length--;
}
	
void List::Print() const
{
 node* tmp = head;
 while(tmp != NULL)
 {
  cout << tmp->item << endl;
  tmp = tmp->next;
 }
}

